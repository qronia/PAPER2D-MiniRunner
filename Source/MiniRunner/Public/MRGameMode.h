// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MRGameMode.generated.h"

/**
 * 
 */
UCLASS()
class MINIRUNNER_API AMRGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	UPROPERTY(Transient)
	int FullFoodAmount;

public:
	AMRGameMode();
	bool OnGetFoodEvent();
	void SetFoodAmount(int Amount);
	void ResetFoodAmount();
};
