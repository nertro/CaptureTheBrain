// Fill out your copyright notice in the Description page of Project Settings.

#include "CapTheBrain.h"
#include "ItemEffectSlow.h"
#include "ItemManager.h"

ItemEffectSlow::ItemEffectSlow()
{
}

ItemEffectSlow::~ItemEffectSlow()
{
}

void ItemEffectSlow::Activate(ACapTheBrainCharacter* player)
{
	player->hasItem = false;
	this->ChangeUI(player);
	this->ChangeSpeed(player, 10, true);
}

void ItemEffectSlow::Deactivate(ACapTheBrainCharacter* player)
{
	this->ResetSpeed(player, 10);
}