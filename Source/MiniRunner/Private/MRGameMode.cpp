// Fill out your copyright notice in the Description page of Project Settings.


#include "MRGameMode.h"
#include "Paper2D\Classes\PaperFlipbookComponent.h"
#include "Blueprint\UserWidget.h"
#include "WidgetComponent.h"
#include "chrono"

#include "MRGameState.h"
#include "MRController.h"
#include "MRGameInstance.h"
#include "MapLoader.h"
#include "HeroCharacter.h"
#include "RankMaster.h"

/*
	TODO LIST:

	4. Rank Master를 생성하고 통신하여 Rank 수정
*/

AMRGameMode::AMRGameMode()
{
	PrimaryActorTick.bCanEverTick = false;
	DefaultPawnClass = nullptr;
	GameStateClass = AMRGameState::StaticClass();
	PlayerControllerClass = AMRController::StaticClass();
}

void AMRGameMode::BeginPlay()
{
	FString Path;
	AHeroCharacter* hero = nullptr;
	APlayerController* localplayer = GetWorld()->GetFirstPlayerController();
	UMRGameInstance* Instance = Cast<UMRGameInstance>(GetGameInstance());
	TSubclassOf<UUserWidget> StartIntroUIClass = LoadClass<UUserWidget>(nullptr, TEXT("WidgetBlueprint'/Game/MiniRunner/Blueprints/UI/PressStartIntroduceUI.PressStartIntroduceUI_C'"));

	MapLoader = GetWorld()->SpawnActor<AMapLoader>(AMapLoader::StaticClass());
	AMRGameState* State = Cast<AMRGameState>(GameState);

	check(MapLoader != nullptr);
	checkf(Instance != nullptr, TEXT("From AMRGameMode : UMRGameInstance was not found."));
	if (StartIntroUIClass != nullptr)
	{
		State->TempWidgetHolder = CreateWidget<UUserWidget>(localplayer, StartIntroUIClass);
		State->TempWidgetHolder->AddToViewport();
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("AMRController's BeginPlay() : Introduce Create Failed."));
	}

	if (Instance->bIsTutorial) Path = FPaths::ProjectDir() + TEXT("Maps/Tutorial/Tutorial.json");
	else Path = FPaths::ProjectDir() + TEXT("Maps/") + Instance->CurrentMapName;
	UE_LOG(LogTemp, Error, TEXT("Target's Path = {%s}"), *Path);

	if (!MapLoader->LoadMap(Path)) UGameplayStatics::OpenLevel(this, TEXT("Title"));

	MapLoader->ReloadMap(hero);
	if (hero == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("From AMRGameMode::BeginPlay() - hero was nullptr."));
		return;
	}

	hero->GetSprite()->SetHiddenInGame(true, true);
	if (localplayer == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("From AMRGameMode::BeginPlay() - localplayer not detected at BeginPlay()"));
		return;
	}
	localplayer->Possess(hero);
	hero->StaminaBarComponent->SetRelativeRotation(FRotator::ZeroRotator);
	hero->DisableInput(localplayer);

	State->bIsGameRunning = true;
	return;
}

bool AMRGameMode::SetPause(APlayerController* PC, FCanUnpause CanUnpauseDelegate)
{
	AMRGameState* MRGameState = Cast<AMRGameState>(GameState);
	if (MRGameState->bIsGameRunning)
	{
		Super::SetPause(PC, CanUnpauseDelegate);
		return true;
	}
	return false;
}

bool AMRGameMode::ClearPause()
{
	AMRGameState* MRGameState = Cast<AMRGameState>(GameState);
	if (MRGameState->bIsGameRunning)
	{
		Super::ClearPause();
		return true;
	}
	return false;
}


// Return true if game is ending state.
bool AMRGameMode::OnGetFoodEvent()
{
	AMRGameState* MRGameState = Cast<AMRGameState>(GameState);
	if (MRGameState->bIsDead || --(MRGameState->RemainFoodAmount) > 0) return false;

	// END GAME & MAKE RANK
	UMRGameInstance* Instance = GetGameInstance<UMRGameInstance>();
	SetPause(GetWorld()->GetFirstPlayerController());
	MRGameState->Timer_MakeStopPoint();
	MRGameState->bIsGameRunning = false;

	// tutorial or error
	if (Instance == nullptr || Instance->bIsTutorial)
	{
		UGameplayStatics::OpenLevel(this, TEXT("Title"));
		return true;
	}

	// normal state
	RankMaster RM(Instance->CurrentMapName);
	TSubclassOf<UUserWidget> InputWidget = LoadClass<UUserWidget>(nullptr, TEXT("WidgetBlueprint'/Game/MiniRunner/Blueprints/UI/BP_Rankinput.BP_Rankinput_C'"));
	if (!RM.CanBeRanker(MRGameState->GetTimerDuration().count()) || InputWidget == nullptr)
	{
		UGameplayStatics::OpenLevel(this, TEXT("Title"));
		return true;
	}

	CreateWidget(GetWorld()->GetFirstPlayerController(), InputWidget)->AddToViewport();
	GetWorld()->GetFirstPlayerController()->bShowMouseCursor = true;
	return true;
}

void AMRGameMode::SetFoodAmount(int Amount)
{
	if (Amount < 1) return;
	FullFoodAmount = Amount;
	ResetFoodAmount();
}

void AMRGameMode::ResetFoodAmount()
{
	AMRGameState* MRGameState = Cast<AMRGameState>(GameState);
	MRGameState->RemainFoodAmount = FullFoodAmount;
}

void AMRGameMode::Reset()
{
	AMRGameState* MRGameState = Cast<AMRGameState>(GameState);
	AHeroCharacter* hero = nullptr;
	APlayerController* localPlayer = GetWorld()->GetFirstPlayerController();

	localPlayer->UnPossess();
	MapLoader->ReloadMap(hero);
	if (hero == nullptr || !IsValid(hero)) return;
	localPlayer->Possess(hero);

	if (IsValid(MRGameState->TempWidgetHolder))
	{
		MRGameState->TempWidgetHolder->RemoveFromParent();
		MRGameState->TempWidgetHolder = nullptr;
	}
	MRGameState->bIsDead = false;
	MRGameState->Timer_Reset();	

	ResetFoodAmount();
}

void AMRGameMode::RankingUpdateAndEndGame(FString Name)
{
	AMRGameState* MRGameState = Cast<AMRGameState>(GameState);
	UMRGameInstance* Instance = GetGameInstance<UMRGameInstance>();
	int64 ElapsedTimeToClear = std::chrono::duration_cast<std::chrono::milliseconds>(MRGameState->GetTimerDuration()).count();
	check(Instance != nullptr);
	RankMaster RM(Instance->CurrentMapName);

	if (RM.CanBeRanker(ElapsedTimeToClear))
	{
		RM.UpdateRank(Name, ElapsedTimeToClear);
		RM.SaveRanks();
	}

	UGameplayStatics::OpenLevel(this, TEXT("Title"));
}
