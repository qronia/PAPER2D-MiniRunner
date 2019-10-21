// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperFlipbookActor.h"
#include "MRKeys.generated.h"

enum class EMRKeyType : uint8;

UCLASS()
class MINIRUNNER_API AMRKeys : public APaperFlipbookActor
{
	GENERATED_BODY()

public:
	EMRKeyType KeyType;

protected:
	virtual void BeginPlay() override;

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
	AMRKeys();
	bool Init(EMRKeyType type);
};
