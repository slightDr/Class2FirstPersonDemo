// Copyright Epic Games, Inc. All Rights Reserved.

#include "Class2_FirstPersonGameMode.h"
#include "Class2_FirstPersonCharacter.h"
#include "UObject/ConstructorHelpers.h"

AClass2_FirstPersonGameMode::AClass2_FirstPersonGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
