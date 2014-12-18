// Fill out your copyright notice in the Description page of Project Settings.

#include "CapTheBrain.h"
#include "Arrow.h"
#include "BrainzlapGameInstance.h"
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
	UBrainzlapGameInstance* instance = Cast<UBrainzlapGameInstance>(GetGameInstance());
	FVector direction = GetActorLocation() - instance->brainBase->GetActorLocation();
	SetActorRotation(direction.Rotation());
}

