// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include <vector>
#include "CapTheBrainCharacter.h"
#include "ItemEffectSlow.h"
#include "ItemEffectFast.h"
#include "ItemEffectShield.h"
#include "ItemEffectSwap.h"
#include "ItemEffectZapp.h"
#include "BrainBase.h"

/**
 * 
 */
class CAPTHEBRAIN_API ItemManager
{
public:
	static ItemManager* GetInstance()
	{
		if (!instance)
		{
			instance = new ItemManager();
		}

		return instance;
	}

	~ItemManager();

	std::vector<ACapTheBrainCharacter*> players;
	void RemovePlayer(ACapTheBrainCharacter*);
	void SetItem(ACapTheBrainCharacter*);
	void TickEffect(ACapTheBrainCharacter*, float);

private:
	ItemManager();
	static ItemManager* instance;

	float ItemTimerDelay = 5.;
	std::vector<ItemEffect*> itemEffects;
};
