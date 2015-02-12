// Fill out your copyright notice in the Description page of Project Settings.

#include "CapTheBrain.h"
#include "Arrow.h"
#include "EngineUtils.h"
#include "CapTheBrainCharacter.h"


AArrow::AArrow(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	MeshComponent = PCIP.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("Mesh"));
	MeshComponent->SetRelativeLocation(FVector(-20, -3, -20));
	RootComponent = MeshComponent;
}

void AArrow::PointToTarget(AActor* target)
{
	FVector direction = GetActorLocation() - target->GetActorLocation();
	SetActorRotation(direction.Rotation());
}

