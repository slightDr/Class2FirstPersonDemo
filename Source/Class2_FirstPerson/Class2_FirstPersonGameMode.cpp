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

	fLimitTime = 10.0f;
}

void AClass2_FirstPersonGameMode::BeginPlay()
{
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
