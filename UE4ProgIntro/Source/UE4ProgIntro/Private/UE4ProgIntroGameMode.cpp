// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#include "UE4ProgIntro.h"
#include "UE4ProgIntroGameMode.h"
#include "UE4ProgIntroCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "ProgIntroHUD.h"

AUE4ProgIntroGameMode::AUE4ProgIntroGameMode(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/MyCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set the default HUD class
	HUDClass = AProgIntroHUD::StaticClass();

	// base decay rate
	DecayRate = .25f;
}


void AUE4ProgIntroGameMode::Tick(float DeltaSeconds)
{
	AUE4ProgIntroCharacter* MyCharacter = Cast<AUE4ProgIntroCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));

	// if the character still has power
	if (MyCharacter->PowerLevel > 0.05)
	{
		// decrease the characters power
		MyCharacter->PowerLevel = FMath::FInterpTo(MyCharacter->PowerLevel, 0.0f, DeltaSeconds, DecayRate);
	}
	else
	{
		SetCurrentState(EUE4ProgIntroPlayerState::EGameOver);
	}

}

void AUE4ProgIntroGameMode::SetCurrentState(EUE4ProgIntroPlayerState NewState)
{
	CurrentState = NewState;

	HandleNewState(NewState);
}

void AUE4ProgIntroGameMode::HandleNewState(EUE4ProgIntroPlayerState NewState)
{
	switch (NewState)
	{
		// When we're playing, the spawn volumes can spawn
	case EUE4ProgIntroPlayerState::EPlaying:
		for (ASpawnVolume* Volume : SpawnVolumeActors)
		{
			Volume->EnableSpawning();
		}
		break;
		// if the game is over the spawn volumes should deactivate
	case EUE4ProgIntroPlayerState::EGameOver:
	{
		for (ASpawnVolume* Volume : SpawnVolumeActors)
		{
			Volume->DisableSpawning();
		}
		APlayerController* PlayerController = UGameplayStatics::GetPlayerController(this, 0);
		PlayerController->SetCinematicMode(true, true, true);
	}
		break;

	case EUE4ProgIntroPlayerState::EUnknown:
	default:
		// Do nothing
		break;
	}
}

void AUE4ProgIntroGameMode::BeginPlay()
{
	Super::BeginPlay();

	// find all the spawn volume actors
	TArray<AActor*> FoundActors;

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASpawnVolume::StaticClass(), FoundActors);

	for (auto Actor : FoundActors)
	{
		ASpawnVolume* SpawnVolumeActor = Cast<ASpawnVolume>(Actor);
		if (SpawnVolumeActor)
		{
			SpawnVolumeActors.Add(SpawnVolumeActor);
		}
	}

	SetCurrentState(EUE4ProgIntroPlayerState::EPlaying);
}