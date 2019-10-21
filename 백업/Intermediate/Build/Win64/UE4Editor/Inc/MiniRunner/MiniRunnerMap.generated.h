// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef MINIRUNNER_MiniRunnerMap_generated_h
#error "MiniRunnerMap.generated.h already included, missing '#pragma once' in MiniRunnerMap.h"
#endif
#define MINIRUNNER_MiniRunnerMap_generated_h

#define MiniRunner_Source_MiniRunner_Private_MiniRunnerMap_h_15_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execReload) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Reload(); \
		P_NATIVE_END; \
	}


#define MiniRunner_Source_MiniRunner_Private_MiniRunnerMap_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execReload) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Reload(); \
		P_NATIVE_END; \
	}


#define MiniRunner_Source_MiniRunner_Private_MiniRunnerMap_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMiniRunnerMap(); \
	friend struct Z_Construct_UClass_AMiniRunnerMap_Statics; \
public: \
	DECLARE_CLASS(AMiniRunnerMap, AActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/MiniRunner"), NO_API) \
	DECLARE_SERIALIZER(AMiniRunnerMap)


#define MiniRunner_Source_MiniRunner_Private_MiniRunnerMap_h_15_INCLASS \
private: \
	static void StaticRegisterNativesAMiniRunnerMap(); \
	friend struct Z_Construct_UClass_AMiniRunnerMap_Statics; \
public: \
	DECLARE_CLASS(AMiniRunnerMap, AActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/MiniRunner"), NO_API) \
	DECLARE_SERIALIZER(AMiniRunnerMap)


#define MiniRunner_Source_MiniRunner_Private_MiniRunnerMap_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AMiniRunnerMap(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AMiniRunnerMap) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMiniRunnerMap); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMiniRunnerMap); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMiniRunnerMap(AMiniRunnerMap&&); \
	NO_API AMiniRunnerMap(const AMiniRunnerMap&); \
public:


#define MiniRunner_Source_MiniRunner_Private_MiniRunnerMap_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMiniRunnerMap(AMiniRunnerMap&&); \
	NO_API AMiniRunnerMap(const AMiniRunnerMap&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMiniRunnerMap); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMiniRunnerMap); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AMiniRunnerMap)


#define MiniRunner_Source_MiniRunner_Private_MiniRunnerMap_h_15_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__Positioner() { return STRUCT_OFFSET(AMiniRunnerMap, Positioner); } \
	FORCEINLINE static uint32 __PPO__Block_SlopeLeft() { return STRUCT_OFFSET(AMiniRunnerMap, Block_SlopeLeft); } \
	FORCEINLINE static uint32 __PPO__Block_SlopeRight() { return STRUCT_OFFSET(AMiniRunnerMap, Block_SlopeRight); } \
	FORCEINLINE static uint32 __PPO__Block_Normal() { return STRUCT_OFFSET(AMiniRunnerMap, Block_Normal); } \
	FORCEINLINE static uint32 __PPO__Block_Grassed() { return STRUCT_OFFSET(AMiniRunnerMap, Block_Grassed); } \
	FORCEINLINE static uint32 __PPO__Block_Breaked() { return STRUCT_OFFSET(AMiniRunnerMap, Block_Breaked); } \
	FORCEINLINE static uint32 __PPO__Fauna_Left() { return STRUCT_OFFSET(AMiniRunnerMap, Fauna_Left); } \
	FORCEINLINE static uint32 __PPO__Fauna_Middle() { return STRUCT_OFFSET(AMiniRunnerMap, Fauna_Middle); } \
	FORCEINLINE static uint32 __PPO__Fauna_Right() { return STRUCT_OFFSET(AMiniRunnerMap, Fauna_Right); } \
	FORCEINLINE static uint32 __PPO__Spike() { return STRUCT_OFFSET(AMiniRunnerMap, Spike); } \
	FORCEINLINE static uint32 __PPO__Block_Breakable() { return STRUCT_OFFSET(AMiniRunnerMap, Block_Breakable); } \
	FORCEINLINE static uint32 __PPO__Block_Movable() { return STRUCT_OFFSET(AMiniRunnerMap, Block_Movable); } \
	FORCEINLINE static uint32 __PPO__Grouped_Spike() { return STRUCT_OFFSET(AMiniRunnerMap, Grouped_Spike); }


#define MiniRunner_Source_MiniRunner_Private_MiniRunnerMap_h_12_PROLOG
#define MiniRunner_Source_MiniRunner_Private_MiniRunnerMap_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	MiniRunner_Source_MiniRunner_Private_MiniRunnerMap_h_15_PRIVATE_PROPERTY_OFFSET \
	MiniRunner_Source_MiniRunner_Private_MiniRunnerMap_h_15_RPC_WRAPPERS \
	MiniRunner_Source_MiniRunner_Private_MiniRunnerMap_h_15_INCLASS \
	MiniRunner_Source_MiniRunner_Private_MiniRunnerMap_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define MiniRunner_Source_MiniRunner_Private_MiniRunnerMap_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	MiniRunner_Source_MiniRunner_Private_MiniRunnerMap_h_15_PRIVATE_PROPERTY_OFFSET \
	MiniRunner_Source_MiniRunner_Private_MiniRunnerMap_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	MiniRunner_Source_MiniRunner_Private_MiniRunnerMap_h_15_INCLASS_NO_PURE_DECLS \
	MiniRunner_Source_MiniRunner_Private_MiniRunnerMap_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> MINIRUNNER_API UClass* StaticClass<class AMiniRunnerMap>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID MiniRunner_Source_MiniRunner_Private_MiniRunnerMap_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
