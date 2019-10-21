// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MiniRunner/Public/Globals.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGlobals() {}
// Cross Module References
	MINIRUNNER_API UEnum* Z_Construct_UEnum_MiniRunner_ESpawnTargetDataInfo();
	UPackage* Z_Construct_UPackage__Script_MiniRunner();
// End Cross Module References
	static UEnum* ESpawnTargetDataInfo_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_MiniRunner_ESpawnTargetDataInfo, Z_Construct_UPackage__Script_MiniRunner(), TEXT("ESpawnTargetDataInfo"));
		}
		return Singleton;
	}
	template<> MINIRUNNER_API UEnum* StaticEnum<ESpawnTargetDataInfo>()
	{
		return ESpawnTargetDataInfo_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_ESpawnTargetDataInfo(ESpawnTargetDataInfo_StaticEnum, TEXT("/Script/MiniRunner"), TEXT("ESpawnTargetDataInfo"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_MiniRunner_ESpawnTargetDataInfo_Hash() { return 1154798699U; }
	UEnum* Z_Construct_UEnum_MiniRunner_ESpawnTargetDataInfo()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_MiniRunner();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("ESpawnTargetDataInfo"), 0, Get_Z_Construct_UEnum_MiniRunner_ESpawnTargetDataInfo_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "ESpawnTargetDataInfo::None", (int64)ESpawnTargetDataInfo::None },
				{ "ESpawnTargetDataInfo::SlopeLeft", (int64)ESpawnTargetDataInfo::SlopeLeft },
				{ "ESpawnTargetDataInfo::SlopeRight", (int64)ESpawnTargetDataInfo::SlopeRight },
				{ "ESpawnTargetDataInfo::BlockNormal", (int64)ESpawnTargetDataInfo::BlockNormal },
				{ "ESpawnTargetDataInfo::GrassyBlock", (int64)ESpawnTargetDataInfo::GrassyBlock },
				{ "ESpawnTargetDataInfo::BrokenBlock", (int64)ESpawnTargetDataInfo::BrokenBlock },
				{ "ESpawnTargetDataInfo::Movable", (int64)ESpawnTargetDataInfo::Movable },
				{ "ESpawnTargetDataInfo::FaunaLeft", (int64)ESpawnTargetDataInfo::FaunaLeft },
				{ "ESpawnTargetDataInfo::FaunaMiddle", (int64)ESpawnTargetDataInfo::FaunaMiddle },
				{ "ESpawnTargetDataInfo::FaunaRight", (int64)ESpawnTargetDataInfo::FaunaRight },
				{ "ESpawnTargetDataInfo::Spike", (int64)ESpawnTargetDataInfo::Spike },
				{ "ESpawnTargetDataInfo::Breakable", (int64)ESpawnTargetDataInfo::Breakable },
				{ "ESpawnTargetDataInfo::Food", (int64)ESpawnTargetDataInfo::Food },
				{ "ESpawnTargetDataInfo::Key", (int64)ESpawnTargetDataInfo::Key },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlockNormal.Name", "ESpawnTargetDataInfo::BlockNormal" },
				{ "Breakable.Name", "ESpawnTargetDataInfo::Breakable" },
				{ "BrokenBlock.Name", "ESpawnTargetDataInfo::BrokenBlock" },
				{ "FaunaLeft.Name", "ESpawnTargetDataInfo::FaunaLeft" },
				{ "FaunaMiddle.Name", "ESpawnTargetDataInfo::FaunaMiddle" },
				{ "FaunaRight.Name", "ESpawnTargetDataInfo::FaunaRight" },
				{ "Food.Comment", "// Item\n" },
				{ "Food.Name", "ESpawnTargetDataInfo::Food" },
				{ "Food.ToolTip", "Item" },
				{ "GrassyBlock.Name", "ESpawnTargetDataInfo::GrassyBlock" },
				{ "Key.Name", "ESpawnTargetDataInfo::Key" },
				{ "ModuleRelativePath", "Public/Globals.h" },
				{ "Movable.Name", "ESpawnTargetDataInfo::Movable" },
				{ "None.Name", "ESpawnTargetDataInfo::None" },
				{ "SlopeLeft.Comment", "// Tile\n" },
				{ "SlopeLeft.Name", "ESpawnTargetDataInfo::SlopeLeft" },
				{ "SlopeLeft.ToolTip", "Tile" },
				{ "SlopeRight.Name", "ESpawnTargetDataInfo::SlopeRight" },
				{ "Spike.Name", "ESpawnTargetDataInfo::Spike" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_MiniRunner,
				nullptr,
				"ESpawnTargetDataInfo",
				"ESpawnTargetDataInfo",
				Enumerators,
				ARRAY_COUNT(Enumerators),
				RF_Public|RF_Transient|RF_MarkAsNative,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				(uint8)UEnum::ECppForm::EnumClass,
				METADATA_PARAMS(Enum_MetaDataParams, ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
