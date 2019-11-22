// Fill out your copyright notice in the Description page of Project Settings.


#include "StaminaBar.h"
#include "Components\ProgressBar.h"

UStaminaBar::UStaminaBar(const FObjectInitializer& Initializer) : UUserWidget(Initializer)
{
}

void UStaminaBar::NativeConstruct()
{
	Super::NativeConstruct();
	_StaminaBar = Cast<UProgressBar>(GetWidgetFromName(TEXT("pBar_Stamina")));
}

void UStaminaBar::ChangePercentage(float Percentage)
{
	if (_StaminaBar == nullptr) return;
	_StaminaBar->SetPercent(Percentage);
}