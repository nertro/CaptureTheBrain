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
	if (pawn->IsA(ACapTheBrainCharacter::StaticClass()))
	{
		Cast<ACapTheBrainCharacter>(pawn)->SetMaterial(newMaterial);
	}
}

void ACapTheBrainArenaGameMode::GameOver()
{
	UBrainzlapGameInstance* gameInstance = Cast<UBrainzlapGameInstance>(GetGameInstance());
	gameInstance->gameOver = true;

	ACapTheBrainCharacter* winner = nullptr;

	for (std::vector<ACapTheBrainCharacter*>::iterator itr = gameInstance->players.begin(); itr != gameInstance->players.end(); itr++)
	{
		if (winner == nullptr)
		{
			winner = (*itr);
			winner->won = true;
		}
		else if (winner->GetScore() < (*itr)->GetScore())
		{
			winner->won = false;

			winner = (*itr);
			winner->won = true;
		}
	}
}


