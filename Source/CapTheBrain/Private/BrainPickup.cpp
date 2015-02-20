// Fill out your copyright notice in the Description page of Project Settings.

#include "CapTheBrain.h"
#include "BrainPickup.h"


ABrainPickup::ABrainPickup(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	MeshComponent = PCIP.CreateDefaultSubobject<USkeletalMeshComponent>(this, TEXT("Mesh"));
	MeshComponent->AttachTo(Capsule);
	MeshComponent->SetRelativeLocation(FVector(0, 0, -20));
	Capsule->SetCapsuleSize(50, 15);
}

//Detach Brain from Base, deactivate CollisionCapsule & Snap Mesh to Player
void ABrainPickup::AttachToHead(ACapTheBrainCharacter* player)
{
	Capsule->SetSimulatePhysics(false);
	myPlayer = player;
	RootComponent->DetachFromParent();
	RootComponent = MeshComponent;
	Capsule->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	MeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	this->RootComponent->SnapTo(player->Mesh , "brainSocket");
	GotCollected = true;
}

//Detach from Player, activate collisionCapsule & set mesh local position back to default
void ABrainPickup::DetachFromHead(ACapTheBrainCharacter* player, FVector newLocation)
{
	RootComponent->DetachFromParent();
	GotCollected = false;
	myPlayer = nullptr;
	if (!Capsule->IsActive())
	{
		Capsule->Activate();
	}
	Capsule->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	RootComponent = Capsule;
	MeshComponent->AttachTo(Capsule);
	
	MeshComponent->SetRelativeLocation(FVector(0,0,-20));

	newLocation.Z = newLocation.Z - player->CapsuleComponent->GetUnscaledCapsuleHalfHeight();
	SetActorLocation(newLocation);
}