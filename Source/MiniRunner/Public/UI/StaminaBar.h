// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "StaminaBar.generated.h"

/**
 * 
 */
UCLASS(Meta=(DisableNativeTick))
class MINIRUNNER_API UStaminaBar : public UUserWidget
{
	GENERATED_BODY()
	
private:
	UPROPERTY()
	class UProgressBar* _StaminaBar;

public:
	UStaminaBar(const FObjectInitializer& Initializer);
	virtual void NativeConstruct() override;
	void ChangePercentage(float Percentage);
};
