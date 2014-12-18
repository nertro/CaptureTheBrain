// Fill out your copyright notice in the Description page of Project Settings.

#include "CapTheBrain.h"
#include "CTBAIController.h"
#include "BrainzlapGameInstance.h"
#include "BrainzlabPathFollowingComponent.h"


ACTBAIController::ACTBAIController(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP.SetDefaultSubobjectClass<UBrainzlabPathFollowingComponent>(TEXT("PathFollowingComponent")))
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

