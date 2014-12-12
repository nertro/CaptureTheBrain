// Fill out your copyright notice in the Description page of Project Settings.

#include "CapTheBrain.h"
#include "CTBAIController.h"
#include "BrainzlapGameInstance.h"


ACTBAIController::ACTBAIController(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{

}

void ACTBAIController::GetBrain()
{
	UBrainzlapGameInstance* gameInstance = Cast<UBrainzlapGameInstance>(GetGameInstance());
	MoveToActor((AActor*)gameInstance->brain);
}

void ACTBAIController::GoToBase()
{
	UBrainzlapGameInstance* gameInstance = Cast<UBrainzlapGameInstance>(GetGameInstance());
	MoveToActor(gameInstance->brainBase);
}

