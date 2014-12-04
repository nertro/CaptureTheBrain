// Fill out your copyright notice in the Description page of Project Settings.

#include "CapTheBrain.h"
#include "ItemManager.h"

ItemManager* ItemManager::instance = 0;

ItemManager::ItemManager()
{
	itemEffects.push_back(new ItemEffectFast());
	itemEffects.push_back(new ItemEffectSlow());
	itemEffects.push_back(new ItemEffectShield());
	itemEffects.push_back(new ItemEffectSwap());
	itemEffects.push_back(new ItemEffectZapp());
}

ItemManager::~ItemManager()
{
}

void ItemManager::TickEffect(ACapTheBrainCharacter* player, float deltaSeconds)
{
	if (player->isFast)
	{
		player->fastTimer += deltaSeconds;
		if (player->fastTimer >= player->itemTimerDelay)
		{
			player->fastTimer = 0;
			itemEffects[0]->Deactivate(player);
		}
	}
	else if (player->isSlow)
	{
		player->slowTimer += deltaSeconds;
		if (player->slowTimer >= player->itemTimerDelay)
		{
			player->slowTimer = 0;
			itemEffects[1]->Deactivate(player);
		}
	}
	else if (player->hasShield)
	{
		player->shieldTimer += deltaSeconds;
		if (player->shieldTimer >= player->itemTimerDelay)
		{
			player->shieldTimer = 0;
			itemEffects[2]->Deactivate(player);
		}
	}
}

void ItemManager::SetItem(ACapTheBrainCharacter* player)
{
	player->hasItem = true;
	player->myControllerHUD->PlayerHasItem = true;
	FRandomStream* str = new FRandomStream();
	str->GenerateNewSeed();
	int newItem = str->RandRange(0, itemEffects.size() - 1);
	player->currentItem = itemEffects[newItem];
	player->myControllerHUD->currentItem = newItem;
}
