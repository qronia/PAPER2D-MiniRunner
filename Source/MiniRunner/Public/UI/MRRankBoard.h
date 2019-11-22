// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MRRankBoard.generated.h"

UCLASS(Meta = (DisableNativeTick))
class MINIRUNNER_API UMRRankBoard : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;
	UFUNCTION(BlueprintCallable)
	virtual void Reload();
};
