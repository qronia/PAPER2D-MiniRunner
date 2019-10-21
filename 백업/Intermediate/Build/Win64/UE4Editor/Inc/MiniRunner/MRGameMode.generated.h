// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef MINIRUNNER_MRGameMode_generated_h
#error "MRGameMode.generated.h already included, missing '#pragma once' in MRGameMode.h"
#endif
#define MINIRUNNER_MRGameMode_generated_h

#define MiniRunner_Source_MiniRunner_Public_MRGameMode_h_15_RPC_WRAPPERS
#define MiniRunner_Source_MiniRunner_Public_MRGameMode_h_15_RPC_WRAPPERS_NO_PURE_DECLS
#define MiniRunner_Source_MiniRunner_Public_MRGameMode_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMRGameMode(); \
	friend struct Z_Construct_UClass_AMRGameMode_Statics; \
public: \
	DECLARE_CLASS(AMRGameMode, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/MiniRunner"), NO_API) \
	DECLARE_SERIALIZER(AMRGameMode)


#define MiniRunner_Source_MiniRunner_Public_MRGameMode_h_15_INCLASS \
private: \
	static void StaticRegisterNativesAMRGameMode(); \
	friend struct Z_Construct_UClass_AMRGameMode_Statics; \
public: \
	DECLARE_CLASS(AMRGameMode, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/MiniRunner"), NO_API) \
	DECLARE_SERIALIZER(AMRGameMode)


#define MiniRunner_Source_MiniRunner_Public_MRGameMode_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AMRGameMode(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AMRGameMode) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMRGameMode); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMRGameMode); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMRGameMode(AMRGameMode&&); \
	NO_API AMRGameMode(const AMRGameMode&); \
public:


#define MiniRunner_Source_MiniRunner_Public_MRGameMode_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AMRGameMode(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMRGameMode(AMRGameMode&&); \
	NO_API AMRGameMode(const AMRGameMode&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMRGameMode); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMRGameMode); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AMRGameMode)


#define MiniRunner_Source_MiniRunner_Public_MRGameMode_h_15_PRIVATE_PROPERTY_OFFSET
#define MiniRunner_Source_MiniRunner_Public_MRGameMode_h_12_PROLOG
#define MiniRunner_Source_MiniRunner_Public_MRGameMode_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	MiniRunner_Source_MiniRunner_Public_MRGameMode_h_15_PRIVATE_PROPERTY_OFFSET \
	MiniRunner_Source_MiniRunner_Public_MRGameMode_h_15_RPC_WRAPPERS \
	MiniRunner_Source_MiniRunner_Public_MRGameMode_h_15_INCLASS \
	MiniRunner_Source_MiniRunner_Public_MRGameMode_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define MiniRunner_Source_MiniRunner_Public_MRGameMode_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	MiniRunner_Source_MiniRunner_Public_MRGameMode_h_15_PRIVATE_PROPERTY_OFFSET \
	MiniRunner_Source_MiniRunner_Public_MRGameMode_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	MiniRunner_Source_MiniRunner_Public_MRGameMode_h_15_INCLASS_NO_PURE_DECLS \
	MiniRunner_Source_MiniRunner_Public_MRGameMode_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> MINIRUNNER_API UClass* StaticClass<class AMRGameMode>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID MiniRunner_Source_MiniRunner_Public_MRGameMode_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
