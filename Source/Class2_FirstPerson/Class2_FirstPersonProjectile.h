// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Class2_FirstPersonProjectile.generated.h"

class AClass2_FirstPersonPlayerController;
class USphereComponent;
class UProjectileMovementComponent;

UCLASS(config=Game)
class AClass2_FirstPersonProjectile : public AActor
{
	GENERATED_BODY()

	/** Sphere collision component */
	UPROPERTY(VisibleDefaultsOnly, Category=Projectile)
	USphereComponent* CollisionComp;

	/** Projectile movement component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
	UProjectileMovementComponent* ProjectileMovement;

public:
	
	AClass2_FirstPersonProjectile();

	/** called when projectile hits something */
	UFUNCTION(BlueprintCallable)
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	/** Returns CollisionComp subobject **/
	USphereComponent* GetCollisionComp() const { return CollisionComp; }
	/** Returns ProjectileMovement subobject **/
	UProjectileMovementComponent* GetProjectileMovement() const { return ProjectileMovement; }

	void SetOwnPlayer(APlayerController* Player);
	AClass2_FirstPersonPlayerController* GetOwnPlayer() const;

private:
	UPROPERTY(EditAnywhere)
	AClass2_FirstPersonPlayerController* OwnPlayer;
};

