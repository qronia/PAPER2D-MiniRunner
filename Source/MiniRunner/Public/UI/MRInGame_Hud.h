// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MRInGame_Hud.generated.h"

/**
 * 
 */
UCLASS()
class MINIRUNNER_API UMRInGame_Hud : public UUserWidget
{
	GENERATED_BODY()
private:
	class AMRGameState* _State;
	class UTextBlock* _txt_ElapsedTime;
	class UTextBlock* _txt_FoodCount;
	class UTextBlock* _txt_RedCount;
	class UTextBlock* _txt_BlueCount;
	class UTextBlock* _txt_GreenCount;
	class UTextBlock* _txt_MasterCount;

public:
	virtual void NativeConstruct() override;
	virtual void NativeTick(const FGeometry &Geometry, float DeltaSeconds) override;
	void KeyCountUpdate(struct FKeyInventory& Inventory);
};
