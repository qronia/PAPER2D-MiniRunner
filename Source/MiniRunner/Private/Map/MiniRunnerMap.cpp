// Fill out your copyright notice in the Description page of Project Settings.


#include "MiniRunnerMap.h"
#include "Paper2D\Classes\PaperSprite.h"
#include "Paper2D\Classes\PaperGroupedSpriteActor.h"
#include "Paper2D\Classes\PaperGroupedSpriteComponent.h"
#include "ConstructorHelpers.h"

#include "Globals.h"
#include "MRKeys.h"
#include "Tile\MRKeyBlock.h"

// Sets default values
AMiniRunnerMap::AMiniRunnerMap()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// Sprite 등록
	{
		static ConstructorHelpers::FObjectFinder<UPaperSprite> PS_BLOCK_SLOPE1(TEXT("PaperSprite'/Game/MiniRunner/Sprites/Tiles/block1-slope_Sprite.block1-slope_Sprite'"));
		if (PS_BLOCK_SLOPE1.Succeeded())
		{
			Block_SlopeLeft = PS_BLOCK_SLOPE1.Object;
		}
		static ConstructorHelpers::FObjectFinder<UPaperSprite> PS_BLOCK_SLOPE2(TEXT("PaperSprite'/Game/MiniRunner/Sprites/Tiles/block1-slope_Sprite2.block1-slope_Sprite2'"));
		if (PS_BLOCK_SLOPE2.Succeeded())
		{
			Block_SlopeRight = PS_BLOCK_SLOPE2.Object;
		}
		static ConstructorHelpers::FObjectFinder<UPaperSprite> PS_BLOCK_NORMAL(TEXT("PaperSprite'/Game/MiniRunner/Sprites/Tiles/block1_Sprite.block1_Sprite'"));
		if (PS_BLOCK_NORMAL.Succeeded())
		{
			Block_Normal = PS_BLOCK_NORMAL.Object;
		}
		static ConstructorHelpers::FObjectFinder<UPaperSprite> PS_BLOCK_GRASSED(TEXT("PaperSprite'/Game/MiniRunner/Sprites/Tiles/block2_Sprite.block2_Sprite'"));
		if (PS_BLOCK_GRASSED.Succeeded())
		{
			Block_Grassed = PS_BLOCK_GRASSED.Object;
		}
		static ConstructorHelpers::FObjectFinder<UPaperSprite> PS_BLOCK_BREAKED(TEXT("PaperSprite'/Game/MiniRunner/Sprites/Tiles/block3_Sprite.block3_Sprite'"));
		if (PS_BLOCK_BREAKED.Succeeded())
		{
			Block_Breaked = PS_BLOCK_BREAKED.Object;
		}
		static ConstructorHelpers::FObjectFinder<UPaperSprite> PS_FAUNA_LEFT(TEXT("PaperSprite'/Game/MiniRunner/Sprites/Tiles/fauna1_Sprite.fauna1_Sprite'"));
		if (PS_FAUNA_LEFT.Succeeded())
		{
			Fauna_Left = PS_FAUNA_LEFT.Object;
		}
		static ConstructorHelpers::FObjectFinder<UPaperSprite> PS_FAUNA_MIDDLE(TEXT("PaperSprite'/Game/MiniRunner/Sprites/Tiles/fauna2_Sprite.fauna2_Sprite'"));
		if (PS_FAUNA_MIDDLE.Succeeded())
		{
			Fauna_Middle = PS_FAUNA_MIDDLE.Object;
		}
		static ConstructorHelpers::FObjectFinder<UPaperSprite> PS_FAUNA_RIGHT(TEXT("PaperSprite'/Game/MiniRunner/Sprites/Tiles/fauna3_Sprite.fauna3_Sprite'"));
		if (PS_FAUNA_RIGHT.Succeeded())
		{
			Fauna_Right = PS_FAUNA_RIGHT.Object;
		}
		static ConstructorHelpers::FObjectFinder<UPaperSprite> PS_SPIKE(TEXT("PaperSprite'/Game/MiniRunner/Sprites/Tiles/spikes1_Sprite.spikes1_Sprite'"));
		if (PS_SPIKE.Succeeded())
		{
			Spike = PS_SPIKE.Object;
		}
	}

	// C++ Script Actor 등록
	{
		static ConstructorHelpers::FClassFinder<AActor> CLS_FOOD(TEXT("Class'/Script/MiniRunner.MRFood'"));
		if (CLS_FOOD.Succeeded())
		{
			Item_Food = CLS_FOOD.Class;
		}
		static ConstructorHelpers::FClassFinder<AActor> CLS_KEY(TEXT("Class'/Script/MiniRunner.MRKeys'"));
		if (CLS_KEY.Succeeded())
		{
			Item_Key = CLS_KEY.Class;
		}
		static ConstructorHelpers::FClassFinder<AActor> CLS_KEYBLOCK(TEXT("Class'/Script/MiniRunner.MRKeyBlock'"));
		if (CLS_KEY.Succeeded())
		{
			Block_KeyBlock = CLS_KEYBLOCK.Class;
		}
		static ConstructorHelpers::FClassFinder<AActor> CLS_HERO(TEXT("Class'/Script/MiniRunner.HeroCharacter'"));
		if (CLS_KEY.Succeeded())
		{
			Class_Hero = CLS_HERO.Class;
		}
	}
	// Blueprint Tile Actor 등록 -> Breakable Block, Moveable Block, Grouped Spike
	{
		static ConstructorHelpers::FObjectFinder<UBlueprint> BP_BREAKABLE_BLOCK(TEXT("Blueprint'/Game/MiniRunner/Blueprints/Tiles/BreakableBlock.BreakableBlock'"));
		if (BP_BREAKABLE_BLOCK.Succeeded())
		{
			Block_Breakable = BP_BREAKABLE_BLOCK.Object->GeneratedClass;
		}

		static ConstructorHelpers::FObjectFinder<UBlueprint> BP_MOVABLE_BLOCK(TEXT("Blueprint'/Game/MiniRunner/Blueprints/Tiles/MovableBlock.MovableBlock'"));
		if (BP_MOVABLE_BLOCK.Succeeded())
		{
			Block_Movable = BP_MOVABLE_BLOCK.Object->GeneratedClass;
		}

		static ConstructorHelpers::FObjectFinder<UBlueprint> BP_GROUPED_SPIKE(TEXT("Blueprint'/Game/MiniRunner/Blueprints/Tiles/SpikeGrouped.SpikeGrouped'"));
		if (BP_GROUPED_SPIKE.Succeeded())
		{
			Grouped_Spike = BP_GROUPED_SPIKE.Object->GeneratedClass;
		}
	}

	Positioner = CreateDefaultSubobject<USceneComponent>(TEXT("RootPositioner"));

	Group_NormalBlock	= CreateDefaultSubobject<UPaperGroupedSpriteComponent>(TEXT("Group_Normal_Block"));
	Group_SlopeLeft		= CreateDefaultSubobject<UPaperGroupedSpriteComponent>(TEXT("Group_Slope_Left"));
	Group_SlopeRight	= CreateDefaultSubobject<UPaperGroupedSpriteComponent>(TEXT("Group_Slope_Right"));
	Group_GrassyBlock	= CreateDefaultSubobject<UPaperGroupedSpriteComponent>(TEXT("Group_Grassy_Block"));
	Group_BrokenBlock	= CreateDefaultSubobject<UPaperGroupedSpriteComponent>(TEXT("Group_Broken_Block"));
	Group_FaunaLeft		= CreateDefaultSubobject<UPaperGroupedSpriteComponent>(TEXT("Group_Fauna_Left"));
	Group_FaunaMiddle	= CreateDefaultSubobject<UPaperGroupedSpriteComponent>(TEXT("Group_Fauna_Middle"));
	Group_FaunaRight	= CreateDefaultSubobject<UPaperGroupedSpriteComponent>(TEXT("Group_Fauna_Right"));

	RootComponent = Positioner;
	Group_NormalBlock	->SetupAttachment(Positioner);
	Group_SlopeLeft		->SetupAttachment(Positioner);
	Group_SlopeRight	->SetupAttachment(Positioner);
	Group_GrassyBlock	->SetupAttachment(Positioner);
	Group_BrokenBlock	->SetupAttachment(Positioner);
	Group_FaunaLeft		->SetupAttachment(Positioner);
	Group_FaunaMiddle	->SetupAttachment(Positioner);
	Group_FaunaRight	->SetupAttachment(Positioner);

	Group_NormalBlock	->SetCollisionProfileName(TEXT("BlockAll"));
	Group_SlopeLeft		->SetCollisionProfileName(TEXT("BlockAll"));
	Group_SlopeRight	->SetCollisionProfileName(TEXT("BlockAll"));
	Group_GrassyBlock	->SetCollisionProfileName(TEXT("BlockAll"));
	Group_BrokenBlock	->SetCollisionProfileName(TEXT("BlockAll"));
	Group_FaunaLeft		->SetCollisionProfileName(TEXT("BlockAll"));
	Group_FaunaMiddle	->SetCollisionProfileName(TEXT("BlockAll"));
	Group_FaunaRight	->SetCollisionProfileName(TEXT("BlockAll"));

}

// Called when the game starts or when spawned
void AMiniRunnerMap::BeginPlay()
{
	Super::BeginPlay();

	SpikesHolder = GetWorld()->SpawnActor<APaperGroupedSpriteActor>(Grouped_Spike, FVector::ZeroVector, FRotator::ZeroRotator);
}

void AMiniRunnerMap::SetTile(ESpawnTargetDataInfo Target, float PosX, float PosY)
{
	FTransform transform = FTransform(FVector{ PosX,0.f, -PosY });
	switch (Target)
	{
	case ESpawnTargetDataInfo::BlockNormal:	Group_NormalBlock	->AddInstance(transform, Block_Normal);				break;
	case ESpawnTargetDataInfo::SlopeLeft:	Group_SlopeLeft		->AddInstance(transform, Block_SlopeLeft);			break;
	case ESpawnTargetDataInfo::SlopeRight:	Group_SlopeRight	->AddInstance(transform, Block_SlopeRight);			break;
	case ESpawnTargetDataInfo::GrassyBlock:	Group_GrassyBlock	->AddInstance(transform, Block_Grassed);			break;
	case ESpawnTargetDataInfo::BrokenBlock:	Group_BrokenBlock	->AddInstance(transform, Block_Breaked);			break;
	case ESpawnTargetDataInfo::FaunaLeft:	Group_FaunaLeft		->AddInstance(transform, Fauna_Left);				break;
	case ESpawnTargetDataInfo::FaunaMiddle:	Group_FaunaMiddle	->AddInstance(transform, Fauna_Middle);				break;
	case ESpawnTargetDataInfo::FaunaRight:	Group_FaunaRight	->AddInstance(transform, Fauna_Right);				break;
		
	case ESpawnTargetDataInfo::Spike:		SpikesHolder->GetRenderComponent()->AddInstance(transform, Spike);		break;

		// Dynamic Actors
	case ESpawnTargetDataInfo::Movable:		DynamicActorsPositions.Add(TTuple<UClass*, FTransform, uint8>{Block_Movable, transform, 0});	break;
	case ESpawnTargetDataInfo::Breakable:	DynamicActorsPositions.Add(TTuple<UClass*, FTransform, uint8>{Block_Breakable, transform, 0});	break;
	case ESpawnTargetDataInfo::Food:		DynamicActorsPositions.Add(TTuple<UClass*, FTransform, uint8>{Item_Food, transform, 0});		break;

	case ESpawnTargetDataInfo::RedKey:		DynamicActorsPositions.Add(TTuple<UClass*, FTransform, uint8>{Item_Key, transform, (uint8)EMRKeyType::Red});	break;
	case ESpawnTargetDataInfo::BlueKey:		DynamicActorsPositions.Add(TTuple<UClass*, FTransform, uint8>{Item_Key, transform, (uint8)EMRKeyType::Blue});	break;
	case ESpawnTargetDataInfo::GreenKey:	DynamicActorsPositions.Add(TTuple<UClass*, FTransform, uint8>{Item_Key, transform, (uint8)EMRKeyType::Green});	break;
	case ESpawnTargetDataInfo::MasterKey:	DynamicActorsPositions.Add(TTuple<UClass*, FTransform, uint8>{Item_Key, transform, (uint8)EMRKeyType::Master});	break;

	default: case ESpawnTargetDataInfo::None: break;
	}
}

// For Object Layer Actor Spawn.
void AMiniRunnerMap::SetTile(FString Name, FString Type, int32 Width, int32 Height, int32 x, int32 y)
{
	FTransform transform = FTransform{ FVector{ (float)(x+(Width/2)) , 0.f, -(float)(y+(Height/2)) } };

	if (Type.Equals(TEXT("player")))
	{
		DynamicActorsPositions.Add(TTuple<UClass*, FTransform, uint8>{Class_Hero, transform, 0});
		return;
	}
	else if (Type.Equals(TEXT("key")))
	{
		transform.SetScale3D(FVector{(float)Width,1.f,(float)Height});

		EMRKeyType NeedKeyType;
		
		if		(Name.Equals(TEXT("red")))		NeedKeyType = EMRKeyType::Red;
		else if (Name.Equals(TEXT("blue")))		NeedKeyType = EMRKeyType::Blue;
		else if (Name.Equals(TEXT("green")))	NeedKeyType = EMRKeyType::Green;
		else NeedKeyType = EMRKeyType::Master;

		DynamicActorsPositions.Add(TTuple<UClass*, FTransform, uint8>{Block_KeyBlock, transform, (uint8)NeedKeyType});
		return;
	}
}

void AMiniRunnerMap::Reload()
{
	AActor* Spawned;
	for (const auto& Target : DynamicActors)
	{
		if (IsValid(Target))
		{
			UE_LOG(LogTemp, Error, TEXT("%s, Deleted"), *Target->GetFullName());
			Target->Destroy(true);
		}
		else UE_LOG(LogTemp, Error, TEXT("Cannot Delete!"));
	}
	DynamicActors.Empty(0);

	for (const auto& TargetInfo : DynamicActorsPositions)
	{
		Spawned = GetWorld()->SpawnActor(TargetInfo.Get<0>(), &TargetInfo.Get<1>());
		DynamicActors.Add(Spawned);

		if (TargetInfo.Get<0>() == Item_Key)
		{
			AMRKeys* Key = Cast<AMRKeys>(Spawned);
			Key->Init((EMRKeyType)TargetInfo.Get<2>());
		}
		else if (TargetInfo.Get<0>() == Block_KeyBlock)
		{
			AMRKeyBlock* KeyBlock = Cast<AMRKeyBlock>(Spawned);
			KeyBlock->Init((EMRKeyType)TargetInfo.Get<2>());
		}
	}
}
