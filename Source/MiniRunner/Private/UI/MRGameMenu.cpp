// Fill out your copyright notice in the Description page of Project Settings.


#include "MRGameMenu.h"

void UMRGameMenu::FDelegateExecuter(FButtonClick Target)
{
	Target.ExecuteIfBound();
}