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
	actor->SetActorHiddenInGame(true);
	actor->SetActorEnableCollision(false);
}

