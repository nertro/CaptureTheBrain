// Fill out your copyright notice in the Description page of Project Settings.

#include "CapTheBrain.h"
#include "CapTheBrainArenaGameMode.h"
#include "BrainzlapGameInstance.h"
#include "PlayerCharacter.h"

ACapTheBrainArenaGameMode::ACapTheBrainArenaGameMode(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	/*static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/Characters/Professor"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}*/
}

void ACapTheBrainArenaGameMode::SetPlayerMaterial(APawn* pawn, UMaterialInterface* newMaterial)
{
	if (pawn)
	{
		if (pawn->IsA(ACapTheBrainCharacter::StaticClass()))
		{
			Cast<ACapTheBrainCharacter>(pawn)->SetMaterial(newMaterial);
		}
	}
}

void ACapTheBrainArenaGameMode::GameOver()
{
	UBrainzlapGameInstance* gameInstance = Cast<UBrainzlapGameInstance>(GetGameInstance());
	if (!gameInstance->gameOver)
	{
		gameInstance->gameOver = true;

		ACapTheBrainCharacter* winner = nullptr;

		for (int i = 0; i < gameInstance->players.Num(); i++)
		{
			if (winner == nullptr)
			{
				winner = gameInstance->players[i];
				winner->won = true;
			}
			else if (winner->GetScore() < gameInstance->players[i]->GetScore())
			{
				winner->won = false;

				winner = gameInstance->players[i];
				winner->won = true;
			}
		}
	}
}


