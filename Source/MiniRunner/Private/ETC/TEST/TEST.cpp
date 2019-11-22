// Fill out your copyright notice in the Description page of Project Settings.


#include "ETC\TEST\TEST.h"
#include "Engine\World.h"
#include "Misc\Paths.h"
#include "UnrealString.h"
#include "FileManager.h"
#include "Globals.h"
#include "RankMaster.h"


// Sets default values
ATEST::ATEST()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void ATEST::BeginPlay()
{
	Super::BeginPlay();

	//Test1();
	Test2();
}

void ATEST::Test1()
{
	FString Path = FPaths::ProjectDir() + TEXT("Maps/Ranking/Test.sav");
	FString strData = TEXT("FUCK YOU LEATHER Man!");

	uint8* mem = (uint8*)FMemory::Malloc(strData.Len());

	int32 outcome = StringToBytes(strData, mem, strData.Len());
	FString outputStr = BytesToString(mem, outcome);
	FMemory::Free(mem);
	UE_LOG(LogTemp, Error, TEXT("%d, %d, %d, %s"), sizeof(TCHAR), outcome, strData.Len(), *outputStr);

	UE_LOG(LogTemp, Error, TEXT("TEST - Start Function"));
	int32 input = -20;
	FArchive* Writer = IFileManager::Get().CreateFileWriter(*Path);
	if (Writer == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("TEST - Writer was nullptr."));
	}
	else
	{
		Writer->Serialize(&input, sizeof(input));
		Writer->Flush();
		delete Writer;
	}


	FArchive* Reader = IFileManager::Get().CreateFileReader(*Path);
	if (Reader == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("TEST - Reader was nullptr."));
	}
	else
	{
		int32 output = 0;
		Reader->Serialize(&output, sizeof(output));
		UE_LOG(LogTemp, Warning, TEXT("Readed Data -> %d"), output);

		delete Reader;
	}

	/*
	FString testStr = TEXT("TEST");
	FString testStr2 = TEXT("TEST2TEST2TEST2TEST2");
	UE_LOG(LogTemp, Warning, TEXT("LOG -> %d, %d"), sizeof(TCHAR), testStr.Len());
	UE_LOG(LogTemp, Warning, TEXT("LOG -> %d, %d"), sizeof(testStr), testStr.Len() * sizeof(TCHAR));
	UE_LOG(LogTemp, Warning, TEXT("LOG -> %d, %d"), sizeof(testStr),sizeof(testStr2));
	*/
}

void ATEST::Test2()
{
	FString FileName = TEXT("Test.sav");

	RankMaster writeRm = RankMaster(FileName);
	writeRm.UpdateRank(TEXT("myname1"), 100);
	writeRm.UpdateRank(TEXT("myname2"), 200);
	writeRm.UpdateRank(TEXT("myname6"), 600);
	writeRm.UpdateRank(TEXT("myname7"), 700);
	writeRm.UpdateRank(TEXT("myname3"), 300);
	writeRm.UpdateRank(TEXT("myname4"), 400);
	writeRm.UpdateRank(TEXT("myname8"), 800);
	writeRm.UpdateRank(TEXT("myname5"), 500);
	writeRm.SaveRanks();
	

	RankMaster readRm = RankMaster(FileName);
	UE_LOG(LogTemp, Warning, TEXT("----------- Result ---------\n%s"), *(readRm.RanksToString()));
}