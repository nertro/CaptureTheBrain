

#include "CapTheBrainProto1.h"
#include "Item.h"


AItem::AItem(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	PrimaryActorTick.bCanEverTick = true;

	Capsule = PCIP.CreateDefaultSubobject<UCapsuleComponent>(this, TEXT("CapsuleCollider"));
	Capsule->InitCapsuleSize(40.f, 70.f);
	Capsule->SetSimulatePhysics(true);
	Capsule->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	Capsule->SetCollisionObjectType(ECollisionChannel::ECC_WorldStatic);
	Capsule->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	RootComponent = Capsule;

	MeshComponent = PCIP.CreateDefaultSubobject<USkeletalMeshComponent>(this, TEXT("Mesh"));
	const ConstructorHelpers::FObjectFinder<USkeletalMesh> Mesh(TEXT("SkeletalMesh'/Game/Models/Teddys/Teddy_Jeans'"));
	SkeletalMesh = Mesh.Object; 
	MeshComponent->SetSkeletalMesh(SkeletalMesh);
	MeshComponent->SetAnimationMode(EAnimationMode::AnimationSingleNode);
	/*const ConstructorHelpers::FObjectFinder<UAnimationAsset> MyAnimation(TEXT("AnimationSequence'/Game/Models/Teddys/Teddy_Walk_Die_Hit.Teddy_Walk_Die_Hit'"));
	Animation = MyAnimation.Object;*/
	MeshComponent->SetAnimation(MyAnimation);
	MeshComponent->AttachTo(Capsule);
	MeshComponent->SetRelativeLocation(FVector(0,0, -65));
}

void AItem::BeginPlay()
{
	Super::BeginPlay();
}
