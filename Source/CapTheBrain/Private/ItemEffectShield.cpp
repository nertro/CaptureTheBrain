// Fill out your copyright notice in the Description page of Project Settings.

#include "CapTheBrain.h"
#include "ItemEffectShield.h"
#include "CapTheBrainCharacter.h"

ItemEffectShield::ItemEffectShield()
{
}

ItemEffectShield::~ItemEffectShield()
{
}

void ItemEffectShield::Activate(ACapTheBrainCharacter* player)
{
	player->hasItem = false;
	this->ChangeUI(player);
	player->hasShield = true;
}

void ItemEffectShield::Deactivate(ACapTheBrainCharacter* player)
{
	player->hasShield = false;
}