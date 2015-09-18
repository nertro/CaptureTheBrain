// Fill out your copyright notice in the Description page of Project Settings.

#include "CapTheBrain.h"
#include "CTBAIController.h"
#include "BrainzlapGameInstance.h"
#include "BrainzlabPathFollowingComponent.h"


ACTBAIController::ACTBAIController(const class FObjectInitializer& PCIP)
	: Super(PCIP.SetDefaultSubobjectClass<UBrainzlabPathFollowingComponent>(TEXT("PathFollowingComponent")))
{
	bWantsPlayerState = true;
}

//void ACTBAIController::BeginPlay()
//{
//	//if (MyBlackboard && BehaviorTree)
//	//{
//	//	//UseBlackboard(MyBlackboard);
//	//	UseBlackboard(MyBlackboard, Blackboard);
//	//	RunBehaviorTree(BehaviorTree);
//	//}
//}
//
//void ACTBAIController::OnPosses()
//{
//	Super::OnPossess(GetPawn());
//
//	if (MyBlackboard && BehaviorTree)
//	{
//		//UseBlackboard(MyBlackboard);
//		UseBlackboard(MyBlackboard, Blackboard);
//		RunBehaviorTree(BehaviorTree);
//	}
//}

