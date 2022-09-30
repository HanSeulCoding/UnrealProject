// Fill out your copyright notice in the Description page of Project Settings.


#include "Critter.h"
#include "Components/StaticMeshComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"

// Sets default values
ACritter::ACritter()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	MeshComponent->SetupAttachment(GetRootComponent());

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(GetRootComponent());
	Camera->SetRelativeLocation(FVector(-300.f, 0.f, 300.f));
	Camera->SetRelativeRotation(FRotator(-45.f, 0.f, 0.f));
	Camera->SetRelativeLocation(FVector(-300.0f, 0.f, 300.f));
	
	AutoPossessPlayer = EAutoReceiveInput::Player0; //Player0는 첫번째 player를 말한다. 
	currentVelocity = FVector(0.f);
	maxSpeed = 300.0f;
}

// Called when the game starts or when spawned
void ACritter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACritter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector newLocation = GetActorLocation() + (currentVelocity * DeltaTime);
	SetActorLocation(newLocation);
}

// Called to bind functionality to input
void ACritter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ACritter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &ACritter::MoveRight);
}

void ACritter::MoveForward(float value)
{
	currentVelocity.X = FMath::Clamp(value, -1.f, 1.f) * maxSpeed; //최소 최대값을 넘지 않을 것이다. value가 음수값 이상으로 확장되지 않도록 한다.

}

void ACritter::MoveRight(float value)
{
	currentVelocity.Y = FMath::Clamp(value, -1.f, 1.f) * maxSpeed;
}
