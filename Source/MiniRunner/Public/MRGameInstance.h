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
	// ����� �̷� ������ OpenLevel�� �� �μ����·ε� �ذ��� �� �ִ�. 
	// ������ ������ ������ �ذ��� ���� GameInstance�� �����ϴ� ������ �ذ��Ͽ���.
	UPROPERTY(BlueprintReadWrite)
	FString CurrentMapName;
	UPROPERTY(BlueprintReadOnly)
	bool bIsTutorial;

public:
	UMRGameInstance();
};
