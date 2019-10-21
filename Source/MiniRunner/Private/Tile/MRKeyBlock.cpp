// Fill out your copyright notice in the Description page of Project Settings.


#include "Tile\MRKeyBlock.h"
#include "ConstructorHelpers.h"
#include "Paper2D\Classes\PaperSprite.h"
#include "Paper2D\Classes\PaperSpriteComponent.h"
#include "Paper2D\Classes\PaperFlipbook.h"
#include "Paper2D\Classes\PaperFlipbookComponent.h"

#include "Globals.h"
#include "HeroCharacter.h"

// Sets default values
AMRKeyBlock::AMRKeyBlock()
{
	PrimaryActorTick.bCanEverTick = false;
	Positioner = CreateDefaultSubobject<USceneComponent>(TEXT("POSITIONER"));
	Flipbook_Key = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("SPRITE_KEY"));
	Sprite_Block = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("SPRITE_BLOCK"));
	
	RootComponent = Positioner;
	Sprite_Block->SetupAttachment(RootComponent);
	Flipbook_Key->SetupAttachment(RootComponent);
	Flipbook_Key->SetRelativeLocation(FVector{ 0.f,1.f,0.f });


	
	static ConstructorHelpers::FObjectFinder<UPaperFlipbook> FB_KEY(TEXT("PaperFlipbook'/Game/MiniRunner/Sprites/Item/Key.Key'"));
	if (FB_KEY.Succeeded())
	{
		Flipbook_Key->SetFlipbook(FB_KEY.Object);
	}

	static ConstructorHelpers::FObjectFinder<UPaperSprite> PS_BLOCK(TEXT("PaperSprite'/Game/MiniRunner/Sprites/Tiles/block4_Sprite.block4_Sprite'"));
	if (PS_BLOCK.Succeeded())
	{
		Sprite_Block->SetSprite(PS_BLOCK.Object);
	}

	NeedKeyType = EMRKeyType::None;

	Sprite_Block->SetCollisionProfileName(TEXT("BlockAll"));
	Sprite_Block->OnComponentHit.AddDynamic(this, &AMRKeyBlock::OnComponentBeginHit);
}

void AMRKeyBlock::OnComponentBeginHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector Impulse, const FHitResult& Hit)
{
	AHeroCharacter* Hero = Cast<AHeroCharacter>(OtherActor);
	if (Hero == nullptr) return;

	int32* Wanted = nullptr;
	switch (NeedKeyType)
	{
	case EMRKeyType::Red:		Wanted = &Hero->KeyInventory.RedKey;	break;
	case EMRKeyType::Blue:		Wanted = &Hero->KeyInventory.BlueKey;	break;
	case EMRKeyType::Green:		Wanted = &Hero->KeyInventory.GreenKey;	break;

	case EMRKeyType::None: case EMRKeyType::Master: default: break;
	}

	if (Wanted != nullptr && *Wanted > 0)
	{
		--(*Wanted);
		Destroy(); return;
	}

	if (Hero->KeyInventory.MasterKey > 0)
	{
		--(Hero->KeyInventory.MasterKey);
		Destroy(); return;
	}
}

// Called when the game starts or when spawned
void AMRKeyBlock::BeginPlay()
{
	Super::BeginPlay();
	
}

// Init을 두번 호출하지 않도록 한다. 여기서 Transform 변경이 일어난다.
void AMRKeyBlock::Init(EMRKeyType type)
{
	FVector Scale = GetActorScale3D();
	Sprite_Block->SetRelativeScale3D(FVector{Scale.X / 32, 1.f, Scale.Z / 32});
	SetActorScale3D(FVector{ 1.f,1.f,1.f });

	switch (type)
	{
	case EMRKeyType::Red:		Flipbook_Key->SetSpriteColor(FLinearColor::Red);	break;
	case EMRKeyType::Blue:		Flipbook_Key->SetSpriteColor(FLinearColor::Blue);	break;
	case EMRKeyType::Green:		Flipbook_Key->SetSpriteColor(FLinearColor::Green);	break;

	case EMRKeyType::None: default:
	case EMRKeyType::Master:	Flipbook_Key->SetSpriteColor(FLinearColor::Black);	break;
	}

	NeedKeyType = type;
}