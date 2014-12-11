// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "BrainPickup.h"
#include "Arrow.h"
#include "BrainBase.h"
#include "CapTheBrainCharacter.h"
#include "SpawnCtrl.h"
#include <vector>
/**
 * 
 */
class CAPTHEBRAIN_API ActorAdministrator
{
public:
	static ActorAdministrator* GetInstance()
	{
		if (!instance)
		{
			instance = new ActorAdministrator();
		}
		return instance;
	}

	~ActorAdministrator();

	UPROPERTY()
	std::vector<ACapTheBrainCharacter*> players;

	UPROPERTY()
	ASpawnCtrl* spawnCtrl;

	UPROPERTY()
	ABrainPickup* brain;

	UPROPERTY()
	AArrow* arrow;

	UPROPERTY()
	ABrainBase* brainBase;

	UPROPERTY()
	std::vector<ASpawnPoint*> itemSpawnPoints;

	UPROPERTY()
	std::vector<ASpawnPoint*> brainBases;

	UPROPERTY()
	ASpawnPoint* BrainSpawnPoint;
private:
	static ActorAdministrator* instance;
	ActorAdministrator();
};
