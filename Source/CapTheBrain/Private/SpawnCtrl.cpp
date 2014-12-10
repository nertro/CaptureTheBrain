// Fill out your copyright notice in the Description page of Project Settings.

#include "CapTheBrain.h"
#include "SpawnCtrl.h"

#include "CollectableItem.h"
#include "SpawnPoint.h"
#include "ActorAdministrator.h"
#include "EngineUtils.h"

#define ActorAdmin ActorAdministrator::GetInstance()

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

	ActorAdministrator::GetInstance()->spawnCtrl = this;

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
			float pointNo = FMath::FRandRange(0, ActorAdmin->itemSpawnPoints.size());
			int newPoint = (int)pointNo;
			if (!ActorAdmin->itemSpawnPoints[newPoint]->occupied)
			{
				ActorAdmin->itemSpawnPoints[newPoint]->SpawnNewItem();
			}
			timer = 0;
		}
	}
}

void ASpawnCtrl::SpawnBrain()
{
	ActorAdmin->BrainSpawnPoint->SpawnNewBrain();
}

void ASpawnCtrl::SpawnBrainBase()
{
	float pointNo = FMath::FRandRange(0, ActorAdmin->brainBases.size());
	int newPoint = (int)pointNo;
	if (currentSpawn != newPoint)
	{
		currentSpawn = newPoint;
		ActorAdmin->brainBases[newPoint]->SpawnNewBase();
		brainBaseSet = true;
	}
	else
	{
		SpawnBrainBase();
	}
}

