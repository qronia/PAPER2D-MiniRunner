// Fill out your copyright notice in the Description page of Project Settings.


#include "RankMaster.h"
#include "FileManager.h"
#include "MemoryReader.h"

RankMaster::RankMaster(FString MapName)
{
	_FileName = MapName;
	LoadRanks();
}

bool RankMaster::CanBeRanker(int64 Time)
{
	if (_Ranks.Num() <= _MaxCountOfRanks) return true;
	return _Ranks.Last(0).MilliSecondsTime > Time;
}

void RankMaster::UpdateRank(FString TargetName, int64 Time)
{
	FRank* Target = _Ranks.FindByPredicate([TargetName](const FRank& a) { return a.Name == TargetName; });
	if (Target != nullptr)
	{
		if (Target->MilliSecondsTime < Time) return;
		Target->MilliSecondsTime = Time;
		SortRank();
		return;
	}
	_Ranks.Emplace(TargetName, Time);
	SortRank();
	if (_Ranks.Num() > _MaxCountOfRanks) _Ranks.SetNum(10);
}

bool RankMaster::SaveRanks()
{
	int32 byteLength;
	uint8* tempMem;
	FArchive* RankFile = IFileManager::Get().CreateFileWriter(*(GetRankingFolderPath() + _FileName));
	if (RankFile == nullptr) return false;

	for ( FRank& rank : _Ranks)
	{
		tempMem = reinterpret_cast<uint8*>(FMemory::Malloc(rank.Name.Len()));
		byteLength = StringToBytes(rank.Name, tempMem, rank.Name.Len());
		RankFile->Serialize(&byteLength, sizeof(byteLength));
		RankFile->Serialize(tempMem, byteLength);
		RankFile->Serialize(&rank.MilliSecondsTime, sizeof(rank.MilliSecondsTime));
		FMemory::Free(tempMem);
	}

	RankFile->Close();
	return true;
}

FString RankMaster::RanksToString()
{
	int32 EntryNumber = 0;
	int32 min, sec, millisec;
	FString Result;
	for (const FRank& rank : _Ranks)
	{
		min = rank.MilliSecondsTime / (1000 * 60);
		sec = (rank.MilliSecondsTime / 1000) % 60;
		millisec = rank.MilliSecondsTime % 1000;

		Result.Append(FString::Printf(TEXT("%d. [%s] - %02d.%02d.%04d\n"), ++EntryNumber, *(rank.Name), min, sec, millisec));
	}

	return Result;
}

bool RankMaster::LoadRanks()
{
	int32 byteLength = 0;
	int64 Time = 0;
	uint8* tempMem = nullptr;
	FArchive* RankFile = IFileManager::Get().CreateFileReader(*(GetRankingFolderPath() + _FileName));
	if (RankFile == nullptr) return false;

	_Ranks.Empty();
	while (!RankFile->AtEnd())
	{
		RankFile->Serialize(&byteLength, sizeof(byteLength));
		tempMem = (uint8*)FMemory::Malloc(byteLength);
		RankFile->Serialize(tempMem, byteLength);
		RankFile->Serialize(&Time, sizeof(Time));
		_Ranks.Add(FRank(BytesToString(tempMem, byteLength), Time));
		FMemory::Free(tempMem);
	}

	RankFile->Close();
	return true;
}
