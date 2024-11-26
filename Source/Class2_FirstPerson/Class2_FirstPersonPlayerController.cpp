// Copyright Epic Games, Inc. All Rights Reserved.


#include "Class2_FirstPersonPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"

void AClass2_FirstPersonPlayerController::AddPoints(int32 add)
{
	iPoints += add;
	// GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, "Points: %i", iPoints);
	UE_LOG(LogTemp, Warning, TEXT("Points: %d"), iPoints);
}

void AClass2_FirstPersonPlayerController::BeginPlay()
{
	Super::BeginPlay();

	iPoints = 0;

	// get the enhanced input subsystem
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		// add the mapping context so we get controls
		Subsystem->AddMappingContext(InputMappingContext, 0);
	}
}
