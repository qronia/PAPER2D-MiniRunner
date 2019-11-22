// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MRController.generated.h"

UCLASS()
class MINIRUNNER_API AMRController : public APlayerController
{
	GENERATED_BODY()
	
private:
	TSubclassOf<UUserWidget> WidClass_Menu;
	TSubclassOf<UUserWidget> WidClass_HUD;

	class UMRGameMenu* Widget_Menu;
	class UMRInGame_Hud* Widget_Hud;

public:
	AMRController();
	virtual void BeginPlay() override;
	void ClearWidget();
	void Hud_KeyUpdate();

protected:
	virtual void SetupInputComponent() override;

private:
	void RequestRestart();
	UFUNCTION()
	void ToggleMenu();
	UFUNCTION()
	void ExitGame();
};
