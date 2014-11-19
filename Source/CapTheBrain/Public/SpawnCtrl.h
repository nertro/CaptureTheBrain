// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include <vector>
#include "SpawnPoint.h"

#include "SpawnCtrl.generated.h"

/**
 * 
 */
UCLASS()
class CAPTHEBRAIN_API ASpawnCtrl : public AActor
{
	GENERATED_UCLASS_BODY()

	virtual void Tick(float)override;

	virtual void BeginPlay()override;

	void SpawnBrain();

	void SpawnBrainBase();

private:
	float delay;
	float timer;
	bool brainBaseSet;
	int currentSpawn;

	std::vector<ASpawnPoint*> itemSpawnPoints;
	std::vector<ASpawnPoint*> brainBases;
	ASpawnPoint* BrainSpawnPoint;
};
