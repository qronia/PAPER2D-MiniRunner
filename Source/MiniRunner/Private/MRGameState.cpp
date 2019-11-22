// Fill out your copyright notice in the Description page of Project Settings.


#include "MRGameState.h"

AMRGameState::AMRGameState()
{
	bIsGameRunning = false;
	RemainFoodAmount = 0;
	bIsDead = true;
}

void AMRGameState::Timer_Reset()
{
	_StartTime = std::chrono::system_clock::now();
	_PauseDuration = std::chrono::duration<double>::zero();
	bIsTimerRunning = true;
}

bool AMRGameState::Timer_MakeStopPoint()
{
	if (bIsTimerRunning == false) return false;
	bIsTimerRunning = false;
	_StopTime = std::chrono::system_clock::now();
	return true;
}

bool AMRGameState::Timer_Resume()
{
	if (bIsTimerRunning == true) return false;
	bIsTimerRunning = true;
	_PauseDuration += std::chrono::system_clock::now() - _StopTime;
	return true;
}

std::chrono::duration<double> AMRGameState::GetTimerDuration()
{
	return (_StopTime - _StartTime) - _PauseDuration;
}

FString AMRGameState::GetTimerDuration_ForUI()
{
	long long totalMilliSec;
	int32 min;
	int32 sec;
	int32 millisec;

	totalMilliSec = bIsTimerRunning? 
		std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - _StartTime - _PauseDuration).count()
		:std::chrono::duration_cast<std::chrono::milliseconds>(GetTimerDuration()).count();

	min = totalMilliSec / (1000 * 60);
	sec = (totalMilliSec / 1000) % 60;
	millisec = totalMilliSec % 1000;

	return FString::Printf(TEXT("%02d.%02d.%04d"), min, sec, millisec);
}
