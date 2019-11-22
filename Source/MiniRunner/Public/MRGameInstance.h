// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MRGameInstance.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class MINIRUNNER_API UMRGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	// 당신은 이런 문제를 OpenLevel에 들어갈 인수형태로도 해결할 수 있다. 
	// 본인은 연습과 간단한 해결을 위해 GameInstance에 저장하는 것으로 해결하였다.
	UPROPERTY(BlueprintReadWrite)
	FString CurrentMapName;
	UPROPERTY(BlueprintReadOnly)
	bool bIsTutorial;

public:
	UMRGameInstance();
};
