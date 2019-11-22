// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "chrono"

#include "MRGameState.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class MINIRUNNER_API AMRGameState : public AGameStateBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Transient)
	int32 RemainFoodAmount;
	UPROPERTY(BlueprintReadWrite, Transient)
	bool bIsDead;
	UPROPERTY(BlueprintReadWrite, Transient)
	bool bIsGameRunning;
	UPROPERTY(BlueprintReadWrite, Transient)
	UUserWidget* TempWidgetHolder;

private:
	bool bIsTimerRunning;
	std::chrono::system_clock::time_point _StartTime;
	std::chrono::system_clock::time_point _StopTime;
	std::chrono::duration<double> _PauseDuration;

public:
	AMRGameState();
	void Timer_Reset();
	bool Timer_MakeStopPoint();
	bool Timer_Resume(); 

	std::chrono::duration<double> GetTimerDuration();

	UFUNCTION(BlueprintCallable)
	FString GetTimerDuration_ForUI();
};
