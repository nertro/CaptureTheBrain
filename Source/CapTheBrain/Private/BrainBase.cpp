// Fill out your copyright notice in the Description page of Project Settings.

#include "CapTheBrain.h"
#include "BrainBase.h"


ABrainBase::ABrainBase(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	MeshComponent = PCIP.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("Mesh"));
	MeshComponent->AttachTo(Capsule);
	MeshComponent->SetRelativeLocation(FVector(0, 0, -65));
}


