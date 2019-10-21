// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef MINIRUNNER_Globals_generated_h
#error "Globals.generated.h already included, missing '#pragma once' in Globals.h"
#endif
#define MINIRUNNER_Globals_generated_h

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID MiniRunner_Source_MiniRunner_Public_Globals_h


#define FOREACH_ENUM_ESPAWNTARGETDATAINFO(op) \
	op(ESpawnTargetDataInfo::None) \
	op(ESpawnTargetDataInfo::SlopeLeft) \
	op(ESpawnTargetDataInfo::SlopeRight) \
	op(ESpawnTargetDataInfo::BlockNormal) \
	op(ESpawnTargetDataInfo::GrassyBlock) \
	op(ESpawnTargetDataInfo::BrokenBlock) \
	op(ESpawnTargetDataInfo::Movable) \
	op(ESpawnTargetDataInfo::FaunaLeft) \
	op(ESpawnTargetDataInfo::FaunaMiddle) \
	op(ESpawnTargetDataInfo::FaunaRight) \
	op(ESpawnTargetDataInfo::Spike) \
	op(ESpawnTargetDataInfo::Breakable) \
	op(ESpawnTargetDataInfo::Food) \
	op(ESpawnTargetDataInfo::Key) 

enum class ESpawnTargetDataInfo : uint8;
template<> MINIRUNNER_API UEnum* StaticEnum<ESpawnTargetDataInfo>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
