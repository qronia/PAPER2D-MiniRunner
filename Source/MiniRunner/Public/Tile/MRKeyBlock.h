// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MRKeyBlock.generated.h"

enum class EMRKeyType : uint8;

UCLASS()
class MINIRUNNER_API AMRKeyBlock : public AActor
{
	GENERATED_BODY()
	
protected:

	UPROPERTY(VisibleAnywhere)
	USceneComponent* Positioner;
	UPROPERTY(VisibleAnywhere)
	class UPaperSpriteComponent* Sprite_Block;
	UPROPERTY(VisibleAnywhere)
	class UPaperFlipbookComponent* Flipbook_Key;

	EMRKeyType NeedKeyType;

private:
	UFUNCTION()
	void OnComponentBeginHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector Impulse, const FHitResult& Hit);

protected:
	virtual void BeginPlay() override;


public:	
	AMRKeyBlock();
	void Init(EMRKeyType type);
};
