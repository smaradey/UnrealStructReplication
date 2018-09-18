// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

// Base Includes
#include "CoreMinimal.h"
#include "GameFramework/Character.h"

// Replicated Actor Component
#include "MyActorComponent.h"

// Generated Header File
#include "MyCharacter.generated.h"

UCLASS()
class STRUCTREPLICATION_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	UPROPERTY(Category = "SomeCategory", BlueprintReadOnly)
	UMyActorComponent* ReplicatingActorComponent;
	
};
