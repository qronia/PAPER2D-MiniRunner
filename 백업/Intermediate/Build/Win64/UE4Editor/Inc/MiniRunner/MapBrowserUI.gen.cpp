// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MiniRunner/Public/MapBrowserUI.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMapBrowserUI() {}
// Cross Module References
	MINIRUNNER_API UClass* Z_Construct_UClass_UMapBrowserUI_NoRegister();
	MINIRUNNER_API UClass* Z_Construct_UClass_UMapBrowserUI();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	UPackage* Z_Construct_UPackage__Script_MiniRunner();
// End Cross Module References
	void UMapBrowserUI::StaticRegisterNativesUMapBrowserUI()
	{
	}
	UClass* Z_Construct_UClass_UMapBrowserUI_NoRegister()
	{
		return UMapBrowserUI::StaticClass();
	}
	struct Z_Construct_UClass_UMapBrowserUI_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UMapBrowserUI_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_MiniRunner,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMapBrowserUI_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "MapBrowserUI.h" },
		{ "ModuleRelativePath", "Public/MapBrowserUI.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UMapBrowserUI_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMapBrowserUI>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UMapBrowserUI_Statics::ClassParams = {
		&UMapBrowserUI::StaticClass,
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
		0x00B010A0u,
		METADATA_PARAMS(Z_Construct_UClass_UMapBrowserUI_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UMapBrowserUI_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UMapBrowserUI()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UMapBrowserUI_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UMapBrowserUI, 3790812071);
	template<> MINIRUNNER_API UClass* StaticClass<UMapBrowserUI>()
	{
		return UMapBrowserUI::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UMapBrowserUI(Z_Construct_UClass_UMapBrowserUI, &UMapBrowserUI::StaticClass, TEXT("/Script/MiniRunner"), TEXT("UMapBrowserUI"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UMapBrowserUI);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
