// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Class2_FirstPersonPlayerController.generated.h"

class UInputMappingContext;

/**
 *
 */
UCLASS()
class CLASS2_FIRSTPERSON_API AClass2_FirstPersonPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:

	/** Input Mapping Context to be used for player input */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputMappingContext* InputMappingContext;

	// Begin Actor interface
protected:

	virtual void BeginPlay() override;

	void InitializeGameVariables();

	void SetGameTimer();

	// End Actor interface
};
