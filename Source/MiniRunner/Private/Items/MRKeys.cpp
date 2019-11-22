// Fill out your copyright notice in the Description page of Project Settings.


#include "MRKeys.h"
#include "ConstructorHelpers.h"
#include "Paper2D\Classes\PaperFlipbook.h"
#include "Paper2D\Classes\PaperFlipbookComponent.h"

#include "Globals.h"
#include "HeroCharacter.h"
#include "MRController.h"

AMRKeys::AMRKeys()
{
	PrimaryActorTick.bCanEverTick = false;

	static ConstructorHelpers::FObjectFinder<UPaperFlipbook> FB_KEY(TEXT("PaperFlipbook'/Game/MiniRunner/Sprites/Item/Key.Key'"));
	if (FB_KEY.Succeeded())
	{
		GetRenderComponent()->SetFlipbook(FB_KEY.Object);
	}

	KeyType = EMRKeyType::None;
	GetRenderComponent()->SetCollisionProfileName(TEXT("OverlapAll"));
	GetRenderComponent()->OnComponentBeginOverlap.AddDynamic(this, &AMRKeys::OnOverlapBegin);
}

void AMRKeys::BeginPlay() {}

void AMRKeys::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AHeroCharacter* Hero = Cast<AHeroCharacter>(OtherActor);
	AMRController* Player;
	if (Hero == nullptr) return;
	Player = Cast<AMRController>(Hero->GetController<AMRController>());
	if (Player == nullptr) return;

	switch (KeyType)
	{
	case EMRKeyType::Red:		++(Hero->KeyInventory.RedKey);		break;
	case EMRKeyType::Blue:		++(Hero->KeyInventory.BlueKey);		break;
	case EMRKeyType::Green:		++(Hero->KeyInventory.GreenKey);	break;
	case EMRKeyType::Master:	++(Hero->KeyInventory.MasterKey);	break;

	case EMRKeyType::None: default: 
		UE_LOG(LogTemp, Error, TEXT("ERROR - You get the key, but THIS KEY WAS TAGGED TO NONE OR ERROR. so you are not gained."));
		break;
	}

	Player->Hud_KeyUpdate();
	Destroy();
}

bool AMRKeys::Init(EMRKeyType type)
{
	switch (type)
	{
	case EMRKeyType::Red:		GetRenderComponent()->SetSpriteColor(FLinearColor::Red);	break;
	case EMRKeyType::Blue:		GetRenderComponent()->SetSpriteColor(FLinearColor::Blue);	break;
	case EMRKeyType::Green:		GetRenderComponent()->SetSpriteColor(FLinearColor::Green);	break;
	case EMRKeyType::Master:	GetRenderComponent()->SetSpriteColor(FLinearColor::Black);	break;

	case EMRKeyType::None: default: return false;
	}

	KeyType = type;
	GetRenderComponent()->PlayFromStart();
	return true;
}