// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#include "CapTheBrain.h"
#include "CapTheBrainCharacter.h"
#include "EngineUtils.h"
#include "BrainzlapGameInstance.h"
#include "BrainzlabGameState.h"
#include "CapTheBrainArenaGameMode.h"
#include "CollectableItem.h"
#include "ItemPickup.h"
#include "BrainPickup.h"
#include "BrainBase.h"
#include "ItemEffect.h"
#include "ItemManager.h"

//////////////////////////////////////////////////////////////////////////
// ACapTheBrainCharacter

ACapTheBrainCharacter::ACapTheBrainCharacter(const class FObjectInitializer& PCIP)
	: Super(PCIP)
{
	buff = 100;
	buffTimer = 0;
	buffDelay = 2;
	score = 0;
	firstUpdate = true;
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 200.f;
	GetCharacterMovement()->AirControl = 0.2f;

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++) 
}

//////////////////////////////////////////////////////////////////////////
// Input

void ACapTheBrainCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	// Set up gameplay key bindings
	check(InputComponent);
	InputComponent->BindAction("Jump", IE_Pressed, this, &ACapTheBrainCharacter::StartJump);
	InputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	InputComponent->BindAction("Fire", IE_Pressed, this, &ACapTheBrainCharacter::UseItem);

	InputComponent->BindAction("Buff", IE_Pressed, this, &ACapTheBrainCharacter::UseBuff);
	InputComponent->BindAction("Buff", IE_Released, this, &ACapTheBrainCharacter::ReleaseBuff);

	InputComponent->BindAxis("MoveForward", this, &ACapTheBrainCharacter::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &ACapTheBrainCharacter::MoveRight);

	InputComponent->BindAction("Start", IE_Pressed, this, &ACapTheBrainCharacter::LoadCredits);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	InputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	InputComponent->BindAxis("TurnRate", this, &ACapTheBrainCharacter::TurnAtRate);
	InputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	InputComponent->BindAxis("LookUpRate", this, &ACapTheBrainCharacter::LookUpAtRate);

	score = 0;
}

void ACapTheBrainCharacter::BeginPlay()
{
	Super::BeginPlay();
	gameState = Cast<ABrainzlabGameState>(GetWorld()->GetGameState());
	gameInstance = Cast<UBrainzlapGameInstance>(GetWorld()->GetGameInstance());
	score = 0;
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

		SetArrowDirection();
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

		SetArrowDirection();
	}
}

void ACapTheBrainCharacter::StartJump()
{
	isJumping = true;
}

/**My Stuff */
void ACapTheBrainCharacter::Tick(float deltaSeconds)
{
	Super::Tick(deltaSeconds);

	if (firstUpdate && gameInstance->gameStarted)
	{
		id = gameState->characters.Num();
		gameState->characters.Add(this);
		SpawnArrow();
		won = false;
		if (id == 0 && gameInstance->playerMats.Num() > 0)
		{
			SetMaterial(gameInstance->playerMats[0]);
		}
		if (gameState->characters.Num() == 4)
		{
			Cast<ACapTheBrainArenaGameMode>(GetWorld()->GetAuthGameMode())->SetPlayerStartPositions();
		}
		firstUpdate = false;
	}

	TickItem(deltaSeconds);
	TickBuff(deltaSeconds);
}

void ACapTheBrainCharacter::NotifyHit(
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
			if (Other->IsA(ABrainPickup::StaticClass()) &! hasBrain &! GotHit)
			{
				if (gameState->brain->MySpawnPoint)
				{
					gameState->brain->MySpawnPoint->occupied = false;
				}
				if (!gameState->spawnCtrl->brainBaseSet)
				{
					gameState->spawnCtrl->SpawnBrainBase();
				}
				gameState->brain->AttachToHead(this);
				this->hasBrain = true;
				gameState->playerWithBrain = this;
				gameState->arrows[id]->ChangeMaterial(false, true, false);
				for (int i = 0; i < gameState->characters.Num(); i++)
				{
					if (gameState->characters[i] != this)
					{
						gameState->arrows[i]->ChangeMaterial(true, false, false);
					}
				}
			}
			else if (Other->IsA(AItemPickup::StaticClass()))
			{
				if (!hasItem)
				{
					CollectItem();
					AItemPickup* other = (AItemPickup*)Other;
					other->MySpawnPoint->occupied = false;
				}
				Other->Destroy();
			}
			else if (Other->IsA(ABrainBase::StaticClass()) && hasBrain)
			{
				ABrainBase* other = (ABrainBase*)Other;
				other->MySpawnPoint->occupied = false;
				gameState->DisableActorInScene(other);


				gameState->DisableActorInScene(gameState->brain);
				gameState->spawnCtrl->SpawnBrain();
				gameState->EnableActorInScene(gameState->brain);

				gameState->spawnCtrl->brainBaseSet = false;
				hasBrain = false;
				gameState->playerWithBrain = nullptr;
				for (int i = 0; i < gameState->characters.Num(); i++)
				{
					gameState->arrows[gameState->characters[i]->id]->ChangeMaterial(false, false, true);
				}
				score++;
			}
		}
		else if (Other->IsA(ACapTheBrainCharacter::StaticClass()))
		{
			ACapTheBrainCharacter* other = (ACapTheBrainCharacter*)Other;
			if (hasBrain &! other->GotHit)
			{
				GotHit = true;
				hasBrain = false;
				gameState->playerWithBrain = nullptr;
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
	if (currentItem && hasItem)
	{
		currentItem->Activate(this);
		if (myControllerHUD)
		{
			myControllerHUD->playItemUseSound = true;
		}
	}
}

void ACapTheBrainCharacter::TickItem(float deltaSeconds)
{
	ItemManager::GetInstance()->TickEffect(this, deltaSeconds);
}

void ACapTheBrainCharacter::UseBuff()
{
	if (!usesBuff && buff > 0)
	{
		CharacterMovement->MaxWalkSpeed *= 50;
	}

	usesBuff = true;
}

void ACapTheBrainCharacter::ReleaseBuff()
{
	if (buff > 0 && usesBuff)
	{
		CharacterMovement->MaxWalkSpeed /= 50;
	}

	usesBuff = false;
}

void ACapTheBrainCharacter::TickBuff(float deltaSeconds)
{
	if (myControllerHUD)
	{
		myControllerHUD->UILiquidAmount = (100 - buff) / 100;
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, FString::SanitizeFloat(myControllerHUD->UILiquidAmount));
	}

	if (usesBuff)
	{
		if (buff > 0)
		{
			buff-= 2;
		}
		else
		{
			CharacterMovement->MaxWalkSpeed /= 50;
			usesBuff = false;
		}
	}
	else if (buff < 100)
	{
		buff++;
	}
}

void ACapTheBrainCharacter::SpawnArrow()
{
	if (ArrowBP)
	{
		AArrow* arrow = (AArrow*)GetWorld()->SpawnActor(ArrowBP);
		arrow->MeshComponent->AttachTo(RootComponent);
		arrow->SetActorTransform(this->GetTransform());
		arrow->SetActorRelativeLocation(FVector(0, 0, ArrowZLocation));
		arrow->ChangeMaterial(false, false, true);

		gameState->arrows.Add(arrow);
	}
}

void ACapTheBrainCharacter::SetArrowDirection()
{
	AActor* target = this;
	if (gameState->brain)
	{
		if (!hasBrain &!gameState->brain->GotCollected)
		{
			target = gameState->brain;
		}
		else if (!hasBrain && gameState->brain->GotCollected && gameState->playerWithBrain != nullptr)
		{
			target = gameState->brain;
		}
		else if (hasBrain && gameState->brainBase != nullptr)
		{
			target = gameState->brainBase;
		}
	}
	else
	{
		gameState->playerWithBrain->hasBrain = false;
		gameState->playerWithBrain = nullptr;
		gameState->spawnCtrl->SpawnBrain();
		gameState->spawnCtrl->brainBaseSet = false;
	}

	gameState->arrows[id]->PointToTarget(target);
}


void ACapTheBrainCharacter::LooseBrain()
{
	GotHit = false;
	FellDown = false;
	FVector newBrainPosition = this->GetActorLocation();
	SetActorLocation(startPosition);
	SetActorRotation(startRotation);
	gameState->brain->DetachFromHead(this, newBrainPosition);
	for (int i = 0; i < gameState->characters.Num(); i++)
	{
		gameState->arrows[gameState->characters[i]->id]->ChangeMaterial(false, false, true);
	}
}


void ACapTheBrainCharacter::SetMaterial(UMaterialInterface* newMaterial)
{
	GetMesh()->SetMaterial(0, newMaterial);
}

void ACapTheBrainCharacter::LoadCredits()
{
	if (gameInstance->gameOver)
	{
		gameInstance->loadCredits = true;
	}
}