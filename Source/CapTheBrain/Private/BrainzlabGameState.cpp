// Fill out your copyright notice in the Description page of Project Settings.

#include "CapTheBrain.h"
#include "BrainzlabGameState.h"

void ABrainzlabGameState::DisableActorInScene(AActor* actor)
{
	actor->SetActorHiddenInGame(true);
	actor->SetActorEnableCollision(false);
}

void ABrainzlabGameState::EnableActorInScene(AActor* actor)
{
	actor->SetActorHiddenInGame(false);
	actor->SetActorEnableCollision(true);
}

ASpawnPoint* ABrainzlabGameState::GetTargetItem()
{
	for (int32 i = 0; i != itemSpawnPoints.Num(); i++)
	{
		if (itemSpawnPoints[i]->occupied)
		{
			return (itemSpawnPoints[i]);
		}
	}

	return itemSpawnPoints[0];
}

