// Fill out your copyright notice in the Description page of Project Settings.


#include "HeroCharacter.h"
#include "Paper2DClasses.h"
#include "AIController.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "WidgetComponent.h"
#include "StaminaBar.h"
#include "MRGameState.h"

#include "Globals.h"

AHeroCharacter::AHeroCharacter()
{
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("MainCamera"));
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	StaminaBarComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("StaminaBar"));

	StaminaBarComponent->SetupAttachment(RootComponent);
	SpringArm->SetupAttachment(RootComponent);
	Camera->SetupAttachment(SpringArm);

	// ĸ��������Ʈ : �浹 ����
	GetCapsuleComponent()->SetCapsuleRadius(10.f);
	GetCapsuleComponent()->SetCapsuleHalfHeight(20.f);

	// ī�޶� ����
	Camera->SetProjectionMode(ECameraProjectionMode::Orthographic);
	Camera->SetOrthoWidth(768.f); 

	SpringArm->RelativeRotation = FRotator{ 0.f,-90.f,0.f };
	SpringArm->TargetOffset = FVector{ 0.f, 50.f, 20.f };
	SpringArm->bUsePawnControlRotation = false;
	SpringArm->bInheritRoll = false;
	SpringArm->bInheritPitch = false;
	SpringArm->bInheritYaw = false;

	// HUD ����
	StaminaBarComponent->SetWorldRotation( FRotator{ 0.f, 90.f, 0.f });
	StaminaBarComponent->bAbsoluteRotation = true;
	StaminaBarComponent->RelativeLocation = FVector{ 0.f, 15.f, 40.f };
	StaminaBarComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	static ConstructorHelpers::FClassFinder<UUserWidget> WID_STAMINABAR(TEXT("WidgetBlueprint'/Game/MiniRunner/Blueprints/UI/BP_StaminaBar.BP_StaminaBar_C'"));
	if (WID_STAMINABAR.Succeeded())
	{
		StaminaBarComponent->SetWidgetClass(WID_STAMINABAR.Class);
		StaminaBarComponent->SetDrawSize(FVector2D(60.f, 5.f));
	}

	// ������ ���� ����
	OriginalWalkSpeed = 160;
	RunSpeedRatio = 1.8f;
	WallSlideVelocity = 180;

	GetMovementComponent()->bConstrainToPlane = true;
	GetMovementComponent()->SetPlaneConstraintAxisSetting(EPlaneConstraintAxisSetting::Y);
	GetCharacterMovement()->SetWalkableFloorAngle(45.0001f);
	GetCharacterMovement()->MaxWalkSpeed = OriginalWalkSpeed;
	GetCharacterMovement()->AirControl = 0.5f;
	GetCharacterMovement()->MaxStepHeight = 2.f;
	GetCharacterMovement()->Mass = 1.f;

	{
		static ConstructorHelpers::FObjectFinder<UPaperFlipbook> PF_IDLE(TEXT("PaperFlipbook'/Game/MiniRunner/Sprites/Hero/idle_Flipbook.idle_Flipbook'"));
		if (PF_IDLE.Succeeded()) Anim_Idle = PF_IDLE.Object;
		else Anim_Idle = nullptr;

		static ConstructorHelpers::FObjectFinder<UPaperFlipbook> PF_WALK(TEXT("PaperFlipbook'/Game/MiniRunner/Sprites/Hero/Anim_Walk.Anim_Walk'"));
		if (PF_WALK.Succeeded()) Anim_Walk = PF_WALK.Object;
		else Anim_Walk = nullptr;

		static ConstructorHelpers::FObjectFinder<UPaperFlipbook> PF_RUN(TEXT("PaperFlipbook'/Game/MiniRunner/Sprites/Hero/Anim_Run.Anim_Run'"));
		if (PF_RUN.Succeeded()) Anim_Run = PF_RUN.Object;
		else Anim_Run = nullptr;

		static ConstructorHelpers::FObjectFinder<UPaperFlipbook> PF_PUSH(TEXT("PaperFlipbook'/Game/MiniRunner/Sprites/Hero/Anim_Push.Anim_Push'"));
		if (PF_PUSH.Succeeded()) Anim_Push = PF_PUSH.Object;
		else Anim_Push = nullptr;

		static ConstructorHelpers::FObjectFinder<UPaperFlipbook> PF_FALL(TEXT("PaperFlipbook'/Game/MiniRunner/Sprites/Hero/Anim_Fall.Anim_Fall'"));
		if (PF_FALL.Succeeded()) Anim_Fall = PF_FALL.Object;
		else Anim_Fall = nullptr;

		static ConstructorHelpers::FObjectFinder<UPaperFlipbook> PF_JUMP(TEXT("PaperFlipbook'/Game/MiniRunner/Sprites/Hero/Anim_Jump.Anim_Jump'"));
		if (PF_JUMP.Succeeded()) Anim_Jump = PF_JUMP.Object;
		else Anim_Jump = nullptr;

		static ConstructorHelpers::FObjectFinder<UPaperFlipbook> PF_WALL_SLIDE(TEXT("PaperFlipbook'/Game/MiniRunner/Sprites/Hero/Anim_WallSlide.Anim_WallSlide'"));
		if (PF_WALL_SLIDE.Succeeded()) Anim_WallSlide = PF_WALL_SLIDE.Object;
		else Anim_WallSlide = nullptr;

		static ConstructorHelpers::FObjectFinder<UPaperFlipbook> PF_DEAD(TEXT("PaperFlipbook'/Game/MiniRunner/Sprites/Hero/bonk_Flipbook.bonk_Flipbook'"));
		if (PF_DEAD.Succeeded()) Anim_Dead = PF_DEAD.Object;
		else Anim_Dead = nullptr;
	}

	// �ʱ� �̹��� ����
	GetSprite()->SetRelativeLocation(FVector{ 0.f,0.f,-1.f });
	GetSprite()->SetFlipbook(Anim_Idle); // UpdateAnimation()���� �ִϸ��̼��� �����ϱ�� ������, �̰��� �����Ϳ��� ���̰� �ϱ� ���� ��.

	// ETC
	State = ECharacterState::IDLE;
	Stamina = 1.f;
	bCanRun = true;
	bIsRunMode = false;
}

void AHeroCharacter::UpdateCharacter()
{
	float Speed;

	// ���� ����
	Speed = GetVelocity().X;
	if (Speed < -KINDA_SMALL_NUMBER)
	{
		Controller->SetControlRotation(FRotator{ 0.f,180.f,0.f });
		Speed *= -1;
	}
	else if (Speed > KINDA_SMALL_NUMBER)
	{
		Controller->SetControlRotation(FRotator{ 0.f,0.f,0.f });
	}

	// �ٴڿ� ����������� ó�� : Run, Walk, Idle, (Push)
	if (GetCharacterMovement()->CurrentFloor.bBlockingHit)
	{
		if (State == ECharacterState::PUSH)
		{
			GetCharacterMovement()->MaxWalkSpeed = OriginalWalkSpeed / 2;
		}
		else
		{
			GetCharacterMovement()->MaxWalkSpeed = 
				bIsRunMode? OriginalWalkSpeed * RunSpeedRatio
				: OriginalWalkSpeed;				

			State = (Speed > OriginalWalkSpeed + 10.f)? ECharacterState::RUN
				:(Speed > KINDA_SMALL_NUMBER)? ECharacterState::WALK
				: ECharacterState::IDLE;
		}
	}
	// �ٴڿ� ������ : Fall, Jump, (WallSlide)
	else
	{
		if (State == ECharacterState::PUSH)
		{
			GetCharacterMovement()->MaxWalkSpeed = OriginalWalkSpeed;
		}
		else if (State == ECharacterState::WALL_SLIDE)
		{
			GetCharacterMovement()->Velocity.Z = -WallSlideVelocity;
			return;
		}

		Speed = GetVelocity().Z;
		State = (Speed > KINDA_SMALL_NUMBER) ? ECharacterState::JUMP : ECharacterState::FALL;
	}
}

void AHeroCharacter::UpdateAnimation()
{
	UPaperFlipbook* DesiredAnimation = nullptr; // Run, Walk, Fall, Jump, Push, WallSlide, Idle..

	if (State == ECharacterState::WALL_SLIDE)
	{
	   DesiredAnimation = Anim_WallSlide;
	   GetSprite()->SetRelativeRotation(FRotator{ 0.f,180.f,0.f });
	}
	else
	{
		GetSprite()->SetRelativeRotation(FRotator{ 0.f,0.f,0.f });
		switch (State)
		{
		case ECharacterState::IDLE:			DesiredAnimation = Anim_Idle;		break;
		case ECharacterState::WALK:			DesiredAnimation = Anim_Walk;		break;
		case ECharacterState::RUN:			DesiredAnimation = Anim_Run;		break;
		case ECharacterState::JUMP:			DesiredAnimation = Anim_Jump;		break;
		case ECharacterState::FALL:			DesiredAnimation = Anim_Fall;		break;
		case ECharacterState::PUSH:			DesiredAnimation = Anim_Push;		break;

		default: DesiredAnimation = nullptr; break; // Animation will not show if State was ERROR.
		}
	}

	if (GetSprite()->GetFlipbook() != DesiredAnimation)
	{
		GetSprite()->SetFlipbook(DesiredAnimation);
	}
}

void AHeroCharacter::RunRecovery()
{
	bCanRun = true;
}

void AHeroCharacter::BeginPlay()
{
	Super::BeginPlay();
	StaminaBar = Cast<UStaminaBar>(StaminaBarComponent->GetUserWidgetObject());
}

void AHeroCharacter::CustomJump()
{
	if (State == ECharacterState::WALL_SLIDE)
	{
		State = ECharacterState::JUMP;
		LaunchCharacter(FVector{ GetActorForwardVector().X * OriginalWalkSpeed * -1.4f,
			0.f, 
			GetCharacterMovement()->JumpZVelocity * 1.2f}, true, true);
	}
	else Jump();
}

void AHeroCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (State == ECharacterState::DEATH) return;
	UpdateCharacter();
	UpdateAnimation();
	StaminaProcess(DeltaSeconds);
}

void AHeroCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &AHeroCharacter::CustomJump);
	PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Released,this, &ACharacter::StopJumping);
	PlayerInputComponent->BindAction(TEXT("Run"), EInputEvent::IE_Pressed, this, &AHeroCharacter::RunModeOn);
	PlayerInputComponent->BindAction(TEXT("Run"), EInputEvent::IE_Released, this, &AHeroCharacter::RunModeOff);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &AHeroCharacter::SideMove);
}

void AHeroCharacter::SideMove(float Value)
{
	bool inAir = !GetCharacterMovement()->CurrentFloor.bBlockingHit;
	FHitResult Result;
	FCollisionObjectQueryParams Params;

	AddMovementInput(FVector{ Value,0.f,0.f });

	// ����(���) ���¶�� �Ʒ��� ������ ���̻� �õ��� �ʿ䰡 ����.
	if (State == ECharacterState::JUMP) return;


	// Value�� �̹� ����� ����, �񱳸� ���� ���밪���� ��ȯ
	if (Value < 0.f) Value *= -1;

	if (inAir)	Params.AddObjectTypesToQuery(ECollisionChannel::ECC_WorldStatic); // �� ����
	else		Params.AddObjectTypesToQuery(ECollisionChannel::ECC_WorldDynamic); // ������ �� �ִ� ���� ����

	if (GetWorld()->LineTraceSingleByObjectType(
		Result,
		GetActorLocation(),
		GetActorLocation() + GetActorForwardVector() * (HandPos + 2.0f),
		Params
	))
	{
		if (inAir)
		{
			if (Value > KINDA_SMALL_NUMBER) State = ECharacterState::WALL_SLIDE;
			else State = ECharacterState::FALL;
		}
		else
		{
			if (Value > KINDA_SMALL_NUMBER) State = ECharacterState::PUSH;
			else State = ECharacterState::IDLE;
		}
	}
	else
	{
		// WALL_SLIDE END
		State = inAir ? ECharacterState::FALL : ECharacterState::IDLE;
	}
}

void AHeroCharacter::RunModeOn()
{
	if (bCanRun == false) return;
	bIsRunMode = true;
}

void AHeroCharacter::RunModeOff()
{
	bIsRunMode = false;
}

void AHeroCharacter::StaminaProcess(float DeltaSeconds)
{
	if (!bCanRun) return;

	if (FMath::Abs(GetVelocity().X) > OriginalWalkSpeed + 10.f)
	{
		Stamina = FMath::Clamp<float>(Stamina - DeltaSeconds * StaminaConsume_Mult, -KINDA_SMALL_NUMBER, MaxStaminaValue);
		if (Stamina < KINDA_SMALL_NUMBER)
		{
			bCanRun = false;
			bIsRunMode = false;
			GetWorld()->GetTimerManager().SetTimer(Stamina_NoRunTimer, this, &AHeroCharacter::RunRecovery, 2.f, false);
		}
	}
	else
	{
		Stamina = FMath::Clamp<float>(Stamina + DeltaSeconds * StaminaRecovery_Mult, -KINDA_SMALL_NUMBER, MaxStaminaValue);
	}

	if (StaminaBar != nullptr)
	{
		StaminaBar->ChangePercentage(Stamina / MaxStaminaValue);
	}
}

void AHeroCharacter::OnDeath()
{
	GetWorld()->GetTimerManager().ClearTimer(Stamina_NoRunTimer);
	State = ECharacterState::DEATH;

	FVector NewLocation;
	AAIController* TempAi;
	APaperCharacter* DeadAnimActor;
	AMRGameState* MRGameState;
	APlayerController* Controller = GetController<APlayerController>();
	if (Controller == nullptr)
	{
		Destroy(); 
		return;
	}

	MRGameState = GetWorld()->GetGameState<AMRGameState>();
	if (MRGameState != nullptr)
	{
		MRGameState->bIsDead = true;
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("MRGameState was nullptr, This World's GameState Must be AMRGameState."));
	}

	DisableInput(Controller);
	SetActorHiddenInGame(true);
	GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	GetCharacterMovement()->GravityScale = 0.f;
	GetCharacterMovement()->Velocity = FVector{ 0.f,0.f,0.f };

	NewLocation = GetActorLocation();
	NewLocation.Y += 20.f;
	FActorSpawnParameters param;
	param.bNoFail = true;
	param.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	
	DeadAnimActor = GetWorld()->SpawnActor<APaperCharacter>(NewLocation, GetActorRotation(), param);
	TempAi = GetWorld()->SpawnActor<AAIController>(NewLocation, GetActorRotation(), param);
	if (DeadAnimActor == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("From HeroCharacter : DeadAnimActor Create Failed"));
		return;
	}
	DeadAnimActor->GetSprite()->SetFlipbook(Anim_Dead);
	DeadAnimActor->GetCapsuleComponent()->SetCapsuleRadius(1.f);
	DeadAnimActor->GetCapsuleComponent()->SetCapsuleHalfHeight(1.f);
	TempAi->Possess(DeadAnimActor);
	DeadAnimActor->LaunchCharacter(FVector{ 0.f,0.f,400.f }, true, true);
	DeadAnimActor->SetLifeSpan(4.f);
	TempAi->SetLifeSpan(4.f);
}
