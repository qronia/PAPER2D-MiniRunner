// Fill out your copyright notice in the Description page of Project Settings.


#include "MRInGame_Hud.h"
#include "Components\TextBlock.h"

#include "Globals.h"
#include "MRGameState.h"

void UMRInGame_Hud::NativeConstruct()
{
	Super::NativeConstruct();
	_State = GetWorld()->GetGameState<AMRGameState>();

	_txt_ElapsedTime	= Cast<UTextBlock>(GetWidgetFromName(TEXT("txt_ET")));
	_txt_FoodCount		= Cast<UTextBlock>(GetWidgetFromName(TEXT("txt_foodCount")));
	_txt_RedCount		= Cast<UTextBlock>(GetWidgetFromName(TEXT("txt_redCount")));
	_txt_BlueCount		= Cast<UTextBlock>(GetWidgetFromName(TEXT("txt_blueCount")));
	_txt_GreenCount		= Cast<UTextBlock>(GetWidgetFromName(TEXT("txt_greenCount")));
	_txt_MasterCount	= Cast<UTextBlock>(GetWidgetFromName(TEXT("txt_masterCount")));
}

void UMRInGame_Hud::NativeTick(const FGeometry& Geometry, float DeltaSeconds)
{
	Super::NativeTick(Geometry, DeltaSeconds);
	if (!IsValid(_State)) return;
	_txt_ElapsedTime->SetText(FText::FromString(_State->GetTimerDuration_ForUI()));
	_txt_FoodCount->SetText(FText::AsNumber(_State->RemainFoodAmount));
}

void UMRInGame_Hud::KeyCountUpdate(FKeyInventory& Inventory)
{
	_txt_RedCount->		SetText(FText::AsNumber(Inventory.RedKey));
	_txt_BlueCount->	SetText(FText::AsNumber(Inventory.BlueKey));
	_txt_GreenCount->	SetText(FText::AsNumber(Inventory.GreenKey));
	_txt_MasterCount->	SetText(FText::AsNumber(Inventory.MasterKey));
}
