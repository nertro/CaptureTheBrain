// Fill out your copyright notice in the Description page of Project Settings.

#include "CapTheBrain.h"
#include "AICharacter.h"
#include "BrainzlapGameInstance.h"


AAICharacter::AAICharacter(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	AIControllerClass = ACTBAIController::StaticClass();
}


void AAICharacter::BeginPlay()
{
	Super::BeginPlay();
}

void AAICharacter::Tick(float deltaSeconds)
{
	Super::Tick(deltaSeconds);

	ACTBAIController* ctrl = Cast<ACTBAIController>(Controller);
	if (ctrl->GetMoveStatus() == EPathFollowingStatus::Idle)
	{
		MoveForward(40);
		if (hasBrain)
		{
			ctrl->GoToBase();
		}
		else if (!hasBrain && gameInstance->brainBase == nullptr)
		{
			ctrl->GetBrain();
		}
		else
		{
			ctrl->GoToBase();
		}
	}
}
