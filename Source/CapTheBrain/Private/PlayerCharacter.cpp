// Fill out your copyright notice in the Description page of Project Settings.

#include "CapTheBrain.h"
#include "PlayerCharacter.h"


APlayerCharacter::APlayerCharacter(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = PCIP.CreateDefaultSubobject<USpringArmComponent>(this, TEXT("CameraBoom"));
	CameraBoom->AttachTo(RootComponent);
	CameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = PCIP.CreateDefaultSubobject<UCameraComponent>(this, TEXT("FollowCamera"));
	FollowCamera->AttachTo(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm
}


void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	APlayerController* ctrler = Cast<APlayerController>(Controller);
	myControllerHUD = Cast<ACharacterHUD>(ctrler->GetHUD());
}

