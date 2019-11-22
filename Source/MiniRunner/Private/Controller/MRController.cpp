// Fill out your copyright notice in the Description page of Project Settings.


#include "MRController.h"
#include "Engine\World.h"
#include "Blueprint\UserWidget.h"
#include "ConstructorHelpers.h"

#include "HeroCharacter.h"
#include "MRGameState.h"
#include "MRGameMode.h"
#include "MRGameMenu.h"
#include "MRInGame_Hud.h"
#include "MapLoader.h"

AMRController::AMRController()
{
	static ConstructorHelpers::FClassFinder<UUserWidget> CLASS_MENU(TEXT("WidgetBlueprint'/Game/MiniRunner/Blueprints/UI/BP_InGameMenu.BP_InGameMenu_C'"));
	if (CLASS_MENU.Succeeded())
	{
		WidClass_Menu = CLASS_MENU.Class;
	}

	static ConstructorHelpers::FClassFinder<UUserWidget> CLASS_HUD(TEXT("WidgetBlueprint'/Game/MiniRunner/Blueprints/UI/BP_InGameHUD.BP_InGameHUD_C'"));
	if (CLASS_HUD.Succeeded())
	{
		WidClass_HUD = CLASS_HUD.Class;
	}
}

void AMRController::BeginPlay()
{
	Super::BeginPlay();
}

FORCEINLINE void AMRController::ClearWidget()
{
	if (IsValid(Widget_Hud))	Widget_Hud	->RemoveFromParent();
	if (IsValid(Widget_Menu))	Widget_Menu	->RemoveFromParent();

	Widget_Hud = nullptr;
	Widget_Menu = nullptr;
}

void AMRController::Hud_KeyUpdate()
{
	AHeroCharacter* MyHero = Cast<AHeroCharacter>(GetPawn());
	if (!IsValid(MyHero) || !IsValid(Widget_Hud)) return;
	Widget_Hud->KeyCountUpdate(MyHero->KeyInventory);
}

void AMRController::SetupInputComponent()
{
	Super::SetupInputComponent();
	InputComponent->BindAction(TEXT("Restart"), EInputEvent::IE_Pressed, this, &AMRController::RequestRestart);
	InputComponent->BindAction(TEXT("Menu"), EInputEvent::IE_Pressed, this, &AMRController::ToggleMenu).bExecuteWhenPaused = true;
}

void AMRController::RequestRestart()
{
	AMRGameState* State = GetWorld()->GetGameState<AMRGameState>();
	check(State != nullptr);

	if (!(State->bIsGameRunning) || (IsValid(Widget_Menu) && Widget_Menu->IsInViewport())) return;

	AMRGameMode* Mode = GetWorld()->GetAuthGameMode<AMRGameMode>();
	check(Mode != nullptr);

	ClearWidget();
	Mode->Reset();
	Widget_Hud = CreateWidget<UMRInGame_Hud>(this, WidClass_HUD);
	Widget_Hud->AddToViewport();
}

void AMRController::ToggleMenu()
{
	AMRGameState* MRGameState = GetWorld()->GetGameState<AMRGameState>();
	if ( MRGameState == nullptr || !MRGameState->bIsGameRunning) return;

	// 버그인지는 모르겠지만 RemoveFromParent를 사용한 Widget에 한하여 
	// 포인터 등으로 레퍼런싱 하고 있다고 해도 GC가 소거해버리는 상황이 발생한다.
	// 이것은 그 현상을 우회하기 위한 방법이며, 
	// 이 방법을 사용했기 때문에 굳이 BeginPlay 등에서 최초 생성을 할 필요가 없어졌다.
	if (!(IsValid(Widget_Menu)))
	{
		Widget_Menu = CreateWidget<UMRGameMenu>(this, WidClass_Menu);
		Widget_Menu->OnClickContinue.BindDynamic(this, &AMRController::ToggleMenu);
		Widget_Menu->OnClickExit.BindDynamic(this, &AMRController::ExitGame);
	}

	if (Widget_Menu->IsInViewport())
	{
		Widget_Menu->RemoveFromParent();
		SetInputMode(FInputModeGameOnly());
		bShowMouseCursor = false;
		GetWorld()->GetAuthGameMode()->ClearPause();
		MRGameState->Timer_Resume();
		return;
	}

	MRGameState->Timer_MakeStopPoint();
	GetWorld()->GetAuthGameMode()->SetPause(this);
	Widget_Menu->AddToViewport();
	bShowMouseCursor = true;
	SetInputMode(FInputModeGameAndUI());
}

void AMRController::ExitGame()
{
	UGameplayStatics::OpenLevel(this, TEXT("Title"));
}