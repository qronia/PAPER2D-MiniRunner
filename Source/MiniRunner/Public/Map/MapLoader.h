// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EngineMinimal.h"
#include "GameFramework/Actor.h"
#include "MapLoader.generated.h"

enum class ESpawnTargetDataInfo : uint8;

UCLASS()
class MINIRUNNER_API AMapLoader : public AActor
{
	GENERATED_BODY()

private:
	enum class ETileInfo : uint8
	{
		SlopeLeft = 1,
		BlockNormal = 10,
		SlopeRight = 11,
		GrassyBlock = 12,
		BrokenBlock = 13,
		Movable = 14,
		FaunaLeft = 15,
		FaunaMiddle = 16,
		FaunaRight = 17,
		Spike = 18,
		Breakable = 20,
	};
	enum class EItemInfo : uint8
	{
		Food = 2,
		RedKey = 8,
		BlueKey = 9,
		GreenKey = 10,
		MasterKey = 11,
	};

	enum class EDataType : uint8
	{
		Tile,
		Item,
		Trigger,
	};
	
public:	
	class AMiniRunnerMap* CreatedMap;



private:
	void MappingHelper(EDataType Type, TMap<int32, ESpawnTargetDataInfo>& TargetDB, int32 firstgid);
	
public:
	AMapLoader();
	bool LoadMap(FString JsonPath);
	UFUNCTION(BlueprintCallable)
	void ReloadMap(class AHeroCharacter*& out);
};
