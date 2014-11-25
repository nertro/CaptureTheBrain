// Fill out your copyright notice in the Description page of Project Settings.

#include "CapTheBrain.h"
#include "BrainPickup.h"


ABrainPickup::ABrainPickup(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	MeshComponent = PCIP.CreateDefaultSubobject<USkeletalMeshComponent>(this, TEXT("Mesh"));
	MeshComponent->AttachTo(Capsule);
	MeshComponent->SetRelativeLocation(FVector(0, 0, -20));
	Capsule->SetCapsuleSize(30, 15);
}


void ABrainPickup::AttachToHead(ACapTheBrainCharacter* player)
{
	myPlayer = player;
	RootComponent = MeshComponent;
	if (Capsule->IsActive())
	{
		Capsule->Deactivate();
	}
	this->RootComponent->SnapTo(player->Mesh , "brainSocket");
	GotCollected = true;
}