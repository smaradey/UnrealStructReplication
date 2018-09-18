// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MyActorComponent.generated.h"


USTRUCT(BlueprintType)
struct FSomeStruct
{
	GENERATED_BODY()
public:

	UPROPERTY(Category = "SomeCategory", BlueprintReadWrite, EditAnywhere, meta = (ClampMin = "0"))
	int32 Health;

	UPROPERTY(Category = "SomeCategory", BlueprintReadWrite, EditAnywhere, meta = (ClampMin = "0"))
	int32 Damage;

	FSomeStruct()
	{
		Health = 0;
		Damage = 0;
	};
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FSomeStructReplicated, FSomeStruct, NewStruct, FSomeStruct, OldStruct);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class STRUCTREPLICATION_API UMyActorComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMyActorComponent();
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	UPROPERTY(ReplicatedUsing = OnRep_SomeStruct, Category = "SomeCategory", BlueprintReadOnly)
	FSomeStruct SomeStruct;

	UFUNCTION()
	virtual void OnRep_SomeStruct(FSomeStruct OldStruct);

public:
	UPROPERTY(BlueprintAssignable, Category = "SomeCategory")
	FSomeStructReplicated SomeStructReplicated;

	UFUNCTION(Server, Reliable, WithValidation, BlueprintCallable, Category = "SomeCategory")
	void ServerOverrideStruct(FSomeStruct NewStruct);
	void ServerOverrideStruct_Implementation(FSomeStruct NewStruct);
	bool ServerOverrideStruct_Validate(FSomeStruct NewStruct);
	
	
};
