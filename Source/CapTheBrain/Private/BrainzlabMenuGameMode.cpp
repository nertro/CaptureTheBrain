// Fill out your copyright notice in the Description page of Project Settings.

#include "CapTheBrain.h"
#include "BrainzlapGameInstance.h"
#include "BrainzlabMenuGameMode.h"


ABrainzlabMenuGameMode::ABrainzlabMenuGameMode(const class FObjectInitializer& PCIP)
	: Super(PCIP)
{

}


void ABrainzlabMenuGameMode::StartNewGame()
{
	const int maxSize = 4;
	ULocalPlayer* PlayersToRemove[maxSize];
	int currPlayer = 0;

	for (FConstPlayerControllerIterator itr = GEngine->GameViewport->GetWorld()->GetPlayerControllerIterator(); itr; ++itr)
	{
		APlayerController* ctrl = *itr;

		if (ctrl && ctrl->IsLocalController() && !ctrl->IsPrimaryPlayer())
		{

			ULocalPlayer* playerToRemove = Cast<ULocalPlayer>(ctrl->Player);
			if (playerToRemove)
			{
				PlayersToRemove[currPlayer++] = playerToRemove;
				ctrl->PawnPendingDestroy(ctrl->GetPawn());
			}
		}
	}

	for (int i = 0; i < currPlayer; ++i)
	{
		GetWorld()->GetGameInstance()->RemoveLocalPlayer(PlayersToRemove[i]);
	}
}

void ABrainzlabMenuGameMode::DisableController(APlayerController* ctrl)
{
	if (!ctrl->bCinematicMode)
	{
		ctrl->SetCinematicMode(true, true, true);
	}
}