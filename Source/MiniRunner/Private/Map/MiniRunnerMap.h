// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "MiniRunnerMap.generated.h"

enum class ESpawnTargetDataInfo : uint8;

UCLASS()
class AMiniRunnerMap : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMiniRunnerMap();


protected:
	UPROPERTY(VisibleAnywhere)
	USceneComponent* Positioner;

	UPROPERTY(EditAnywhere)
	class UPaperSprite* Block_SlopeLeft;
	UPROPERTY(EditAnywhere)
	class UPaperSprite* Block_SlopeRight;
	UPROPERTY(EditAnywhere)
	class UPaperSprite* Block_Normal;
	UPROPERTY(EditAnywhere)
	class UPaperSprite* Block_Grassed;
	UPROPERTY(EditAnywhere)
	class UPaperSprite* Block_Breaked;
	UPROPERTY(EditAnywhere)
	class UPaperSprite* Fauna_Left;
	UPROPERTY(EditAnywhere)
	class UPaperSprite* Fauna_Middle;
	UPROPERTY(EditAnywhere)
	class UPaperSprite* Fauna_Right;	
	UPROPERTY(EditAnywhere)
	class UPaperSprite* Spike;



	UPROPERTY(EditAnywhere)
	UClass* Item_Food;
	UPROPERTY(EditAnywhere)
	UClass* Item_Key;
	UPROPERTY(EditAnywhere)
	UClass* Block_Breakable;
	UPROPERTY(EditAnywhere)
	UClass* Block_Movable;
	UPROPERTY(EditAnywhere)
	UClass* Block_KeyBlock;
	UPROPERTY(EditAnywhere)
	UClass* Class_Hero;


	UPROPERTY(EditAnywhere)
	TSubclassOf<class APaperGroupedSpriteActor> Grouped_Spike;

	class UPaperGroupedSpriteComponent* Group_NormalBlock;
	class UPaperGroupedSpriteComponent* Group_SlopeLeft;
	class UPaperGroupedSpriteComponent* Group_SlopeRight;
	class UPaperGroupedSpriteComponent* Group_GrassyBlock;
	class UPaperGroupedSpriteComponent* Group_BrokenBlock;
	class UPaperGroupedSpriteComponent* Group_FaunaLeft;
	class UPaperGroupedSpriteComponent* Group_FaunaMiddle;
	class UPaperGroupedSpriteComponent* Group_FaunaRight;

	class APaperGroupedSpriteActor* SpikesHolder;

	// uint8 for enum
	TArray<TTuple<UClass*, FTransform, uint8>> DynamicActorsPositions;
	TArray<AActor*> DynamicActors;



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	void SetTile(ESpawnTargetDataInfo Target, float PosX, float PosY);
	void SetTile(FString Name, FString Type, int32 Width, int32 Height, int32 x, int32 y);

	void Reload(class AHeroCharacter*& out);
};
