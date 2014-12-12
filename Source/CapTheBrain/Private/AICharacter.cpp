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
	 
}

bool AAICharacter::GetHasBrain()
{
	return hasBrain;
}
