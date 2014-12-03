// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "ItemEffect.h"
/**
 * 
 */
class CAPTHEBRAIN_API ItemEffectZapp : public ItemEffect
{
public:
	ItemEffectZapp();
	~ItemEffectZapp();

	virtual void Activate(ACapTheBrainCharacter*) override;
	virtual void Deactivate(ACapTheBrainCharacter*) override;

private:
	void Zapp(ACapTheBrainCharacter*);
};