// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#include "CapTheBrain.h"
#include "CapTheBrainCharacter.h"
#include "EngineUtils.h"

#include "CollectableItem.h"
#include "ItemPickup.h"
#include "BrainPickup.h"
#include "BrainBase.h"
#include "ItemEffect.h"
#include "ActorAdministrator.h"
#include "ItemManager.h"

#define ActorAdmin ActorAdministrator::GetInstance()

//////////////////////////////////////////////////////////////////////////
// ACapTheBrainCharacter

ACapTheBrainCharacter::ACapTheBrainCharacter(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	firstUpdate = true;
	// Set size for collision capsule
	CapsuleComponent->InitCapsuleSize(42.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	CharacterMovement->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	CharacterMovement->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	CharacterMovement->JumpZVelocity = 200.f;
	CharacterMovement->AirControl = 0.2f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = PCIP.CreateDefaultSubobject<USpringArmComponent>(this, TEXT("CameraBoom"));
	CameraBoom->AttachTo(RootComponent);
	CameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = PCIP.CreateDefaultSubobject<UCameraComponent>(this, TEXT("FollowCamera"));
	FollowCamera->AttachTo(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++) 
}

//////////////////////////////////////////////////////////////////////////
// Input

void ACapTheBrainCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	// Set up gameplay key bindings
	check(InputComponent);
	InputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	InputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	InputComponent->BindAction("Fire", IE_Pressed, this, &ACapTheBrainCharacter::UseItem);

	InputComponent->BindAxis("MoveForward", this, &ACapTheBrainCharacter::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &ACapTheBrainCharacter::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	InputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	InputComponent->BindAxis("TurnRate", this, &ACapTheBrainCharacter::TurnAtRate);
	InputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	InputComponent->BindAxis("LookUpRate", this, &ACapTheBrainCharacter::LookUpAtRate);
}

void ACapTheBrainCharacter::BeginPlay()
{
	Super::BeginPlay();
	startPosition = this->GetActorLocation();
	startRotation = this->GetActorRotation();
	APlayerController* ctrler = Cast<APlayerController>(Controller);
	myControllerHUD = Cast<ACharacterHUD>(ctrler->GetHUD());
}

void ACapTheBrainCharacter::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void ACapTheBrainCharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void ACapTheBrainCharacter::MoveForward(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value/SpeedBuffer);

		//Set Animation

		if (hasBrain && ActorAdmin->arrow)
		{
			ActorAdmin->arrow->PointToBase();
		}
	}
}

void ACapTheBrainCharacter::MoveRight(float Value)
{
	if ( (Controller != NULL) && (Value != 0.0f) )
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
	
		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value/SpeedBuffer);

		//Set Animation

		if (hasBrain && ActorAdmin->arrow)
		{
			ActorAdmin->arrow->PointToBase();
		}
	}
}

/**My Stuff */
void ACapTheBrainCharacter::Tick(float deltaSeconds)
{
	Super::Tick(deltaSeconds);

	if (firstUpdate)
	{

		/*for (TActorIterator<ASpawnCtrl>SpawnItr(GetWorld()); SpawnItr; ++SpawnItr)
		{
			if (!spawnCtrl)
			{
				spawnCtrl = *SpawnItr;
			}
		}*/

		ActorAdmin->players.push_back(this);

		firstUpdate = false;
	}

	TickItem(deltaSeconds);
	if (isLoosingBrain)
	{
		if (FellDown)
		{
			GotHit = false;
			SetActorLocation(startPosition);
			SetActorRotation(startRotation);
			FVector acloc = this->GetActorLocation();
			float dist = startPosition.Z - GetActorLocation().Z;
			if (isLoosingBrain && dist <= 100)
			{
				isLoosingBrain = false;
			}
		}
	}
}

void ACapTheBrainCharacter::ReceiveHit(
class UPrimitiveComponent * MyComp,
class AActor * Other,
class UPrimitiveComponent * OtherComp,
	bool bSelfMoved,
	FVector HitLocation,
	FVector HitNormal,
	FVector NormalImpulse,
	const FHitResult & Hit)
{
	if (Other != nullptr)
	{
		if (Other->IsA(ACollectableItem::StaticClass()))
		{
			if (Other->IsA(ABrainPickup::StaticClass()) &! hasBrain)
			{
				this->hasBrain = true;
				if (ActorAdmin->brain->MySpawnPoint)
				{
					ActorAdmin->brain->MySpawnPoint->occupied = false;
				}
				ActorAdmin->spawnCtrl->SpawnBrainBase();
				ActorAdmin->brain->AttachToHead(this);
				SpawnArrow();
			}
			else if (Other->IsA(AItemPickup::StaticClass()) &! hasItem)
			{
				CollectItem();
				AItemPickup* other = (AItemPickup*)Other;
				other->MySpawnPoint->occupied = false;
				Other->Destroy();
			}
			else if (Other->IsA(ABrainBase::StaticClass()) && hasBrain)
			{
				ABrainBase* other = (ABrainBase*)Other;
				other->MySpawnPoint->occupied = false;
				Other->Destroy();
				ActorAdmin->spawnCtrl->SpawnBrain();
				ActorAdmin->spawnCtrl->brainBaseSet = false;

				hasBrain = false;
				score++;
				DestroyArrowPointer();
				ActorAdmin->brain->Destroy();
			}
		}
		else if (Other->IsA(ACapTheBrainCharacter::StaticClass()))
		{
			ACapTheBrainCharacter* other = (ACapTheBrainCharacter*)Other;
			if (hasBrain &! other->isLoosingBrain)
			{
				GotHit = true;
				hasBrain = false;
				other->hasBrain = true;
				ActorAdmin->brain->AttachToHead(other);
				isLoosingBrain = true;
				other->SpawnArrow();
			}
		}
	}
}

void ACapTheBrainCharacter::CollectItem()
{
	ItemManager::GetInstance()->SetItem(this);
}

void ACapTheBrainCharacter::UseItem()
{
	currentItem->Activate(this);
}

void ACapTheBrainCharacter::TickItem(float deltaSeconds)
{
	ItemManager::GetInstance()->TickEffect(this, deltaSeconds);
}

void ACapTheBrainCharacter::SpawnArrow()
{
	if (ArrowBP)
	{
		UWorld* const World = GetWorld();
		AArrow* arrow = (AArrow*)World->SpawnActor(ArrowBP);
		arrow->Capsule->AttachTo(RootComponent);
		arrow->SetActorTransform(this->GetTransform());
		arrow->SetActorRelativeLocation(FVector(0, 0, ArrowZLocation));
		ActorAdmin->arrow = arrow;
	}
}
