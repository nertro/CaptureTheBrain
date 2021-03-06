// Fill out your copyright notice in the Description page of Project Settings.

#include "CapTheBrain.h"
#include "CollectableItem.h"
#include "BrainzlabGameState.h"


ACollectableItem::ACollectableItem(const class FObjectInitializer& PCIP)
	: Super(PCIP)
{
	Capsule = PCIP.CreateDefaultSubobject<UCapsuleComponent>(this, TEXT("CapsuleCollider"));
	Capsule->InitCapsuleSize(40.f, 70.f);
	Capsule->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	Capsule->SetCollisionObjectType(ECollisionChannel::ECC_WorldStatic);
	Capsule->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	RootComponent = Capsule;
}

void ACollectableItem::BeginPlay()
{
	gameState = Cast<ABrainzlabGameState>(GetWorld()->GetGameState());
}