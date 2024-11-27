// Copyright Epic Games, Inc. All Rights Reserved.

#include "Class2_FirstPersonGameMode.h"

AClass2_FirstPersonGameMode::AClass2_FirstPersonGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	fLimitTime = 10.0f;
	iDoubleNum = 1;
	UE_LOG(LogTemp, Warning, TEXT("gamemode init"))
}

void AClass2_FirstPersonGameMode::BeginPlay()
{
	UE_LOG(LogTemp, Warning, TEXT("gamemode beginplay"))
	Super::BeginPlay();
	
	// 设置一个计时器，限定时间到时调用 OnTimeLimitReached
	if (fLimitTime > 0)
	{
		GetWorld()->GetTimerManager().SetTimer(
			TimerHandle_GameTimeLimit,
			this,
			&AClass2_FirstPersonGameMode::OnTimeLimitReached,
			fLimitTime,
			false
		);
	}

	GetWorld()->GetTimerManager().SetTimer(
		TimerHandle_CubeDoubleTime,
		this,
		&AClass2_FirstPersonGameMode::SetSomeDoubleCubes,
		1.0f,
		false
	);
}

void AClass2_FirstPersonGameMode::OnTimeLimitReached() const
{
	UE_LOG(LogTemp, Warning, TEXT("Time limit reached! Ending game."));
	// 停止游戏或其他逻辑
	if (APlayerController* PC = GetWorld()->GetFirstPlayerController())
	{
		PC->SetPause(true); // 暂停游戏
	}
}

void AClass2_FirstPersonGameMode::SetSomeDoubleCubes() const
{
	// 获取所有种类为AMyCube的actor
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AMyCube::StaticClass(), FoundActors);

	// 处理越界问题
	if (FoundActors.Num() < iDoubleNum)  
	{
		UE_LOG(LogTemp, Warning, TEXT("double too much, Cubes %d, double %d"), FoundActors.Num(), iDoubleNum);
		return;
	}

	// 随机取iDoubleNum个双倍积分
	for (int32 i = 0; i < iDoubleNum; ++ i)  
	{
		int32 idx = FMath::RandRange(0, FoundActors.Num() - 1);
		AMyCube* cube = Cast<AMyCube>(FoundActors[idx]);
		if (!cube)
			continue;

		cube->DoubleShotPoints();
		UE_LOG(LogTemp, Warning, TEXT("cube name %s double, points: %d"), *cube->GetName(), cube->GetShotPoints());
		FoundActors.RemoveAt(idx);
	}
}
