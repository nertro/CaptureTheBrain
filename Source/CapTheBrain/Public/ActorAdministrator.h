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

	std::vector<ACapTheBrainCharacter*> players;
	ASpawnCtrl* spawnCtrl;

	UPROPERTY()
	ABrainPickup* brain;

	UPROPERTY()
	AArrow* arrow;

	UPROPERTY()
	ABrainBase* brainBase;


	std::vector<ASpawnPoint*> itemSpawnPoints;
	std::vector<ASpawnPoint*> brainBases;

	UPROPERTY()
	ASpawnPoint* BrainSpawnPoint;
private:
	static ActorAdministrator* instance;
	ActorAdministrator();
};
