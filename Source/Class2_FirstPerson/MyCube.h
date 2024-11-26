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
	AMyCube(int32 shotPoints, float scale);

protected:
	// 方块的网格体组件
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* CubeMesh;
	
	// 是否已经被射中过
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bHasBeenShotOnce;

	// 是否双倍
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsDoubled;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 iShotPoints;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float fShotScale;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void InitCubeMesh();

	// Getter
	UFUNCTION(BlueprintCallable)
	bool GetHasBeenShotOnce();

	// Setter
	UFUNCTION(BlueprintCallable)
	void SetHasBeenShotOnce(bool bValue);

	UFUNCTION(BlueprintCallable)
	float GetShotScale();

	UFUNCTION(BlueprintCallable)
	int32 GetShotPoints();

	UFUNCTION(BlueprintCallable)
	void SetShotPoints(int32 shotPoints);
	
	UFUNCTION(BlueprintCallable)
    void DoubleShotPoints();
};
