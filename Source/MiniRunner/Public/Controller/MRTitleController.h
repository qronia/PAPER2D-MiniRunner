// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MRTitleController.generated.h"


UCLASS()
class MINIRUNNER_API AMRTitleController : public APlayerController
{
	GENERATED_BODY()
	
private:
	UPROPERTY(VisibleAnywhere, Category="UI")
	TSubclassOf<UUserWidget> TitleMenu;
	UPROPERTY(VisibleAnywhere, Category = "UI")
	TSubclassOf<UUserWidget> MapLoadMenu;

	class UMRTitleUI* TitleUI;
	class UMapBrowserUI* MapBrowserUI;

public:
	AMRTitleController();
	virtual void BeginPlay() override;

private:
	void GetMapListForMapBrowserUI();

	UFUNCTION()
	void OpenTitleMenu();
	UFUNCTION()
	void OpenMapLoadMenu();

	UFUNCTION()
	void StartGame();
	UFUNCTION()
	void StartTutorial();
	UFUNCTION()
	void RankReset();
};
