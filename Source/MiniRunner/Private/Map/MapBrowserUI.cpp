// Fill out your copyright notice in the Description page of Project Settings.


#include "MapBrowserUI.h"

void UMapBrowserUI::FBrowserDelegateExcute(FBrowserDelegate Target)
{
	Target.ExecuteIfBound();
}
