// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EngineMinimal.h"
#include "PaperCharacter.h"
#include "Globals.h"
#include "HeroCharacter.generated.h"

UCLASS()
class MINIRUNNER_API AHeroCharacter : public APaperCharacter
{
	GENERATED_BODY()

private:
	enum class ECharacterState : uint8
	{
		IDLE,
		WALK,
		RUN,
		PUSH,
		FALL,
		JUMP,
		WALL_SLIDE,
		DEATH,
	};

	// 扁夯 备己前
	UPROPERTY(VisibleAnywhere, Meta=(AllowPrivateAccess = true))
	class UCameraComponent* Camera;

	UPROPERTY(VisibleAnywhere, Meta=(AllowPrivateAccess = true))
	class USpringArmComponent* SpringArm;

	// 局聪皋捞记
	UPROPERTY(VisibleAnywhere, Meta = (AllowPrivateAccess = true), Category = "Animations")
	class UPaperFlipbook* Anim_Idle;

	UPROPERTY(VisibleAnywhere, Meta = (AllowPrivateAccess = true), Category = "Animations")
	class UPaperFlipbook* Anim_Walk;

	UPROPERTY(VisibleAnywhere, Meta = (AllowPrivateAccess = true), Category = "Animations")
	class UPaperFlipbook* Anim_Run;

	UPROPERTY(VisibleAnywhere, Meta = (AllowPrivateAccess = true), Category = "Animations")
	class UPaperFlipbook* Anim_Push;

	UPROPERTY(VisibleAnywhere, Meta = (AllowPrivateAccess = true), Category = "Animations")
	class UPaperFlipbook* Anim_Fall;

	UPROPERTY(VisibleAnywhere, Meta = (AllowPrivateAccess = true), Category = "Animations")
	class UPaperFlipbook* Anim_Jump;

	UPROPERTY(VisibleAnywhere, Meta = (AllowPrivateAccess = true), Category = "Animations")
	class UPaperFlipbook* Anim_WallSlide;

	UPROPERTY(VisibleAnywhere, Meta = (AllowPrivateAccess = true), Category = "Animations")
	class UPaperFlipbook* Anim_Dead;

	// ETC
	UPROPERTY(VisibleAnywhere, Meta = (AllowPrivateAccess = true))
	float OriginalWalkSpeed;
	UPROPERTY(VisibleAnywhere, Meta = (AllowPrivateAccess = true))
	float RunSpeedRatio;
	
	UPROPERTY(VisibleAnywhere, Meta = (AllowPrivateAccess = true))
	float WallSlideVelocity;

	const float HandPos = 10.f;
	const float StaminaRecovery_Mult = 3.f;
	const float StaminaConsume_Mult = 7.f;
	const float MaxStaminaValue = 10.f;

	UPROPERTY(VisibleAnywhere, Category = Stat, Meta = (AllowPrivateAccess = true))
	float Stamina;
	bool bIsRunMode;
	bool bCanRun;

	ECharacterState State;
	FTimerHandle Stamina_NoRunTimer;

public:
	UPROPERTY(BlueprintReadOnly)
	FKeyInventory KeyInventory;

	UPROPERTY(EditAnywhere, Meta = (AllowPrivateAccess = true))
	class UWidgetComponent* StaminaBarComponent;
	class UStaminaBar* StaminaBar;

private:
	void UpdateCharacter();
	void UpdateAnimation();

	UFUNCTION()
	void RunRecovery();

protected:
	virtual void BeginPlay() override;
	virtual void CustomJump();
	virtual void Tick(float DeltaSeconds) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void SideMove(float Value);
	virtual void RunModeOn();
	virtual void RunModeOff();
	virtual void StaminaProcess(float DeltaSeconds);

public:
	AHeroCharacter();

	UFUNCTION(BlueprintCallable)
	virtual void OnDeath();
};
