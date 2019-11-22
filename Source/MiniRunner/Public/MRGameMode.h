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

private:
	class AMapLoader* MapLoader;

public:
	AMRGameMode();
	virtual void BeginPlay() override;
	virtual void Reset() override;

	virtual bool SetPause(APlayerController* PC, FCanUnpause CanUnpauseDelegate = FCanUnpause()) override;
	virtual bool ClearPause() override;

	bool OnGetFoodEvent();
	void SetFoodAmount(int Amount);
	void ResetFoodAmount();

	UFUNCTION(BlueprintCallable)
	void RankingUpdateAndEndGame(FString Name);
};
