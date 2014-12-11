// Fill out your copyright notice in the Description page of Project Settings.

#include "CapTheBrain.h"
#include "AICharacter.h"


AAICharacter::AAICharacter(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	AIControllerClass = ACTBAIController::StaticClass();
}


void AAICharacter::BeginPlay()
{
	ACharacter::BeginPlay();
}

void AAICharacter::ReceiveHit(
class UPrimitiveComponent * MyComp,
class AActor * Other,
class UPrimitiveComponent * OtherComp,
	bool bSelfMoved,
	FVector HitLocation,
	FVector HitNormal,
	FVector NormalImpulse,
	const FHitResult & Hit)
{
	Super::ReceiveHit(MyComp, Other, OtherComp, bSelfMoved, HitLocation, HitNormal, NormalImpulse, Hit);
}