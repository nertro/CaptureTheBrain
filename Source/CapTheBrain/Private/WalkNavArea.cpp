// Fill out your copyright notice in the Description page of Project Settings.

#include "CapTheBrain.h"
#include "JumpNavArea.h"
#include "WalkNavArea.h"


UWalkNavArea::UWalkNavArea(const class FObjectInitializer& PCIP)
	: Super(PCIP)
{
	FNavAreaHelper::Set(AreaFlags, ENavAreaFlag::Walk);
}


