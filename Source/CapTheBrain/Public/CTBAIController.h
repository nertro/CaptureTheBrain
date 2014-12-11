// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "ActorAdministrator.h"

#include "CTBAIController.generated.h"

/**
 * 
 */
UCLASS()
class CAPTHEBRAIN_API ACTBAIController : public AAIController
{
	GENERATED_UCLASS_BODY()

	void GetBrain();
	void GetItem(){}
	void ChasePlayer(){}
	void GoToBase();
};
