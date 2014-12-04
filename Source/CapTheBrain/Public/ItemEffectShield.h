// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "ItemEffect.h"
/**
 * 
 */
class CAPTHEBRAIN_API ItemEffectShield : public ItemEffect
{
public:
	ItemEffectShield();
	~ItemEffectShield();

	virtual void Activate(ACapTheBrainCharacter*) override;
	virtual void Deactivate(ACapTheBrainCharacter*) override;
};
