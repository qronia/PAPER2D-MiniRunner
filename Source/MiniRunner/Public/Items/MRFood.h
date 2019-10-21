// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperFlipbookActor.h"
#include "MRFood.generated.h"

/**
 * 
 */
UCLASS()
class MINIRUNNER_API AMRFood : public APaperFlipbookActor
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, 
		AActor* OtherActor, 
		UPrimitiveComponent* OtherComp, 
		int32 OtherBodyIndex, 
		bool bFromSweep, 
		const FHitResult& SweepResult
	);

public:
	AMRFood();
};
