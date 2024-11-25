// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCube.h"


// Sets default values
AMyCube::AMyCube()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bHasBeenShotOnce = false;
	fShotScale = 3.0f;
}

AMyCube::AMyCube(float scale)
{
	bHasBeenShotOnce = false;
	fShotScale = scale;
}

// Called when the game starts or when spawned
void AMyCube::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyCube::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool AMyCube::GetHasBeenShotOnce()
{
	return bHasBeenShotOnce;
}

void AMyCube::SetHasBeenShotOnce(bool bValue)
{
	bHasBeenShotOnce = bValue;
}

float AMyCube::GetShotScale()
{
	return fShotScale;
}

