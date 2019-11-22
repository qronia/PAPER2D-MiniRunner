// Fill out your copyright notice in the Description page of Project Settings.


#include "MRTitleController.h"
#include "Blueprint\UserWidget.h"
#include "ConstructorHelpers.h"
#include "Misc/Paths.h"
#include "FileManager.h"
#include "PlatformFilemanager.h"
#include "Engine\Classes\Kismet\GameplayStatics.h"

#include "MRTitleUI.h"
#include "MapBrowserUI.h"
#include "MRGameInstance.h"


AMRTitleController::AMRTitleController()
{
	static ConstructorHelpers::FClassFinder<UUserWidget> BPWID_TITLE(TEXT("WidgetBlueprint'/Game/MiniRunner/Blueprints/UI/BP_TitleUI.BP_TitleUI_C'"));
	if (BPWID_TITLE.Succeeded())
	{
		TitleMenu = BPWID_TITLE.Class;
	}

	static ConstructorHelpers::FClassFinder<UUserWidget> BPWID_MAPLOADER(TEXT("WidgetBlueprint'/Game/MiniRunner/Blueprints/UI/BP_MapBrowserUI.BP_MapBrowserUI_C'"));
	if(BPWID_MAPLOADER.Succeeded())
	{
		MapLoadMenu = BPWID_MAPLOADER.Class;
	}
}

void AMRTitleController::BeginPlay()
{
	Super::BeginPlay();
	SetInputMode(FInputModeGameAndUI());
	bShowMouseCursor = true;

	TitleUI = nullptr;
	MapBrowserUI = nullptr;
	if(!IsLocalController() || !IsValid(TitleMenu) || !IsValid(MapLoadMenu)) return;

	OpenTitleMenu();
}

void AMRTitleController::GetMapListForMapBrowserUI()
{
	TArray<FString> MapFiles;
	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
	FString Path = FPaths::ProjectDir() + TEXT("Maps/");

	if (!PlatformFile.DirectoryExists(*Path))
	{
		PlatformFile.CreateDirectory(*Path);
		return;
	}

	if (MapBrowserUI == nullptr) return;
	MapBrowserUI->MapListItem_Clear();
	PlatformFile.FindFiles(MapFiles, *Path, TEXT(".json"));
	for (const auto& str : MapFiles)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s found. -> Cleaned Path is = {%s}"), *str, *FPaths::GetCleanFilename(*str));
		MapBrowserUI->MapListItem_Add(FPaths::GetCleanFilename(*str));
	}
}

void AMRTitleController::OpenTitleMenu()
{
	if (IsValid(MapBrowserUI))
	{
		MapBrowserUI->RemoveFromViewport();
		MapBrowserUI = nullptr;
	}

	if (TitleUI != nullptr) return;
	TitleUI = CreateWidget<UMRTitleUI>(this, TitleMenu);
	TitleUI->OnBtnClick_GameStart.BindDynamic(this, &AMRTitleController::OpenMapLoadMenu);
	TitleUI->OnBtnClick_Tutorial.BindDynamic(this, &AMRTitleController::StartTutorial);
	TitleUI->AddToViewport();
}

void AMRTitleController::OpenMapLoadMenu()
{
	if (IsValid(TitleUI))
	{
		TitleUI->RemoveFromViewport();
		TitleUI = nullptr;
	}

	if (MapBrowserUI != nullptr) return;
	MapBrowserUI = CreateWidget<UMapBrowserUI>(this, MapLoadMenu);
	MapBrowserUI->OnBtnClick_Close.BindDynamic(this, &AMRTitleController::OpenTitleMenu);
	MapBrowserUI->OnBtnClick_Start.BindDynamic(this, &AMRTitleController::StartGame);
	MapBrowserUI->OnBtnClick_ResetRanking.BindDynamic(this, &AMRTitleController::RankReset);
	MapBrowserUI->AddToViewport();
	GetMapListForMapBrowserUI();
}

void AMRTitleController::StartGame()
{
	UMRGameInstance* Instance = Cast<UMRGameInstance>(GetGameInstance());
	if (Instance == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("From AMRTitleController : UMRGameInstance not detected!"));
		return;
	}
	if (Instance->CurrentMapName.IsEmpty())
	{
		UE_LOG(LogTemp, Error, TEXT("From AMRTitleController : MapPath was Empty!"));
		return;
	}

	Instance->bIsTutorial = false;
	UGameplayStatics::OpenLevel(this, TEXT("GamePlayLevel"));
}

void AMRTitleController::StartTutorial()
{
	UMRGameInstance* Instance = Cast<UMRGameInstance>(GetGameInstance());
	if (Instance == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("From AMRTitleController : UMRGameInstance not detected!"));
		return;
	}
	Instance->bIsTutorial = true;
	UGameplayStatics::OpenLevel(this, TEXT("GamePlayLevel"));
}

void AMRTitleController::RankReset()
{
	IFileManager& fm = IFileManager::Get();
	UMRGameInstance* Instance = Cast<UMRGameInstance>(GetGameInstance());
	FString Path;
	if (Instance == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("From AMRTitleController : UMRGameInstance not detected!"));
		return;
	}

	Path = FPaths::ProjectDir() + TEXT("Maps/Ranking/") + Instance->CurrentMapName;
	fm.Delete(*Path, false, false, true);
}
