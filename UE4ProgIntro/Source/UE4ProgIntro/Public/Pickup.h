// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Pickup.generated.h"

/**
 * 
 */
UCLASS()
class UE4PROGINTRO_API APickup : public AActor
{
	GENERATED_BODY()
		
public:

	APickup(const FObjectInitializer& ObjectInitializer);

	// True when the pickup is able to be picked up, false if something deactivates the pickup.
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bIsActive;
	
	// Simple collision primitive to use as the root component.
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly)
	class USphereComponent* BaseCollisionComponent;

	// StaticMeshComponent to represent the pickup in the level.
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly)
	class UStaticMeshComponent* PickupMesh;

	// Function to call when the Pickup is collected.
	UFUNCTION(BlueprintNativeEvent)
		void OnPickedUp();
};
