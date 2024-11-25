// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyCube.generated.h"

UCLASS()
class CLASS2_FIRSTPERSON_API AMyCube : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyCube();
	AMyCube(float scale);

protected:
	// 是否已经被射中过
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	bool bHasBeenShotOnce;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	float fShotScale;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	// Getter
	UFUNCTION(BlueprintCallable, Category = "Gameplay")
	bool GetHasBeenShotOnce();

	// Setter
	UFUNCTION(BlueprintCallable, Category = "Gameplay")
	void SetHasBeenShotOnce(bool bValue);

	UFUNCTION(BlueprintCallable, Category = "Gameplay")
	float GetShotScale();
};
