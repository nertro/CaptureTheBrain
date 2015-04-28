// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#include "CapTheBrain.h"
#include "CapTheBrainGameMode.h"
#include "CapTheBrainCharacter.h"

ACapTheBrainGameMode::ACapTheBrainGameMode(const class FObjectInitializer& PCIP)
	: Super(PCIP)
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/Characters/Professorin"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
