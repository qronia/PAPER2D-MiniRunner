// Fill out your copyright notice in the Description page of Project Settings.


#include "MRGameMode.h"
#include "MRGameState.h"

AMRGameMode::AMRGameMode()
{
	DefaultPawnClass = nullptr;
	GameStateClass = AMRGameState::StaticClass();
}

bool AMRGameMode::OnGetFoodEvent()
{
	AMRGameState* MRGameState = Cast<AMRGameState>(GameState);

	if (--(MRGameState->RemainFoodAmount) > 0) return false;

	// TODO: ���⿡ ������ �������� ����. ������� ���� ���� �� UI ���� ���� �ؾ��Ѵ�.

	return true;
}

void AMRGameMode::SetFoodAmount(int Amount)
{
	AMRGameState* MRGameState = Cast<AMRGameState>(GameState);	
	if (Amount <= 0) return;
		
	FullFoodAmount = Amount;
	MRGameState->RemainFoodAmount = Amount;
}

void AMRGameMode::ResetFoodAmount()
{
	AMRGameState* MRGameState = Cast<AMRGameState>(GameState);
	MRGameState->RemainFoodAmount = FullFoodAmount;
}