// Fill out your copyright notice in the Description page of Project Settings.


#include "MRFood.h"
#include "ConstructorHelpers.h"
#include "Paper2D\Classes\PaperFlipbook.h"
#include "Paper2D\Classes\PaperFlipbookComponent.h"

#include "MRGameMode.h"
#include "HeroCharacter.h"

AMRFood::AMRFood()
{
	PrimaryActorTick.bCanEverTick = false;

	static ConstructorHelpers::FObjectFinder<UPaperFlipbook> FB_KEY(TEXT("PaperFlipbook'/Game/MiniRunner/Sprites/Item/Food.Food'"));
	if (FB_KEY.Succeeded())
	{
		GetRenderComponent()->SetFlipbook(FB_KEY.Object);
	}

	GetRenderComponent()->SetCollisionProfileName(TEXT("OverlapAll"));
	GetRenderComponent()->OnComponentBeginOverlap.AddDynamic(this, &AMRFood::OnOverlapBegin);
}

void AMRFood::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (Cast<AHeroCharacter>(OtherActor) == nullptr) return; // 부딛힌 대상의 적법성 확인

	AMRGameMode* Mode = Cast<AMRGameMode>(GetWorld()->GetAuthGameMode());
	if (Mode == nullptr) return;


	Mode->OnGetFoodEvent();
	Destroy();
}