// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#include "CapTheBrainProto1.h"
#include "CapTheBrainProto1GameMode.h"
#include "CapTheBrainProto1Character.h"

ACapTheBrainProto1GameMode::ACapTheBrainProto1GameMode(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/MyCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
