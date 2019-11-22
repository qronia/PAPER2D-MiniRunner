// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Misc/Paths.h"
#include "Globals.h"

class MINIRUNNER_API RankMaster
{
private:
	const int _MaxCountOfRanks = 10;
	FString _FileName;
	TArray<FRank> _Ranks;
	
public:
	RankMaster() = delete;
	RankMaster(FString MapName);
	~RankMaster() = default;

	bool CanBeRanker(int64 Time);
	void UpdateRank(FString TargetName, int64 Time);
	bool SaveRanks();
	FString RanksToString();
	
private:
	FORCEINLINE FString GetRankingFolderPath() { return FPaths::ProjectDir() + TEXT("Maps/Ranking/"); }
	FORCEINLINE void SortRank() { _Ranks.Sort([](const FRank& a, const FRank& b) { return a.MilliSecondsTime < b.MilliSecondsTime; }); }
	bool LoadRanks();
};
