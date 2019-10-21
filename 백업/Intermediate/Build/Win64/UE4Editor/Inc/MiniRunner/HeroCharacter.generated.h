// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef MINIRUNNER_HeroCharacter_generated_h
#error "HeroCharacter.generated.h already included, missing '#pragma once' in HeroCharacter.h"
#endif
#define MINIRUNNER_HeroCharacter_generated_h

#define MiniRunner_Source_MiniRunner_Public_HeroCharacter_h_15_RPC_WRAPPERS
#define MiniRunner_Source_MiniRunner_Public_HeroCharacter_h_15_RPC_WRAPPERS_NO_PURE_DECLS
#define MiniRunner_Source_MiniRunner_Public_HeroCharacter_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAHeroCharacter(); \
	friend struct Z_Construct_UClass_AHeroCharacter_Statics; \
public: \
	DECLARE_CLASS(AHeroCharacter, APaperCharacter, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/MiniRunner"), NO_API) \
	DECLARE_SERIALIZER(AHeroCharacter)


#define MiniRunner_Source_MiniRunner_Public_HeroCharacter_h_15_INCLASS \
private: \
	static void StaticRegisterNativesAHeroCharacter(); \
	friend struct Z_Construct_UClass_AHeroCharacter_Statics; \
public: \
	DECLARE_CLASS(AHeroCharacter, APaperCharacter, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/MiniRunner"), NO_API) \
	DECLARE_SERIALIZER(AHeroCharacter)


#define MiniRunner_Source_MiniRunner_Public_HeroCharacter_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AHeroCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AHeroCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AHeroCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AHeroCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AHeroCharacter(AHeroCharacter&&); \
	NO_API AHeroCharacter(const AHeroCharacter&); \
public:


#define MiniRunner_Source_MiniRunner_Public_HeroCharacter_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AHeroCharacter(AHeroCharacter&&); \
	NO_API AHeroCharacter(const AHeroCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AHeroCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AHeroCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AHeroCharacter)


#define MiniRunner_Source_MiniRunner_Public_HeroCharacter_h_15_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__Camera() { return STRUCT_OFFSET(AHeroCharacter, Camera); } \
	FORCEINLINE static uint32 __PPO__SpringArm() { return STRUCT_OFFSET(AHeroCharacter, SpringArm); } \
	FORCEINLINE static uint32 __PPO__Anim_Idle() { return STRUCT_OFFSET(AHeroCharacter, Anim_Idle); } \
	FORCEINLINE static uint32 __PPO__Anim_Walk() { return STRUCT_OFFSET(AHeroCharacter, Anim_Walk); } \
	FORCEINLINE static uint32 __PPO__Anim_Run() { return STRUCT_OFFSET(AHeroCharacter, Anim_Run); } \
	FORCEINLINE static uint32 __PPO__Anim_Push() { return STRUCT_OFFSET(AHeroCharacter, Anim_Push); } \
	FORCEINLINE static uint32 __PPO__Anim_Fall() { return STRUCT_OFFSET(AHeroCharacter, Anim_Fall); } \
	FORCEINLINE static uint32 __PPO__Anim_Jump() { return STRUCT_OFFSET(AHeroCharacter, Anim_Jump); } \
	FORCEINLINE static uint32 __PPO__Anim_WallSlide() { return STRUCT_OFFSET(AHeroCharacter, Anim_WallSlide); } \
	FORCEINLINE static uint32 __PPO__OriginalWalkSpeed() { return STRUCT_OFFSET(AHeroCharacter, OriginalWalkSpeed); } \
	FORCEINLINE static uint32 __PPO__WallSlideVelocity() { return STRUCT_OFFSET(AHeroCharacter, WallSlideVelocity); }


#define MiniRunner_Source_MiniRunner_Public_HeroCharacter_h_12_PROLOG
#define MiniRunner_Source_MiniRunner_Public_HeroCharacter_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	MiniRunner_Source_MiniRunner_Public_HeroCharacter_h_15_PRIVATE_PROPERTY_OFFSET \
	MiniRunner_Source_MiniRunner_Public_HeroCharacter_h_15_RPC_WRAPPERS \
	MiniRunner_Source_MiniRunner_Public_HeroCharacter_h_15_INCLASS \
	MiniRunner_Source_MiniRunner_Public_HeroCharacter_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define MiniRunner_Source_MiniRunner_Public_HeroCharacter_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	MiniRunner_Source_MiniRunner_Public_HeroCharacter_h_15_PRIVATE_PROPERTY_OFFSET \
	MiniRunner_Source_MiniRunner_Public_HeroCharacter_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	MiniRunner_Source_MiniRunner_Public_HeroCharacter_h_15_INCLASS_NO_PURE_DECLS \
	MiniRunner_Source_MiniRunner_Public_HeroCharacter_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> MINIRUNNER_API UClass* StaticClass<class AHeroCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID MiniRunner_Source_MiniRunner_Public_HeroCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
