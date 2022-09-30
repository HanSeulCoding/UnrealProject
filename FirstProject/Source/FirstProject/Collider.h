// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Collider.generated.h"

UCLASS()
class FIRSTPROJECT_API ACollider : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACollider();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere, Category = "Mesh")
	class UStaticMeshComponent* meshComponent;

	UPROPERTY(VisibleAnywhere, Category = "Mesh")
	class USphereComponent* sphereComponent;

	UPROPERTY(VisibleAnywhere, Category = "Mesh")
	class UCameraComponent* cameraComponent;

	UPROPERTY(VisibleAnywhere, Category = "Mesh")
	class USpringArmComponent* springArmComponent;
	
	FORCEINLINE UStaticMeshComponent* GetMeshComponent() { return meshComponent; }
	FORCEINLINE void SetMeshComponent(UStaticMeshComponent* mesh) { meshComponent = mesh; }
	FORCEINLINE USphereComponent* GetSphereComponent() { return sphereComponent; }
	FORCEINLINE void SetSphereComponent(USphereComponent* mesh) { sphereComponent = mesh; }

	FORCEINLINE UCameraComponent* GetCameraComponent() { return cameraComponent; }
	FORCEINLINE void SetCameraComponent(UCameraComponent* camera) { cameraComponent = camera; }
	FORCEINLINE USpringArmComponent* GetSpringArmComponent() { return springArmComponent; }
	FORCEINLINE void SetSpringArmComponent(USpringArmComponent* springArm) { springArmComponent = springArm; }

private :

	void MoveForward(float input);
	void MoveRight(float input);
};
