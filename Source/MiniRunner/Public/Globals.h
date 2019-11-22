// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Globals.generated.h"

UENUM(BlueprintType)
enum class ESpawnTargetDataInfo : uint8
{
	None,

	// Tile
	SlopeLeft,
	SlopeRight,
	BlockNormal,
	GrassyBlock,
	BrokenBlock,
	Movable,
	FaunaLeft,
	FaunaMiddle,
	FaunaRight,
	Spike,
	Breakable,

	// Item
	Food,
	RedKey,
	BlueKey,
	GreenKey,
	MasterKey,
};

UENUM(BlueprintType)
enum class EMRKeyType : uint8
{
	None,
	Red,
	Blue,
	Green,
	Master,
};

USTRUCT(Atomic, BlueprintType)
struct FTiledObjectData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 X;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Y;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Width;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Height;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EMRKeyType Type;
};

USTRUCT(Atomic, BlueprintType)
struct FKeyInventory
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 RedKey;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 BlueKey;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 GreenKey;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 MasterKey;

public:
	FKeyInventory() : RedKey(0), BlueKey(0), GreenKey(0), MasterKey(0) {};
};

USTRUCT(BlueprintType, Atomic)
struct FRank
{
	GENERATED_BODY()

public:
	FRank() = default;
	FRank(FString Username, int64 Time) : Name(Username), MilliSecondsTime(Time) {};

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString Name;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int64 MilliSecondsTime;
};
