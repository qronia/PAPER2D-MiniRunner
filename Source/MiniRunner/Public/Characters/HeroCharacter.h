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
	float WallSlideVelocity;

	const float HandPos = 10.f;
	ECharacterState State;

	FTimerHandle DeathTimeHandler;

public:
	FKeyInventory KeyInventory;

private:
	void UpdateCharacter();
	void UpdateAnimation();

protected:
	virtual void CustomJump();
	virtual void Tick(float DeltaSeconds) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void SideMove(float Value);

public:
	AHeroCharacter();

	UFUNCTION(BlueprintCallable)
	virtual void OnDeath();
};
