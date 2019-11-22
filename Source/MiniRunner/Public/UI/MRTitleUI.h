// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MRTitleUI.generated.h"

DECLARE_DYNAMIC_DELEGATE(FTitleDelegate);

UCLASS(Meta=(DisableNativeTick))
class MINIRUNNER_API UMRTitleUI : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category="Event")
	FTitleDelegate OnBtnClick_GameStart;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Event")
	FTitleDelegate OnBtnClick_Tutorial;

protected:
	UFUNCTION(BlueprintCallable)
	void FTitleDelegateExcute(FTitleDelegate Target);
};
