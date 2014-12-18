// Fill out your copyright notice in the Description page of Project Settings.

#include "CapTheBrain.h"
#include "ItemEffectSwap.h"
#include "CapTheBrainCharacter.h"
#include "ItemManager.h"
#include "EngineUtils.h"

ItemEffectSwap::ItemEffectSwap()
{
}

ItemEffectSwap::~ItemEffectSwap()
{
}

void ItemEffectSwap::Activate(ACapTheBrainCharacter* player)
{
	player->hasItem = false;
	this->ChangeUI(player);
	SwapBase(player);
}

void ItemEffectSwap::Deactivate(ACapTheBrainCharacter* player)
{
}

void ItemEffectSwap::SwapBase(ACapTheBrainCharacter* player)
{
	gameInstance = Cast<UBrainzlapGameInstance>(player->GetGameInstance());
	if (gameInstance->spawnCtrl->brainBaseSet)
	{
		gameInstance->brainBase->Destroy();
		gameInstance->brainBase = nullptr;
		gameInstance->spawnCtrl->SpawnBrainBase();
	}
}
