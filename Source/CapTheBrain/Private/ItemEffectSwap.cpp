// Fill out your copyright notice in the Description page of Project Settings.

#include "CapTheBrain.h"
#include "ItemEffectSwap.h"
#include "CapTheBrainCharacter.h"
#include "ItemManager.h"
#include "BrainzlabGameState.h"
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
	ABrainzlabGameState* gameState = Cast<ABrainzlabGameState>(player->GetWorld()->GetGameState());
	if (gameState->spawnCtrl->brainBaseSet)
	{
		gameState->brainBase->Destroy();
		gameState->brainBase = nullptr;
		gameState->spawnCtrl->SpawnBrainBase();
	}
}
