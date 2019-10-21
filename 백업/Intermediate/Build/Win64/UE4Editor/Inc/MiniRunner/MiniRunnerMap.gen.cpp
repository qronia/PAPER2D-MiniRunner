// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MiniRunner/Private/MiniRunnerMap.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMiniRunnerMap() {}
// Cross Module References
	MINIRUNNER_API UClass* Z_Construct_UClass_AMiniRunnerMap_NoRegister();
	MINIRUNNER_API UClass* Z_Construct_UClass_AMiniRunnerMap();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_MiniRunner();
	MINIRUNNER_API UFunction* Z_Construct_UFunction_AMiniRunnerMap_Reload();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	PAPER2D_API UClass* Z_Construct_UClass_APaperGroupedSpriteActor_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	PAPER2D_API UClass* Z_Construct_UClass_UPaperSprite_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
// End Cross Module References
	void AMiniRunnerMap::StaticRegisterNativesAMiniRunnerMap()
	{
		UClass* Class = AMiniRunnerMap::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Reload", &AMiniRunnerMap::execReload },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AMiniRunnerMap_Reload_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMiniRunnerMap_Reload_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Private/MiniRunnerMap.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMiniRunnerMap_Reload_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMiniRunnerMap, nullptr, "Reload", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMiniRunnerMap_Reload_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AMiniRunnerMap_Reload_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMiniRunnerMap_Reload()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMiniRunnerMap_Reload_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AMiniRunnerMap_NoRegister()
	{
		return AMiniRunnerMap::StaticClass();
	}
	struct Z_Construct_UClass_AMiniRunnerMap_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Grouped_Spike_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_Grouped_Spike;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Block_Movable_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_Block_Movable;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Block_Breakable_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_Block_Breakable;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Spike_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Spike;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Fauna_Right_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Fauna_Right;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Fauna_Middle_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Fauna_Middle;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Fauna_Left_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Fauna_Left;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Block_Breaked_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Block_Breaked;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Block_Grassed_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Block_Grassed;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Block_Normal_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Block_Normal;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Block_SlopeRight_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Block_SlopeRight;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Block_SlopeLeft_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Block_SlopeLeft;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Positioner_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Positioner;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMiniRunnerMap_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_MiniRunner,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AMiniRunnerMap_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AMiniRunnerMap_Reload, "Reload" }, // 1541672605
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMiniRunnerMap_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "MiniRunnerMap.h" },
		{ "ModuleRelativePath", "Private/MiniRunnerMap.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMiniRunnerMap_Statics::NewProp_Grouped_Spike_MetaData[] = {
		{ "Category", "MiniRunnerMap" },
		{ "ModuleRelativePath", "Private/MiniRunnerMap.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_AMiniRunnerMap_Statics::NewProp_Grouped_Spike = { "Grouped_Spike", nullptr, (EPropertyFlags)0x0024080000000001, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMiniRunnerMap, Grouped_Spike), Z_Construct_UClass_APaperGroupedSpriteActor_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_AMiniRunnerMap_Statics::NewProp_Grouped_Spike_MetaData, ARRAY_COUNT(Z_Construct_UClass_AMiniRunnerMap_Statics::NewProp_Grouped_Spike_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMiniRunnerMap_Statics::NewProp_Block_Movable_MetaData[] = {
		{ "Category", "MiniRunnerMap" },
		{ "ModuleRelativePath", "Private/MiniRunnerMap.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_AMiniRunnerMap_Statics::NewProp_Block_Movable = { "Block_Movable", nullptr, (EPropertyFlags)0x0020080000000001, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMiniRunnerMap, Block_Movable), Z_Construct_UClass_UObject_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_AMiniRunnerMap_Statics::NewProp_Block_Movable_MetaData, ARRAY_COUNT(Z_Construct_UClass_AMiniRunnerMap_Statics::NewProp_Block_Movable_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMiniRunnerMap_Statics::NewProp_Block_Breakable_MetaData[] = {
		{ "Category", "MiniRunnerMap" },
		{ "ModuleRelativePath", "Private/MiniRunnerMap.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_AMiniRunnerMap_Statics::NewProp_Block_Breakable = { "Block_Breakable", nullptr, (EPropertyFlags)0x0020080000000001, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMiniRunnerMap, Block_Breakable), Z_Construct_UClass_UObject_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_AMiniRunnerMap_Statics::NewProp_Block_Breakable_MetaData, ARRAY_COUNT(Z_Construct_UClass_AMiniRunnerMap_Statics::NewProp_Block_Breakable_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMiniRunnerMap_Statics::NewProp_Spike_MetaData[] = {
		{ "Category", "MiniRunnerMap" },
		{ "ModuleRelativePath", "Private/MiniRunnerMap.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMiniRunnerMap_Statics::NewProp_Spike = { "Spike", nullptr, (EPropertyFlags)0x0020080000000001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMiniRunnerMap, Spike), Z_Construct_UClass_UPaperSprite_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMiniRunnerMap_Statics::NewProp_Spike_MetaData, ARRAY_COUNT(Z_Construct_UClass_AMiniRunnerMap_Statics::NewProp_Spike_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMiniRunnerMap_Statics::NewProp_Fauna_Right_MetaData[] = {
		{ "Category", "MiniRunnerMap" },
		{ "ModuleRelativePath", "Private/MiniRunnerMap.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMiniRunnerMap_Statics::NewProp_Fauna_Right = { "Fauna_Right", nullptr, (EPropertyFlags)0x0020080000000001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMiniRunnerMap, Fauna_Right), Z_Construct_UClass_UPaperSprite_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMiniRunnerMap_Statics::NewProp_Fauna_Right_MetaData, ARRAY_COUNT(Z_Construct_UClass_AMiniRunnerMap_Statics::NewProp_Fauna_Right_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMiniRunnerMap_Statics::NewProp_Fauna_Middle_MetaData[] = {
		{ "Category", "MiniRunnerMap" },
		{ "ModuleRelativePath", "Private/MiniRunnerMap.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMiniRunnerMap_Statics::NewProp_Fauna_Middle = { "Fauna_Middle", nullptr, (EPropertyFlags)0x0020080000000001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMiniRunnerMap, Fauna_Middle), Z_Construct_UClass_UPaperSprite_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMiniRunnerMap_Statics::NewProp_Fauna_Middle_MetaData, ARRAY_COUNT(Z_Construct_UClass_AMiniRunnerMap_Statics::NewProp_Fauna_Middle_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMiniRunnerMap_Statics::NewProp_Fauna_Left_MetaData[] = {
		{ "Category", "MiniRunnerMap" },
		{ "ModuleRelativePath", "Private/MiniRunnerMap.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMiniRunnerMap_Statics::NewProp_Fauna_Left = { "Fauna_Left", nullptr, (EPropertyFlags)0x0020080000000001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMiniRunnerMap, Fauna_Left), Z_Construct_UClass_UPaperSprite_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMiniRunnerMap_Statics::NewProp_Fauna_Left_MetaData, ARRAY_COUNT(Z_Construct_UClass_AMiniRunnerMap_Statics::NewProp_Fauna_Left_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMiniRunnerMap_Statics::NewProp_Block_Breaked_MetaData[] = {
		{ "Category", "MiniRunnerMap" },
		{ "ModuleRelativePath", "Private/MiniRunnerMap.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMiniRunnerMap_Statics::NewProp_Block_Breaked = { "Block_Breaked", nullptr, (EPropertyFlags)0x0020080000000001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMiniRunnerMap, Block_Breaked), Z_Construct_UClass_UPaperSprite_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMiniRunnerMap_Statics::NewProp_Block_Breaked_MetaData, ARRAY_COUNT(Z_Construct_UClass_AMiniRunnerMap_Statics::NewProp_Block_Breaked_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMiniRunnerMap_Statics::NewProp_Block_Grassed_MetaData[] = {
		{ "Category", "MiniRunnerMap" },
		{ "ModuleRelativePath", "Private/MiniRunnerMap.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMiniRunnerMap_Statics::NewProp_Block_Grassed = { "Block_Grassed", nullptr, (EPropertyFlags)0x0020080000000001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMiniRunnerMap, Block_Grassed), Z_Construct_UClass_UPaperSprite_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMiniRunnerMap_Statics::NewProp_Block_Grassed_MetaData, ARRAY_COUNT(Z_Construct_UClass_AMiniRunnerMap_Statics::NewProp_Block_Grassed_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMiniRunnerMap_Statics::NewProp_Block_Normal_MetaData[] = {
		{ "Category", "MiniRunnerMap" },
		{ "ModuleRelativePath", "Private/MiniRunnerMap.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMiniRunnerMap_Statics::NewProp_Block_Normal = { "Block_Normal", nullptr, (EPropertyFlags)0x0020080000000001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMiniRunnerMap, Block_Normal), Z_Construct_UClass_UPaperSprite_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMiniRunnerMap_Statics::NewProp_Block_Normal_MetaData, ARRAY_COUNT(Z_Construct_UClass_AMiniRunnerMap_Statics::NewProp_Block_Normal_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMiniRunnerMap_Statics::NewProp_Block_SlopeRight_MetaData[] = {
		{ "Category", "MiniRunnerMap" },
		{ "ModuleRelativePath", "Private/MiniRunnerMap.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMiniRunnerMap_Statics::NewProp_Block_SlopeRight = { "Block_SlopeRight", nullptr, (EPropertyFlags)0x0020080000000001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMiniRunnerMap, Block_SlopeRight), Z_Construct_UClass_UPaperSprite_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMiniRunnerMap_Statics::NewProp_Block_SlopeRight_MetaData, ARRAY_COUNT(Z_Construct_UClass_AMiniRunnerMap_Statics::NewProp_Block_SlopeRight_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMiniRunnerMap_Statics::NewProp_Block_SlopeLeft_MetaData[] = {
		{ "Category", "MiniRunnerMap" },
		{ "ModuleRelativePath", "Private/MiniRunnerMap.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMiniRunnerMap_Statics::NewProp_Block_SlopeLeft = { "Block_SlopeLeft", nullptr, (EPropertyFlags)0x0020080000000001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMiniRunnerMap, Block_SlopeLeft), Z_Construct_UClass_UPaperSprite_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMiniRunnerMap_Statics::NewProp_Block_SlopeLeft_MetaData, ARRAY_COUNT(Z_Construct_UClass_AMiniRunnerMap_Statics::NewProp_Block_SlopeLeft_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMiniRunnerMap_Statics::NewProp_Positioner_MetaData[] = {
		{ "Category", "MiniRunnerMap" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Private/MiniRunnerMap.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMiniRunnerMap_Statics::NewProp_Positioner = { "Positioner", nullptr, (EPropertyFlags)0x00200800000a0009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMiniRunnerMap, Positioner), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMiniRunnerMap_Statics::NewProp_Positioner_MetaData, ARRAY_COUNT(Z_Construct_UClass_AMiniRunnerMap_Statics::NewProp_Positioner_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMiniRunnerMap_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMiniRunnerMap_Statics::NewProp_Grouped_Spike,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMiniRunnerMap_Statics::NewProp_Block_Movable,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMiniRunnerMap_Statics::NewProp_Block_Breakable,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMiniRunnerMap_Statics::NewProp_Spike,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMiniRunnerMap_Statics::NewProp_Fauna_Right,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMiniRunnerMap_Statics::NewProp_Fauna_Middle,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMiniRunnerMap_Statics::NewProp_Fauna_Left,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMiniRunnerMap_Statics::NewProp_Block_Breaked,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMiniRunnerMap_Statics::NewProp_Block_Grassed,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMiniRunnerMap_Statics::NewProp_Block_Normal,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMiniRunnerMap_Statics::NewProp_Block_SlopeRight,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMiniRunnerMap_Statics::NewProp_Block_SlopeLeft,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMiniRunnerMap_Statics::NewProp_Positioner,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMiniRunnerMap_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMiniRunnerMap>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AMiniRunnerMap_Statics::ClassParams = {
		&AMiniRunnerMap::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AMiniRunnerMap_Statics::PropPointers,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		ARRAY_COUNT(FuncInfo),
		ARRAY_COUNT(Z_Construct_UClass_AMiniRunnerMap_Statics::PropPointers),
		0,
		0x008000A0u,
		METADATA_PARAMS(Z_Construct_UClass_AMiniRunnerMap_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AMiniRunnerMap_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AMiniRunnerMap()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AMiniRunnerMap_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AMiniRunnerMap, 1789008918);
	template<> MINIRUNNER_API UClass* StaticClass<AMiniRunnerMap>()
	{
		return AMiniRunnerMap::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AMiniRunnerMap(Z_Construct_UClass_AMiniRunnerMap, &AMiniRunnerMap::StaticClass, TEXT("/Script/MiniRunner"), TEXT("AMiniRunnerMap"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMiniRunnerMap);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
