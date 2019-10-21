// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MiniRunner/Public/HeroCharacter.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeHeroCharacter() {}
// Cross Module References
	MINIRUNNER_API UClass* Z_Construct_UClass_AHeroCharacter_NoRegister();
	MINIRUNNER_API UClass* Z_Construct_UClass_AHeroCharacter();
	PAPER2D_API UClass* Z_Construct_UClass_APaperCharacter();
	UPackage* Z_Construct_UPackage__Script_MiniRunner();
	PAPER2D_API UClass* Z_Construct_UClass_UPaperFlipbook_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
// End Cross Module References
	void AHeroCharacter::StaticRegisterNativesAHeroCharacter()
	{
	}
	UClass* Z_Construct_UClass_AHeroCharacter_NoRegister()
	{
		return AHeroCharacter::StaticClass();
	}
	struct Z_Construct_UClass_AHeroCharacter_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_WallSlideVelocity_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_WallSlideVelocity;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OriginalWalkSpeed_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_OriginalWalkSpeed;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Anim_WallSlide_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Anim_WallSlide;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Anim_Jump_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Anim_Jump;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Anim_Fall_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Anim_Fall;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Anim_Push_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Anim_Push;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Anim_Run_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Anim_Run;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Anim_Walk_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Anim_Walk;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Anim_Idle_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Anim_Idle;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SpringArm_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SpringArm;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Camera_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Camera;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AHeroCharacter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APaperCharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_MiniRunner,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHeroCharacter_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "HeroCharacter.h" },
		{ "ModuleRelativePath", "Public/HeroCharacter.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHeroCharacter_Statics::NewProp_WallSlideVelocity_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "HeroCharacter" },
		{ "ModuleRelativePath", "Public/HeroCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AHeroCharacter_Statics::NewProp_WallSlideVelocity = { "WallSlideVelocity", nullptr, (EPropertyFlags)0x0040000000020001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AHeroCharacter, WallSlideVelocity), METADATA_PARAMS(Z_Construct_UClass_AHeroCharacter_Statics::NewProp_WallSlideVelocity_MetaData, ARRAY_COUNT(Z_Construct_UClass_AHeroCharacter_Statics::NewProp_WallSlideVelocity_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHeroCharacter_Statics::NewProp_OriginalWalkSpeed_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "HeroCharacter" },
		{ "Comment", "// ETC\n" },
		{ "ModuleRelativePath", "Public/HeroCharacter.h" },
		{ "ToolTip", "ETC" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AHeroCharacter_Statics::NewProp_OriginalWalkSpeed = { "OriginalWalkSpeed", nullptr, (EPropertyFlags)0x0040000000020001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AHeroCharacter, OriginalWalkSpeed), METADATA_PARAMS(Z_Construct_UClass_AHeroCharacter_Statics::NewProp_OriginalWalkSpeed_MetaData, ARRAY_COUNT(Z_Construct_UClass_AHeroCharacter_Statics::NewProp_OriginalWalkSpeed_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHeroCharacter_Statics::NewProp_Anim_WallSlide_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "Animations" },
		{ "ModuleRelativePath", "Public/HeroCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AHeroCharacter_Statics::NewProp_Anim_WallSlide = { "Anim_WallSlide", nullptr, (EPropertyFlags)0x0040000000020001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AHeroCharacter, Anim_WallSlide), Z_Construct_UClass_UPaperFlipbook_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AHeroCharacter_Statics::NewProp_Anim_WallSlide_MetaData, ARRAY_COUNT(Z_Construct_UClass_AHeroCharacter_Statics::NewProp_Anim_WallSlide_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHeroCharacter_Statics::NewProp_Anim_Jump_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "Animations" },
		{ "ModuleRelativePath", "Public/HeroCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AHeroCharacter_Statics::NewProp_Anim_Jump = { "Anim_Jump", nullptr, (EPropertyFlags)0x0040000000020001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AHeroCharacter, Anim_Jump), Z_Construct_UClass_UPaperFlipbook_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AHeroCharacter_Statics::NewProp_Anim_Jump_MetaData, ARRAY_COUNT(Z_Construct_UClass_AHeroCharacter_Statics::NewProp_Anim_Jump_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHeroCharacter_Statics::NewProp_Anim_Fall_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "Animations" },
		{ "ModuleRelativePath", "Public/HeroCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AHeroCharacter_Statics::NewProp_Anim_Fall = { "Anim_Fall", nullptr, (EPropertyFlags)0x0040000000020001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AHeroCharacter, Anim_Fall), Z_Construct_UClass_UPaperFlipbook_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AHeroCharacter_Statics::NewProp_Anim_Fall_MetaData, ARRAY_COUNT(Z_Construct_UClass_AHeroCharacter_Statics::NewProp_Anim_Fall_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHeroCharacter_Statics::NewProp_Anim_Push_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "Animations" },
		{ "ModuleRelativePath", "Public/HeroCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AHeroCharacter_Statics::NewProp_Anim_Push = { "Anim_Push", nullptr, (EPropertyFlags)0x0040000000020001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AHeroCharacter, Anim_Push), Z_Construct_UClass_UPaperFlipbook_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AHeroCharacter_Statics::NewProp_Anim_Push_MetaData, ARRAY_COUNT(Z_Construct_UClass_AHeroCharacter_Statics::NewProp_Anim_Push_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHeroCharacter_Statics::NewProp_Anim_Run_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "Animations" },
		{ "ModuleRelativePath", "Public/HeroCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AHeroCharacter_Statics::NewProp_Anim_Run = { "Anim_Run", nullptr, (EPropertyFlags)0x0040000000020001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AHeroCharacter, Anim_Run), Z_Construct_UClass_UPaperFlipbook_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AHeroCharacter_Statics::NewProp_Anim_Run_MetaData, ARRAY_COUNT(Z_Construct_UClass_AHeroCharacter_Statics::NewProp_Anim_Run_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHeroCharacter_Statics::NewProp_Anim_Walk_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "Animations" },
		{ "ModuleRelativePath", "Public/HeroCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AHeroCharacter_Statics::NewProp_Anim_Walk = { "Anim_Walk", nullptr, (EPropertyFlags)0x0040000000020001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AHeroCharacter, Anim_Walk), Z_Construct_UClass_UPaperFlipbook_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AHeroCharacter_Statics::NewProp_Anim_Walk_MetaData, ARRAY_COUNT(Z_Construct_UClass_AHeroCharacter_Statics::NewProp_Anim_Walk_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHeroCharacter_Statics::NewProp_Anim_Idle_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "Animations" },
		{ "Comment", "// ?\xd6\xb4\xcf\xb8??\xcc\xbc?\n" },
		{ "ModuleRelativePath", "Public/HeroCharacter.h" },
		{ "ToolTip", "?\xd6\xb4\xcf\xb8??\xcc\xbc?" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AHeroCharacter_Statics::NewProp_Anim_Idle = { "Anim_Idle", nullptr, (EPropertyFlags)0x0040000000020001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AHeroCharacter, Anim_Idle), Z_Construct_UClass_UPaperFlipbook_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AHeroCharacter_Statics::NewProp_Anim_Idle_MetaData, ARRAY_COUNT(Z_Construct_UClass_AHeroCharacter_Statics::NewProp_Anim_Idle_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHeroCharacter_Statics::NewProp_SpringArm_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "HeroCharacter" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/HeroCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AHeroCharacter_Statics::NewProp_SpringArm = { "SpringArm", nullptr, (EPropertyFlags)0x00400000000a0009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AHeroCharacter, SpringArm), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AHeroCharacter_Statics::NewProp_SpringArm_MetaData, ARRAY_COUNT(Z_Construct_UClass_AHeroCharacter_Statics::NewProp_SpringArm_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHeroCharacter_Statics::NewProp_Camera_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "HeroCharacter" },
		{ "Comment", "// ?\xe2\xba\xbb ????\xc7\xb0\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/HeroCharacter.h" },
		{ "ToolTip", "?\xe2\xba\xbb ????\xc7\xb0" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AHeroCharacter_Statics::NewProp_Camera = { "Camera", nullptr, (EPropertyFlags)0x00400000000a0009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AHeroCharacter, Camera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AHeroCharacter_Statics::NewProp_Camera_MetaData, ARRAY_COUNT(Z_Construct_UClass_AHeroCharacter_Statics::NewProp_Camera_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AHeroCharacter_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHeroCharacter_Statics::NewProp_WallSlideVelocity,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHeroCharacter_Statics::NewProp_OriginalWalkSpeed,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHeroCharacter_Statics::NewProp_Anim_WallSlide,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHeroCharacter_Statics::NewProp_Anim_Jump,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHeroCharacter_Statics::NewProp_Anim_Fall,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHeroCharacter_Statics::NewProp_Anim_Push,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHeroCharacter_Statics::NewProp_Anim_Run,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHeroCharacter_Statics::NewProp_Anim_Walk,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHeroCharacter_Statics::NewProp_Anim_Idle,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHeroCharacter_Statics::NewProp_SpringArm,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHeroCharacter_Statics::NewProp_Camera,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AHeroCharacter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AHeroCharacter>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AHeroCharacter_Statics::ClassParams = {
		&AHeroCharacter::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AHeroCharacter_Statics::PropPointers,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		0,
		ARRAY_COUNT(Z_Construct_UClass_AHeroCharacter_Statics::PropPointers),
		0,
		0x009000A0u,
		METADATA_PARAMS(Z_Construct_UClass_AHeroCharacter_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AHeroCharacter_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AHeroCharacter()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AHeroCharacter_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AHeroCharacter, 1027139508);
	template<> MINIRUNNER_API UClass* StaticClass<AHeroCharacter>()
	{
		return AHeroCharacter::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AHeroCharacter(Z_Construct_UClass_AHeroCharacter, &AHeroCharacter::StaticClass, TEXT("/Script/MiniRunner"), TEXT("AHeroCharacter"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AHeroCharacter);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
