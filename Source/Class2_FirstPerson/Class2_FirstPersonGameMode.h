// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Class2_FirstPersonGameMode.generated.h"

UCLASS(minimalapi)
class AClass2_FirstPersonGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float fLimitTime;
	
	AClass2_FirstPersonGameMode();

protected:
	virtual void BeginPlay() override;

private:
	FTimerHandle TimerHandle_GameTimeLimit; // 定义定时器句柄
	// 用于处理时间到的逻辑
	void OnTimeLimitReached() const;
};



