// Fill out your copyright notice in the Description page of Project Settings.

#include "CapTheBrain.h"
#include "ItemEffectFast.h"

ItemEffectFast::ItemEffectFast()
{
}

ItemEffectFast::~ItemEffectFast()
{
}

void ItemEffectFast::Activate(ACapTheBrainCharacter* player)
{
	this->ChangeUI(player);
	this->ChangeSpeed(player, .1, false);
}

void ItemEffectFast::Deactivate(ACapTheBrainCharacter* player)
{
	this->ChangeSpeed(player, 10, false);
}
