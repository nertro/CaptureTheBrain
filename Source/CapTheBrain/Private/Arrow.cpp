// Fill out your copyright notice in the Description page of Project Settings.

#include "CapTheBrain.h"
#include "Arrow.h"
#include "EngineUtils.h"


AArrow::AArrow(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	PrimaryActorTick.bCanEverTick = true;
	Capsule = PCIP.CreateDefaultSubobject<UCapsuleComponent>(this, TEXT("CapsuleCollider"));
	Capsule->InitCapsuleSize(10.f, 10.f);
	RootComponent = Capsule;
	MeshComponent = PCIP.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("Mesh"));
	MeshComponent->AttachTo(Capsule);
	MeshComponent->SetRelativeLocation(FVector(-20, -3, -20));
}

void AArrow::Tick(float deltaSeconds)
{
	Super::Tick(deltaSeconds);
	if (!base)
	{
		for (TActorIterator<ABrainBase> ActorItr(GetWorld()); ActorItr; ++ActorItr)
		{
			base = *ActorItr;
		}
	}
	else
	{
		FVector direction = GetActorLocation() - base->GetActorLocation();
		SetActorRotation(direction.Rotation());
	}
}

