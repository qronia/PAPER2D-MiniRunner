// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FileManager.h"

#include "MapBrowserUI.generated.h"

DECLARE_DYNAMIC_DELEGATE(FBrowserDelegate);

UCLASS(Meta=(DisableNativeTick))
class MINIRUNNER_API UMapBrowserUI : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Event")
	FBrowserDelegate OnBtnClick_Close;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Event")
	FBrowserDelegate OnBtnClick_Start;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Event")
	FBrowserDelegate OnBtnClick_ResetRanking;

	UPROPERTY(BlueprintReadOnly)
	FString Str_RankBoard_MapName;
	UPROPERTY(BlueprintReadOnly)
	FString Str_RankBoard_Rank;

public:
	UFUNCTION(BlueprintImplementableEvent)
	void MapListItem_Add(const FString& MapName);
	UFUNCTION(BlueprintImplementableEvent)
	void MapListItem_Clear();
	

protected:
	UFUNCTION(BlueprintCallable)
	void FBrowserDelegateExcute(FBrowserDelegate Target);
};
