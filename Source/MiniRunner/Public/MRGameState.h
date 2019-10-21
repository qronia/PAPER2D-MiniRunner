// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "MRGameState.generated.h"

/**
 * 
 */
UCLASS()
class MINIRUNNER_API AMRGameState : public AGameStateBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Transient)
	int32 RemainFoodAmount;
};
