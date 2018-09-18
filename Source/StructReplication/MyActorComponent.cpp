// Fill out your copyright notice in the Description page of Project Settings.

#include "MyActorComponent.h"

#include "Net/UnrealNetwork.h"


// Sets default values for this component's properties
UMyActorComponent::UMyActorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
	bReplicates = true;
}


void UMyActorComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UMyActorComponent, SomeStruct);
}

// Called when the game starts
void UMyActorComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UMyActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UMyActorComponent::OnRep_SomeStruct(FSomeStruct OldStruct)
{
	SomeStructReplicated.Broadcast(SomeStruct, OldStruct);
}

void UMyActorComponent::ServerOverrideStruct_Implementation(FSomeStruct NewStruct)
{
	FSomeStruct OldStruct = SomeStruct;
	SomeStruct = NewStruct;

	//SomeStructReplicated.Broadcast(SomeStruct, OldStruct);

	if (GetNetMode() < ENetMode::NM_Client) // should only execute on listen servers, not so sure about this one though anymore ...
	{
		OnRep_SomeStruct(OldStruct);
	}
}

bool UMyActorComponent::ServerOverrideStruct_Validate(FSomeStruct NewStruct)
{
	return true;
}

