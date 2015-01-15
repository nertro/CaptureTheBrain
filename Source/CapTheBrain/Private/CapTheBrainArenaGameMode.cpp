// Fill out your copyright notice in the Description page of Project Settings.

#include "CapTheBrain.h"
#include "CapTheBrainArenaGameMode.h"
#include "BrainzlapGameInstance.h"
#include "PlayerCharacter.h"

ACapTheBrainArenaGameMode::ACapTheBrainArenaGameMode(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/Characters/Professor"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void ACapTheBrainArenaGameMode::GameOver()
{
	UBrainzlapGameInstance* gameInstance = Cast<UBrainzlapGameInstance>(GetGameInstance());
	for (std::vector<ACapTheBrainCharacter*>::iterator itr = gameInstance->players.begin(); itr != gameInstance->players.end(); itr++)
	{
		if ((*itr)->IsA(APlayerCharacter::StaticClass()))
		{
			APlayerController* ctrl = Cast<APlayerController>((*itr)->Controller);
			ctrl->SetCinematicMode(true, true, false);
		}
	}
}



