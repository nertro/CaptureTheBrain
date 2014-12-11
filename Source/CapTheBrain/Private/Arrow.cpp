// Fill out your copyright notice in the Description page of Project Settings.

#include "CapTheBrain.h"
#include "Arrow.h"
#include "ActorAdministrator.h"
#include "EngineUtils.h"


AArrow::AArrow(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	MeshComponent = PCIP.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("Mesh"));
	MeshComponent->SetRelativeLocation(FVector(-20, -3, -20));
	RootComponent = MeshComponent;
}

void AArrow::PointToBase()
{
		FVector direction = GetActorLocation() - ActorAdministrator::GetInstance()->brainBase->GetActorLocation();
		SetActorRotation(direction.Rotation());
}

