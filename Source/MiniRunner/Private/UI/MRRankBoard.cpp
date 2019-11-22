// Fill out your copyright notice in the Description page of Project Settings.


#include "MRRankBoard.h"
#include "Components\TextBlock.h"

#include "MRGameInstance.h"
#include "RankMaster.h"

void UMRRankBoard::NativeConstruct()
{
	Super::NativeConstruct();
	Reload();
}

void UMRRankBoard::Reload()
{
	UMRGameInstance* MRInstance = GetGameInstance<UMRGameInstance>();
	UTextBlock* txt_mapname = Cast<UTextBlock>(GetWidgetFromName(TEXT("txt_MapName")));
	UTextBlock* txt_ranking = Cast<UTextBlock>(GetWidgetFromName(TEXT("txt_Ranking")));

	if (txt_mapname == nullptr || txt_ranking == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("UMRRankBoard::NativeConstruct() - GetWidgetFromName Error"));
		return;
	}

	if (MRInstance == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("UMRRankBoard::NativeConstruct() - UMRGameInstance not found"));
		return;
	}

	RankMaster RM(MRInstance->CurrentMapName);
	txt_mapname->SetText(FText::FromString(MRInstance->CurrentMapName));
	txt_ranking->SetText(FText::FromString(RM.RanksToString()));
}
