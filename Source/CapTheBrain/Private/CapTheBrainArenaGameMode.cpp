// Fill out your copyright notice in the Description page of Project Settings.

#include "CapTheBrain.h"
#include "CapTheBrainArenaGameMode.h"
#include "BrainzlapGameInstance.h"
#include "PlayerCharacter.h"

ACapTheBrainArenaGameMode::ACapTheBrainArenaGameMode(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{

	
	if (GetWorld())
	{
		UBrainzlapGameInstance* instance = Cast<UBrainzlapGameInstance>(GetWorld()->GetGameInstance());
		if (instance->maleChar.Num() > 0)
		{
			if (instance->maleChar[0])
			{
				static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/Characters/Professor"));
				if (PlayerPawnBPClass.Class != NULL)
				{
					DefaultPawnClass = PlayerPawnBPClass.Class;
				}
			}
			else
			{
				static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/Characters/Professorin"));
				if (PlayerPawnBPClass.Class != NULL)
				{
					DefaultPawnClass = PlayerPawnBPClass.Class;
				}
			}
		}
	}
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
	UBrainzlapGameInstance* gameInstance = Cast<UBrainzlapGameInstance>(GetGameInstance());

	if (gameInstance)
	{
		if (gameInstance->players.Num() > 0)
		{
			int i = 0;
			for (TActorIterator<APlayerStart> ActorItr(GetWorld()); ActorItr; ++ActorItr)
			{
				if (i < gameInstance->players.Num())
				{
					gameInstance->players[i]->startPosition = ActorItr->GetActorLocation();
					gameInstance->players[i]->startRotation = ActorItr->GetActorRotation();
					gameInstance->players[i]->SetActorLocationAndRotation(gameInstance->players[i]->startPosition, gameInstance->players[i]->startRotation);
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

		ACapTheBrainCharacter* winner = nullptr;

		for (int i = 0; i < gameInstance->players.Num(); i++)
		{
			if (winner == nullptr)
			{
				winner = gameInstance->players[i];
				winner->won = true;
			}
			else if (winner->score < gameInstance->players[i]->score)
			{
				winner->won = false;

				winner = gameInstance->players[i];
				winner->won = true;
			}
		}

		if (winner->score == 0)
		{
			winner->won = false;
		}
	}
}


