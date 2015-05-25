// Fill out your copyright notice in the Description page of Project Settings.

#include "CapTheBrain.h"
#include "CapTheBrainArenaGameMode.h"
#include "BrainzlabGameState.h"
#include "BrainzlapGameInstance.h"
#include "PlayerCharacter.h"

ACapTheBrainArenaGameMode::ACapTheBrainArenaGameMode(const class FObjectInitializer& PCIP)
	: Super(PCIP)
{
	bUseSeamlessTravel = true;
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

void ACapTheBrainArenaGameMode::SetPlayerStartPositions()
{

	ABrainzlabGameState* gameState = Cast<ABrainzlabGameState>(GetWorld()->GetGameState());

	if (gameState)
	{
		if (gameState->characters.Num() > 0)
		{
			int i = 0;
			for (TActorIterator<APlayerStart> ActorItr(GetWorld()); ActorItr; ++ActorItr)
			{
				if (i < gameState->characters.Num())
				{
					gameState->characters[i]->startPosition = ActorItr->GetActorLocation();
					gameState->characters[i]->startRotation = ActorItr->GetActorRotation();
					gameState->characters[i]->SetActorLocationAndRotation(gameState->characters[i]->startPosition, gameState->characters[i]->startRotation);
					i++;
				}
			}
		}
	}

}

void ACapTheBrainArenaGameMode::GameOver()
{
	UBrainzlapGameInstance* gameInstance = Cast<UBrainzlapGameInstance>(GetGameInstance());
	if (!gameInstance->gameOver)
	{
		gameInstance->gameOver = true;

		TWeakObjectPtr<ACapTheBrainCharacter> winner;
		ABrainzlabGameState* gameState = Cast<ABrainzlabGameState>(GameState);

		if (gameState)
		{

			for (int i = 0; i < gameState->characters.Num(); i++)
			{
				if (winner == NULL)
				{
					winner = gameState->characters[i];
					winner->won = true;
				}
				else if (winner->score < gameState->characters[i]->score)
				{
					winner->won = false;

					winner = gameState->characters[i];
					winner->won = true;
				}
			}
		}

		if (winner->score == 0)
		{
			winner->won = false;
		}

	}
}


