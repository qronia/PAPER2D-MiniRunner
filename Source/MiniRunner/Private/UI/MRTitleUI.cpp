// Fill out your copyright notice in the Description page of Project Settings.


#include "MRTitleUI.h"

void UMRTitleUI::FTitleDelegateExcute(FTitleDelegate Target)
{
	Target.ExecuteIfBound();
}
