// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "ItemEffect.h"
#include "CapTheBrainCharacter.h"
/**
 * 
 */
class CAPTHEBRAIN_API ItemEffectSlow : public ItemEffect
{
public:
	ItemEffectSlow();
	~ItemEffectSlow();

	virtual void Activate(ACapTheBrainCharacter*) override;
	virtual void Deactivate(ACapTheBrainCharacter*) override;
};
