// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef MINIRUNNER_MapLoader_generated_h
#error "MapLoader.generated.h already included, missing '#pragma once' in MapLoader.h"
#endif
#define MINIRUNNER_MapLoader_generated_h

#define MiniRunner_Source_MiniRunner_Public_MapLoader_h_14_RPC_WRAPPERS
#define MiniRunner_Source_MiniRunner_Public_MapLoader_h_14_RPC_WRAPPERS_NO_PURE_DECLS
#define MiniRunner_Source_MiniRunner_Public_MapLoader_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMapLoader(); \
	friend struct Z_Construct_UClass_AMapLoader_Statics; \
public: \
	DECLARE_CLASS(AMapLoader, AActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/MiniRunner"), NO_API) \
	DECLARE_SERIALIZER(AMapLoader)


#define MiniRunner_Source_MiniRunner_Public_MapLoader_h_14_INCLASS \
private: \
	static void StaticRegisterNativesAMapLoader(); \
	friend struct Z_Construct_UClass_AMapLoader_Statics; \
public: \
	DECLARE_CLASS(AMapLoader, AActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/MiniRunner"), NO_API) \
	DECLARE_SERIALIZER(AMapLoader)


#define MiniRunner_Source_MiniRunner_Public_MapLoader_h_14_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AMapLoader(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AMapLoader) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMapLoader); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMapLoader); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMapLoader(AMapLoader&&); \
	NO_API AMapLoader(const AMapLoader&); \
public:


#define MiniRunner_Source_MiniRunner_Public_MapLoader_h_14_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMapLoader(AMapLoader&&); \
	NO_API AMapLoader(const AMapLoader&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMapLoader); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMapLoader); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AMapLoader)


#define MiniRunner_Source_MiniRunner_Public_MapLoader_h_14_PRIVATE_PROPERTY_OFFSET
#define MiniRunner_Source_MiniRunner_Public_MapLoader_h_11_PROLOG
#define MiniRunner_Source_MiniRunner_Public_MapLoader_h_14_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	MiniRunner_Source_MiniRunner_Public_MapLoader_h_14_PRIVATE_PROPERTY_OFFSET \
	MiniRunner_Source_MiniRunner_Public_MapLoader_h_14_RPC_WRAPPERS \
	MiniRunner_Source_MiniRunner_Public_MapLoader_h_14_INCLASS \
	MiniRunner_Source_MiniRunner_Public_MapLoader_h_14_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define MiniRunner_Source_MiniRunner_Public_MapLoader_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	MiniRunner_Source_MiniRunner_Public_MapLoader_h_14_PRIVATE_PROPERTY_OFFSET \
	MiniRunner_Source_MiniRunner_Public_MapLoader_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	MiniRunner_Source_MiniRunner_Public_MapLoader_h_14_INCLASS_NO_PURE_DECLS \
	MiniRunner_Source_MiniRunner_Public_MapLoader_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> MINIRUNNER_API UClass* StaticClass<class AMapLoader>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID MiniRunner_Source_MiniRunner_Public_MapLoader_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
