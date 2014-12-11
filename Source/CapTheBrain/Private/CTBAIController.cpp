// Fill out your copyright notice in the Description page of Project Settings.

#include "CapTheBrain.h"
#include "CTBAIController.h"


ACTBAIController::ACTBAIController(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{

}

void ACTBAIController::GetBrain()
{
	MoveToActor(ActorAdministrator::GetInstance()->brain);
}

void ACTBAIController::GoToBase()
{
	MoveToActor(ActorAdministrator::GetInstance()->brainBase);
}

