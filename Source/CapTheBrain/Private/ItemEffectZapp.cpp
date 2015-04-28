// Fill out your copyright notice in the Description page of Project Settings.

#include "CapTheBrain.h"
#include "ItemEffectZapp.h"
#include "CapTheBrainCharacter.h"
#include "BrainzlabGameState.h"
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
	ABrainzlabGameState* gameState = Cast<ABrainzlabGameState>(player->GetWorld()->GetGameState());
	for (int i = 0; i < gameState->characters.Num(); i++)
	{
		if (!gameState->characters[i]->hasShield && gameState->characters[i]->hasBrain && gameState->characters[i] != player)
		{	 
			gameState->characters[i]->GotHit = true;
			gameState->playerWithBrain = nullptr;
			gameState->characters[i]->hasBrain = false;
		}
	}
}
