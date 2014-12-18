// Fill out your copyright notice in the Description page of Project Settings.

#include "CapTheBrain.h"
#include "FallNavArea.h"
#include "JumpNavArea.h"


UFallNavArea::UFallNavArea(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	FNavAreaHelper::Set(AreaFlags, ENavAreaFlag::Fall);
}


