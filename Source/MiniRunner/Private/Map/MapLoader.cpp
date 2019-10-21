// Fill out your copyright notice in the Description page of Project Settings.


#include "MapLoader.h"
#include "Json/Public/Json.h"
#include "Paper2D\Classes\PaperSprite.h"
#include "Paper2D\Classes\PaperGroupedSpriteActor.h"
#include "Paper2D\Classes\PaperGroupedSpriteComponent.h"
#include "FileManager.h"

#include "Globals.h"
#include "MiniRunnerMap.h"

// Sets default values
AMapLoader::AMapLoader()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void AMapLoader::BeginPlay()
{
	Super::BeginPlay();
	FString Path = FPaths::ProjectDir() + TEXT("Maps/test.json");

	//UE_LOG(LogTemp, Error, TEXT("%s"), *Path);

	LoadMap(Path);
	CreatedMap->Reload();
}

bool AMapLoader::LoadMap(FString MapPath)
{
	TMap<int32, ESpawnTargetDataInfo> TileLinkDB;
	int32 TileHeight, TileWidth;
	int32 MapHeight, MapWidth;

	FString JsonStrings;
	if (!FFileHelper::LoadFileToString(JsonStrings, *MapPath)) return false;

	TSharedPtr<FJsonObject> MainObject;
	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(JsonStrings);

	/**************************************************************/
	//					Json Object�� �ؼ� �غ� �� ETC
	/**************************************************************/
	UE_LOG(LogTemp, Error, TEXT("==== Json Object Parsing Start ===="));
	if (!FJsonSerializer::Deserialize<>(Reader, MainObject) || !MainObject.IsValid()) return false;

	TileHeight = MainObject->GetIntegerField(TEXT("tileheight")); // Should be 32
	TileWidth = MainObject->GetIntegerField(TEXT("tilewidth")); // Should be 32

	UE_LOG(LogTemp, Error, TEXT("tile Height, tile Width = %d, %d"), TileHeight, TileWidth);

	if (IsValid(CreatedMap)) CreatedMap->Destroy();
	CreatedMap = GetWorld()->SpawnActor<AMiniRunnerMap>();
	TileLinkDB.Add(0, ESpawnTargetDataInfo::None);

	/**************************************************************/
	//						TileSet ����
	/**************************************************************/
	UE_LOG(LogTemp, Error, TEXT("Tileset Data Parsing..."));
	const TArray<TSharedPtr<FJsonValue>> TilesetData = MainObject->GetArrayField("tilesets");
	for (TSharedPtr<FJsonValue> ptr : TilesetData)
	{
		int32 firstgid;
		FString source;
		auto tileset = ptr->AsObject();
		// if (!tileset.IsValid()) continue;

		// ������ �ؼ�
		source = tileset->GetStringField(TEXT("source"));
		if (source.FindLastChar(TCHAR('/'), firstgid)) // �� ������ firstgid�� �ӽð�, ���� ��ΰ� ���� ���丮�� �����ϴ� ��츦 ã�Ƴ���.
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
	//						layer �ؼ�
	/**************************************************************/
	UE_LOG(LogTemp, Error, TEXT("Layer Data Parsing..."));
	const TArray<TSharedPtr<FJsonValue>> MapLayers = MainObject->GetArrayField("layers");
	for (TSharedPtr<FJsonValue> ptr : MapLayers) // �ϳ��� ����� ����� ������ �����ڿ� ���󼭴� �ϳ��� �ƴҼ��� ������ ������ ��.
	{
		auto layer = ptr->AsObject();
		FString Type = layer->GetStringField(TEXT("type"));
		// Case - tilelayer (Ÿ�� ���̾�)
		if (Type.Equals(TEXT("tilelayer")))
		{
			UE_LOG(LogTemp, Warning, TEXT("Layer - tileLayer Detected"));
			MapHeight = layer->GetIntegerField(TEXT("height"));
			MapWidth = layer->GetIntegerField(TEXT("width"));
			UE_LOG(LogTemp, Warning, TEXT("map Height, map Width = %d, %d"), MapHeight, MapWidth);

			// �� �κ��� ���� �ӽ÷μ� �Ǿ��ִ� CSV ��Ÿ���� �ؼ��Ѵ�. 
			// �̰��� ������ �Ǿ����� ���� ���·μ�, �˰��� �׽�Ʈ�� ���� �ӽ÷� ����ϱ�� �ߴ�.
			int32 TileNumber, PosX, PosY;
			PosX = PosY = 0;
			TArray<TSharedPtr<FJsonValue>> data = layer->GetArrayField(TEXT("data"));
			/*
				���� base64 ��Ÿ�Ϸ� ���ڵ� �Ǿ��ִ� ���� ���ڵ��ϴ� �۾��� �����Ѵ�.
				����� CSV ��Ÿ���̹Ƿ�.. �Ʒ��� �̿��Ѵ�.
			*/
			ESpawnTargetDataInfo* Target;
			UE_LOG(LogTemp, Warning, TEXT("Layer - Start tile Data Process..."));
			UE_LOG(LogTemp, Warning, TEXT("Layer - data amount : %d"), data.Num());
			for (const auto& tile : data)
			{
				TileNumber = (int32)tile->AsNumber();
				Target = TileLinkDB.Find(TileNumber);

				if(Target != nullptr) CreatedMap->SetTile(*Target, (float)(TileWidth * PosX), (float)(TileHeight * PosY));

				if (++PosX >= MapWidth)
				{
					PosX = 0;
					++PosY;
				}
			}
		}
		// Case - objectgroup (������Ʈ ���̾�)
		else if (Type.Equals(TEXT("objectgroup")))
		{
			// ���� Type�� �ӽú����μ� ���Ǿ����Ƿ� �Ʒ������� ��Ȱ�� �� �� �ִ�.
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

				CreatedMap->SetTile(objName, Type, width, height, x, y);
			}
		}
	}
	return true;
}

void AMapLoader::ReloadMap()
{
	if (!IsValid(CreatedMap)) return;
	CreatedMap->Reload();
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
