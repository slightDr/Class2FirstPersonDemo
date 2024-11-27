// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCube.h"


// Sets default values
AMyCube::AMyCube()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bHasBeenShotOnce = false;
	bIsDoubled = false;
	iShotPoints = 100;
	fShotScale = 3.0f;

	InitCubeMesh();
	UE_LOG(LogTemp, Warning, TEXT("mycube init"));
}

AMyCube::AMyCube(int32 shotPoints, float scale)
{
	PrimaryActorTick.bCanEverTick = true;
	bHasBeenShotOnce = false;
	bIsDoubled = false;
	iShotPoints = shotPoints;
	fShotScale = scale;

	InitCubeMesh();
}

// Called when the game starts or when spawned
void AMyCube::BeginPlay()
{
	Super::BeginPlay();
	DoubleShotPoints();
	UE_LOG(LogTemp, Warning, TEXT("mycube beginplay"))
}

// Called every frame
void AMyCube::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyCube::InitCubeMesh()
{
	// 在构造函数中创建该组件
	CubeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CubeMesh"));
	RootComponent = CubeMesh;  // 将该组件设置为根组件

	// 加载StaticMesh并将其应用到 CubeMesh
	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeMeshAsset(TEXT("/Game/LevelPrototyping/Meshes/SM_ChamferCube.SM_ChamferCube"));
	if (CubeMeshAsset.Succeeded())
	{
		CubeMesh->SetStaticMesh(CubeMeshAsset.Object);  // 设置 StaticMesh
	}
	CubeMesh->SetSimulatePhysics(true);
}

bool AMyCube::GetHasBeenShotOnce()
{
	return bHasBeenShotOnce;
}

void AMyCube::SetHasBeenShotOnce(bool bValue)
{
	bHasBeenShotOnce = bValue;
}

int32 AMyCube::GetShotPoints()
{
	return iShotPoints;
}

void AMyCube::SetShotPoints(int32 shotPoints)
{
	iShotPoints = shotPoints;
}

void AMyCube::DoubleShotPoints()
{
	if (FMath::FRand() <= 0.5)
	{
		bIsDoubled = true;
		iShotPoints *= 2;
	}
}

float AMyCube::GetShotScale()
{
	return fShotScale;
}

