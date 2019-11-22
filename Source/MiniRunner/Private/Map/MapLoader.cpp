// Fill out your copyright notice in the Description page of Project Settings.


#include "MapLoader.h"
#include "Json/Public/Json.h"
#include "Paper2D\Classes\PaperSprite.h"
#include "Paper2D\Classes\PaperGroupedSpriteActor.h"
#include "Paper2D\Classes\PaperGroupedSpriteComponent.h"
#include "FileManager.h"
#include "Kismet\GameplayStatics.h"

#include "Globals.h"
#include "HeroCharacter.h"
#include "MiniRunnerMap.h"
#include "MRGameInstance.h"
#include "MRGameMode.h"

// Sets default values
AMapLoader::AMapLoader()
{
	PrimaryActorTick.bCanEverTick = false;
}

bool AMapLoader::LoadMap(FString MapPath)
{
	AMRGameMode* Mode;
	TMap<int32, ESpawnTargetDataInfo> TileLinkDB;
	int32 TileHeight, TileWidth;
	int32 MapHeight, MapWidth;
	bool bIsPlayerExist = false;
	int32 FoodCount = 0;

	FString JsonStrings;
	if (!FFileHelper::LoadFileToString(JsonStrings, *MapPath))
	{
		UE_LOG(LogTemp, Error, TEXT("From AMapLoader - Cannot Load Target File."));
		return false;
	}

	TSharedPtr<FJsonObject> MainObject;
	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(JsonStrings);

	/**************************************************************/
	//					Json Object의 해석 준비 및 ETC
	/**************************************************************/
	UE_LOG(LogTemp, Error, TEXT("==== Json Object Parsing Start ===="));
	if (!FJsonSerializer::Deserialize<>(Reader, MainObject) || !MainObject.IsValid())
	{
		UE_LOG(LogTemp, Error, TEXT("From AMapLoader - Target is probably NOT JSON."));
		return false;
	}

	TileHeight = MainObject->GetIntegerField(TEXT("tileheight")); // Should be 32
	TileWidth = MainObject->GetIntegerField(TEXT("tilewidth")); // Should be 32

	if (IsValid(CreatedMap)) CreatedMap->Destroy();
	CreatedMap = GetWorld()->SpawnActor<AMiniRunnerMap>();
	TileLinkDB.Add(0, ESpawnTargetDataInfo::None); 
	Mode = Cast<AMRGameMode>(GetWorld()->GetAuthGameMode());
	if (Mode == nullptr) return false;

	/**************************************************************/
	//						TileSet 정보
	/**************************************************************/
	UE_LOG(LogTemp, Error, TEXT("Tileset Data Parsing..."));
	const TArray<TSharedPtr<FJsonValue>> TilesetData = MainObject->GetArrayField("tilesets");
	for (TSharedPtr<FJsonValue> ptr : TilesetData)
	{
		int32 firstgid;
		FString source;
		auto tileset = ptr->AsObject();
		// if (!tileset.IsValid()) continue;

		// 데이터 해석
		source = tileset->GetStringField(TEXT("source"));
		if (source.FindLastChar(TCHAR('/'), firstgid)) // 이 시점의 firstgid는 임시값, 또한 경로가 하위 디렉토리를 포함하는 경우를 찾아낸다.
		{
			source = source.RightChop(firstgid+1);
		}
		firstgid = tileset->GetIntegerField(TEXT("firstgid"));

		// Mapping
		UE_LOG(LogTemp, Error, TEXT("source Str - %s"), *source);
		if (source.Equals(TEXT("MRTileset.tsx"), ESearchCase::IgnoreCase))
		{
			UE_LOG(LogTemp, Error, TEXT("Tileset - MRTileset Detected"));
			MappingHelper(EDataType::Tile, TileLinkDB, firstgid);
		}
		else if (source.Equals(TEXT("MRItems.tsx"), ESearchCase::IgnoreCase))
		{
			UE_LOG(LogTemp, Error, TEXT("Tileset - MRItems Detected"));
			MappingHelper(EDataType::Item, TileLinkDB, firstgid);
		}
	}

	/**************************************************************/
	//						layer 해석
	/**************************************************************/
	UE_LOG(LogTemp, Error, TEXT("Layer Data Parsing..."));
	const TArray<TSharedPtr<FJsonValue>> MapLayers = MainObject->GetArrayField("layers");
	for (TSharedPtr<FJsonValue> ptr : MapLayers) // 하나로 충분히 만들수 있지만 저작자에 따라서는 하나가 아닐수도 있으니 주의할 것.
	{
		auto layer = ptr->AsObject();
		FString Type = layer->GetStringField(TEXT("type"));
		// Case - tilelayer (타일 레이어)
		if (Type.Equals(TEXT("tilelayer")))
		{
			UE_LOG(LogTemp, Warning, TEXT("Layer - tileLayer Detected"));
			MapHeight = layer->GetIntegerField(TEXT("height"));
			MapWidth = layer->GetIntegerField(TEXT("width"));
			UE_LOG(LogTemp, Warning, TEXT("map Height, map Width = %d, %d"), MapHeight, MapWidth);

			// 이 부분은 CSV 스타일로 저장되어있을 데이터들을 해석한다. 
			int32 TileNumber, PosX, PosY;
			PosX = PosY = 0;
			TArray<TSharedPtr<FJsonValue>> data = layer->GetArrayField(TEXT("data"));

			ESpawnTargetDataInfo* Target;
			UE_LOG(LogTemp, Warning, TEXT("Layer - Start tile Data Process..."));
			UE_LOG(LogTemp, Warning, TEXT("Layer - data amount : %d"), data.Num());
			for (const auto& tile : data)
			{
				TileNumber = (int32)tile->AsNumber();
				Target = TileLinkDB.Find(TileNumber);

				if (Target != nullptr) CreatedMap->SetTile(*Target, (float)(TileWidth * PosX), (float)(TileHeight * PosY));
				if (*Target == ESpawnTargetDataInfo::Food) ++FoodCount;

				if (++PosX >= MapWidth)
				{
					PosX = 0;
					++PosY;
				}
			}
		}
		// Case - objectgroup (오브젝트 레이어)
		else if (Type.Equals(TEXT("objectgroup")))
		{
			// 위의 Type은 임시변수로서 사용되었으므로 아래에서도 재활용 될 수 있다.
			UE_LOG(LogTemp, Warning, TEXT("Layer - ObjectLayer Detected"));
			TArray<TSharedPtr<FJsonValue>> objectArray = layer->GetArrayField(TEXT("objects"));
			FString objName;
			int x, y, width, height;

			UE_LOG(LogTemp, Error, TEXT("Type, Name, x, y, width, height"));
			for (const TSharedPtr<FJsonValue> &objElement : objectArray)
			{
				auto obj =	objElement->AsObject();
				Type =		obj->GetStringField(TEXT("type"));
				objName =	obj->GetStringField(TEXT("name"));
				x =			obj->GetIntegerField(TEXT("x"));
				y =			obj->GetIntegerField(TEXT("y"));
				width =		obj->GetIntegerField(TEXT("width"));
				height =	obj->GetIntegerField(TEXT("height"));

				UE_LOG(LogTemp, Error, TEXT("%s, %s, %d, %d, %d, %d"), *Type, *objName, x, y, width, height);
				if (Type.Equals(TEXT("player")))
				{
					// 플레이어의 경우 분기하여 플레이어에 대한 위치지정이 중복되었다면 이 맵은 잘못된 맵이기 때문에 실패를 알린다.
					if(bIsPlayerExist) return false;
					else bIsPlayerExist = true;
				}

				CreatedMap->SetTile(objName, Type, width, height, x, y);
			}
		}
	}

	Mode->SetFoodAmount(FoodCount);
	return true;
}

void AMapLoader::ReloadMap(AHeroCharacter*& out)
{
	if (CreatedMap == nullptr || !IsValid(CreatedMap))
	{
		out = nullptr;
		return;
	}
	CreatedMap->Reload(out);
}

void AMapLoader::MappingHelper(EDataType Type, TMap<int32, ESpawnTargetDataInfo>& TargetMapper, int32 firstgid)
{
	switch (Type)
	{
	case EDataType::Tile:
		TargetMapper.Add(firstgid + (int32)ETileInfo::SlopeLeft,	ESpawnTargetDataInfo::SlopeLeft);
		TargetMapper.Add(firstgid + (int32)ETileInfo::SlopeRight,	ESpawnTargetDataInfo::SlopeRight);
		TargetMapper.Add(firstgid + (int32)ETileInfo::BlockNormal,	ESpawnTargetDataInfo::BlockNormal);
		TargetMapper.Add(firstgid + (int32)ETileInfo::GrassyBlock,	ESpawnTargetDataInfo::GrassyBlock);
		TargetMapper.Add(firstgid + (int32)ETileInfo::BrokenBlock,	ESpawnTargetDataInfo::BrokenBlock);
		TargetMapper.Add(firstgid + (int32)ETileInfo::Movable,		ESpawnTargetDataInfo::Movable);
		TargetMapper.Add(firstgid + (int32)ETileInfo::FaunaLeft,	ESpawnTargetDataInfo::FaunaLeft);
		TargetMapper.Add(firstgid + (int32)ETileInfo::FaunaMiddle,	ESpawnTargetDataInfo::FaunaMiddle);
		TargetMapper.Add(firstgid + (int32)ETileInfo::FaunaRight,	ESpawnTargetDataInfo::FaunaRight);
		TargetMapper.Add(firstgid + (int32)ETileInfo::Spike,		ESpawnTargetDataInfo::Spike);
		TargetMapper.Add(firstgid + (int32)ETileInfo::Breakable,	ESpawnTargetDataInfo::Breakable);
		break;

	case EDataType::Item:
		TargetMapper.Add(firstgid + (int32)EItemInfo::Food,			ESpawnTargetDataInfo::Food);
		TargetMapper.Add(firstgid + (int32)EItemInfo::RedKey,		ESpawnTargetDataInfo::RedKey);
		TargetMapper.Add(firstgid + (int32)EItemInfo::BlueKey,		ESpawnTargetDataInfo::BlueKey);
		TargetMapper.Add(firstgid + (int32)EItemInfo::GreenKey,		ESpawnTargetDataInfo::GreenKey);
		TargetMapper.Add(firstgid + (int32)EItemInfo::MasterKey,	ESpawnTargetDataInfo::MasterKey);
		break;

	default: return;
	}

}
