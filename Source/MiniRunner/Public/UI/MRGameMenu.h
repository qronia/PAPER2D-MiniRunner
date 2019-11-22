// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MRGameMenu.generated.h"

DECLARE_DYNAMIC_DELEGATE(FButtonClick);

UCLASS(Meta=(DisableNativeTick))
class MINIRUNNER_API UMRGameMenu : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = Custom)
	FButtonClick OnClickContinue;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = Custom)
	FButtonClick OnClickExit;

protected:
	UFUNCTION(BlueprintCallable)
	void FDelegateExecuter(FButtonClick Target);
};
