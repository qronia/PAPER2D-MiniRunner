// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MiniRunner/Public/MapLoader.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMapLoader() {}
// Cross Module References
	MINIRUNNER_API UClass* Z_Construct_UClass_AMapLoader_NoRegister();
	MINIRUNNER_API UClass* Z_Construct_UClass_AMapLoader();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_MiniRunner();
// End Cross Module References
	void AMapLoader::StaticRegisterNativesAMapLoader()
	{
	}
	UClass* Z_Construct_UClass_AMapLoader_NoRegister()
	{
		return AMapLoader::StaticClass();
	}
	struct Z_Construct_UClass_AMapLoader_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMapLoader_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_MiniRunner,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMapLoader_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "MapLoader.h" },
		{ "ModuleRelativePath", "Public/MapLoader.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMapLoader_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMapLoader>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AMapLoader_Statics::ClassParams = {
		&AMapLoader::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009000A0u,
		METADATA_PARAMS(Z_Construct_UClass_AMapLoader_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AMapLoader_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AMapLoader()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AMapLoader_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AMapLoader, 501498925);
	template<> MINIRUNNER_API UClass* StaticClass<AMapLoader>()
	{
		return AMapLoader::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AMapLoader(Z_Construct_UClass_AMapLoader, &AMapLoader::StaticClass, TEXT("/Script/MiniRunner"), TEXT("AMapLoader"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMapLoader);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
