// Fill out your copyright notice in the Description page of Project Settings.

#include "CapTheBrain.h"
#include "BrainPickup.h"
#include "ActorAdministrator.h"


ABrainPickup::ABrainPickup(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	MeshComponent = PCIP.CreateDefaultSubobject<USkeletalMeshComponent>(this, TEXT("Mesh"));
	MeshComponent->AttachTo(Capsule);
	MeshComponent->SetRelativeLocation(FVector(0, 0, -20));
	Capsule->SetCapsuleSize(30, 15);
	ActorAdministrator::GetInstance()->brain = this;
}

//Detach Brain from Base, deactivate CollisionCapsule & Snap Mesh to Player
void ABrainPickup::AttachToHead(ACapTheBrainCharacter* player)
{
	myPlayer = player;
	RootComponent->DetachFromParent();
	RootComponent = MeshComponent;
	if (Capsule->IsActive())
	{
		Capsule->Deactivate();
	}
	this->RootComponent->SnapTo(player->Mesh , "brainSocket");
	GotCollected = true;
}

//Detach from Player, activate collisionCapsule & set mesh local position back to default
void ABrainPickup::DetachFromHead(ACapTheBrainCharacter* player, FVector newLocation)
{
	RootComponent->DetachFromParent();
	GotCollected = false;
	myPlayer = NULL;
	if (!Capsule->IsActive())
	{
		Capsule->Activate();
	}
	RootComponent = Capsule;
	MeshComponent->AttachTo(Capsule);
	MeshComponent->SetRelativeLocation(FVector(0,0,-20));
	SetActorLocation(newLocation);
}