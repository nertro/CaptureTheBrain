// Fill out your copyright notice in the Description page of Project Settings.

#include "CapTheBrain.h"
#include "PlayerCharacter.h"
#include "BrainzlapGameInstance.h"

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

	step = 0.1;
}


void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	if (Controller)
	{
		APlayerController* ctrler = Cast<APlayerController>(Controller);
		myControllerHUD = Cast<ACharacterHUD>(ctrler->GetHUD());
	}
}

void APlayerCharacter::Tick(float deltaSeconds)
{
	Super::Tick(deltaSeconds);

	if (gameInstance->gameOver)
	{
		OrbitCamera();
	}
}

void APlayerCharacter::OrbitCamera()
{
		APlayerController* ctrl = Cast<APlayerController>(Controller);

		if (!ctrl->bCinematicMode)
		{
			ctrl->SetCinematicMode(true, false, false, true, true);
			CameraBoom->TargetArmLength /= 3;
		}

		float radius = CameraBoom->TargetArmLength*2;
		CameraBoom->SetWorldLocation(FVector(GetActorLocation().X + (sinf(step) * radius), GetActorLocation().Y + (cosf(step) * radius), GetActorLocation().Z + 10), true);
		step += 0.01;
		FVector camDirection = GetActorLocation() - FollowCamera->GetComponentLocation();
		camDirection.Z += 40;
		FollowCamera->SetWorldRotation(camDirection.Rotation());
}

