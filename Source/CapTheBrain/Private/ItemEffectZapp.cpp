// Fill out your copyright notice in the Description page of Project Settings.

#include "CapTheBrain.h"
#include "ItemEffectZapp.h"
#include "CapTheBrainCharacter.h"
#include "ItemManager.h"
#include "BrainPickup.h"

ItemEffectZapp::ItemEffectZapp()
{
}

ItemEffectZapp::~ItemEffectZapp()
{
}

void ItemEffectZapp::Activate(ACapTheBrainCharacter* player)
{
	player->hasItem = false;
	this->ChangeUI(player);
	Zapp(player);
}

void ItemEffectZapp::Deactivate(ACapTheBrainCharacter* player)
{}

void ItemEffectZapp::Zapp(ACapTheBrainCharacter* player)
{
	gameInstance = Cast<UBrainzlapGameInstance>(player->GetGameInstance());
	for (int i = 0; i < gameInstance->players.Num(); i++)
	{
		if (!gameInstance->players[i]->hasShield && gameInstance->players[i]->hasBrain)
		{
			gameInstance->players[i]->GotHit = true;
			gameInstance->playerWithBrain = nullptr;
			gameInstance->players[i]->hasBrain = false;
		}
	}
}
