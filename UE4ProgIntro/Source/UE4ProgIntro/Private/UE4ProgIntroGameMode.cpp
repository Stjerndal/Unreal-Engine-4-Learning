// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#include "UE4ProgIntro.h"
#include "UE4ProgIntroGameMode.h"
#include "UE4ProgIntroCharacter.h"

AUE4ProgIntroGameMode::AUE4ProgIntroGameMode(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/MyCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
