// Fill out your copyright notice in the Description page of Project Settings.

#include "CapTheBrain.h"
#include "CTBAIController.h"
#include "BrainzlapGameInstance.h"


ACTBAIController::ACTBAIController(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	
}

void ACTBAIController::BeginPlay()
{
	if (Blackboard && BehaviorTree)
	{
		UseBlackboard(Blackboard);
		RunBehaviorTree(BehaviorTree);
	}
}

