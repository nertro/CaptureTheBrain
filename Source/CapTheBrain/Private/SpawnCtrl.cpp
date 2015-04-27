// Fill out your copyright notice in the Description page of Project Settings.

#include "CapTheBrain.h"
#include "SpawnCtrl.h"
#include "BrainzlabGameState.h"
#include "CollectableItem.h"
#include "SpawnPoint.h"
#include "EngineUtils.h"


ASpawnCtrl::ASpawnCtrl(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	PrimaryActorTick.bCanEverTick = true;
	delay = 4.5f;
	timer = 0;
	brainBaseSet = false;
	beginPlayReady = false;
	currentSpawn = 300;

	gameState = Cast<ABrainzlabGameState>(GetWorld()->GameState);
}

void ASpawnCtrl::BeginPlay()
{
	Super::BeginPlay();

	gameState->spawnCtrl = this;

	beginPlayReady = true;
	this->SpawnBrain();
}

void ASpawnCtrl::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	if (beginPlayReady)
	{
		timer += DeltaSeconds;
		if (timer > delay)
		{
			float pointNo = FMath::FRandRange(0, gameState->itemSpawnPoints.Num());
			int newPoint = (int)pointNo;
			if (!gameState->itemSpawnPoints[newPoint]->occupied)
			{
				gameState->itemSpawnPoints[newPoint]->SpawnNewItem();
			}
			timer = 0;
		}
	}
}

void ASpawnCtrl::SpawnBrain()
{
	gameState->BrainSpawnPoint->SpawnNewBrain();
}

void ASpawnCtrl::SpawnBrainBase()
{
	float pointNo = FMath::FRandRange(0, gameState->brainBases.Num());
	int newPoint = (int)pointNo;
	if (currentSpawn != newPoint)
	{
		currentSpawn = newPoint;
		gameState->brainBases[newPoint]->SpawnNewBase();
		brainBaseSet = true;
	}
	else
	{
		SpawnBrainBase();
	}
}

