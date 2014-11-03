// Fill out your copyright notice in the Description page of Project Settings.

#include "CapTheBrain.h"
#include "CollectableItem.h"


ACollectableItem::ACollectableItem(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	Capsule = PCIP.CreateDefaultSubobject<UCapsuleComponent>(this, TEXT("CapsuleCollider"));
	Capsule->InitCapsuleSize(40.f, 70.f);
	Capsule->SetSimulatePhysics(true);
	Capsule->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	Capsule->SetCollisionObjectType(ECollisionChannel::ECC_WorldStatic);
	Capsule->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	RootComponent = Capsule;

	MeshComponent = PCIP.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("Mesh"));
	const ConstructorHelpers::FObjectFinder<UStaticMesh> Mesh(TEXT("StaticMesh'/Game/InteractiveAssets/Item/Item_Object.Item_Object'"));
	StaticMesh = Mesh.Object;
	MeshComponent->SetStaticMesh(StaticMesh);
	MeshComponent->AttachTo(Capsule);
	MeshComponent->SetRelativeLocation(FVector(0, 0, -65));
}

