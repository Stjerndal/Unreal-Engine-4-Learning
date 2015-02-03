// Fill out your copyright notice in the Description page of Project Settings.

#include "UE4ProgIntro.h"
#include "Pickup.h"


APickup::APickup(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	// The pickup is valid when it is created.
	bIsActive = true;

	// Create the root SphereComponent to handle the pickup's collision
	BaseCollisionComponent = ObjectInitializer.CreateDefaultSubobject<USphereComponent>(this, TEXT("BaseSphereComponent"));

	// Set the SphereComponent as the root component.
	RootComponent = BaseCollisionComponent;

	//Create the static mesh component
	PickupMesh = ObjectInitializer.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("PickupMesh"));

	// Turn physics on for the static mesh.
	PickupMesh->SetSimulatePhysics(true);

	//attach the static mesh component to the root component
	PickupMesh->AttachTo(RootComponent);

}


void APickup::OnPickedUp_Implementation()	//<--this is a Blueprint Native event, so we need to add _Implementation
{
	//there is no default behavior for a pickup when its picked up.
}

