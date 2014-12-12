// Fill out your copyright notice in the Description page of Project Settings.

#include "CapTheBrain.h"
#include "SpawnCtrl.h"
#include "BrainzlapGameInstance.h"
#include "CollectableItem.h"
#include "SpawnPoint.h"
#include "EngineUtils.h"

#define GameInstance Cast<UBrainzlapGameInstance>(GetGameInstance())

ASpawnCtrl::ASpawnCtrl(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	PrimaryActorTick.bCanEverTick = true;
	delay = 4.5f;
	timer = 0;
	brainBaseSet = false;
	beginPlayReady = false;
	currentSpawn = 300;
}

void ASpawnCtrl::BeginPlay()
{
	Super::BeginPlay();

	GameInstance->spawnCtrl = this;

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
			float pointNo = FMath::FRandRange(0, GameInstance->itemSpawnPoints.size());
			int newPoint = (int)pointNo;
			if (!GameInstance->itemSpawnPoints[newPoint]->occupied)
			{
				GameInstance->itemSpawnPoints[newPoint]->SpawnNewItem();
			}
			timer = 0;
		}
	}
}

void ASpawnCtrl::SpawnBrain()
{
	GameInstance->BrainSpawnPoint->SpawnNewBrain();
}

void ASpawnCtrl::SpawnBrainBase()
{
	float pointNo = FMath::FRandRange(0, GameInstance->brainBases.size());
	int newPoint = (int)pointNo;
	if (currentSpawn != newPoint)
	{
		currentSpawn = newPoint;
		GameInstance->brainBases[newPoint]->SpawnNewBase();
		brainBaseSet = true;
	}
	else
	{
		SpawnBrainBase();
	}
}

