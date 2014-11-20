// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/LevelScriptActor.h"

#include "LevelScript.generated.h"

/**
 * 
 */
UCLASS()
class CAPTHEBRAIN_API ALevelScript : public ALevelScriptActor
{
	GENERATED_UCLASS_BODY()

	virtual void BeginPlay() override;
	
};
