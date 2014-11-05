// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#include "CapTheBrain.h"
#include "CapTheBrainGameMode.h"
#include "CapTheBrainCharacter.h"

ACapTheBrainGameMode::ACapTheBrainGameMode(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/Characters/Professor"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
