// Fill out your copyright notice in the Description page of Project Settings.


#include "Collider.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
ACollider::ACollider()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	sphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("sphereComponent"));
	sphereComponent->SetupAttachment(GetRootComponent());
	sphereComponent->InitSphereRadius(40.0f);
	sphereComponent->SetCollisionProfileName(TEXT("Pawn"));

	meshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	meshComponent->SetupAttachment(GetRootComponent());

	static ConstructorHelpers::FObjectFinder<UStaticMesh> meshComponentAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));
	if (meshComponentAsset.Succeeded())
	{
		meshComponent->SetStaticMesh(meshComponentAsset.Object);
		meshComponent->SetRelativeLocation(FVector(0.f, 0.f, -40.f));
		meshComponent->SetWorldLocation(FVector(0.8f, 0.8f, 0.8f));
	}

	springArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	springArmComponent->SetupAttachment(GetRootComponent());
	springArmComponent->SetRelativeRotation(FRotator(-45.f, 0.f, 0.f));
	springArmComponent->TargetArmLength = 400.0f;
	springArmComponent->bEnableCameraLag = true;
	springArmComponent->CameraLagSpeed = 3.0f;

	cameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	cameraComponent->SetupAttachment(springArmComponent,USpringArmComponent::SocketName);
	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

// Called when the game starts or when spawned
void ACollider::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACollider::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACollider::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ACollider::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &ACollider::MoveRight);
}
void ACollider::MoveForward(float input)
{
	FVector forward = GetActorForwardVector();

	AddMovementInput(input * forward);
}
void ACollider::MoveRight(float input)
{
	FVector right = GetActorRightVector();

	AddMovementInput(input * right);
}