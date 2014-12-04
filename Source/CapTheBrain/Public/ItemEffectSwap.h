// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "ItemEffect.h"
/**
 * 
 */
class CAPTHEBRAIN_API ItemEffectSwap : public ItemEffect
{
public:
	ItemEffectSwap();
	~ItemEffectSwap();

	virtual void Activate(ACapTheBrainCharacter*) override;
	virtual void Deactivate(ACapTheBrainCharacter*) override;

private:
	void SwapBase(ACapTheBrainCharacter*);
};