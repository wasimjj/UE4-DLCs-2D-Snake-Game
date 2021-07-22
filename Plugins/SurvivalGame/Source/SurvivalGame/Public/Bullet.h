// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/SphereComponent.h"

#include "Bullet.generated.h"

UCLASS()
class SURVIVALGAME_API ABullet : public AActor
{
	GENERATED_BODY()
	UPROPERTY(EditDefaultsOnly, Category=Projectile)
	class USphereComponent* CollisionComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
	class UProjectileMovementComponent* ProjectileMovement;

public:	
	ABullet();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable , Category="Bullet Hit")
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
	virtual void OnHit_Implementation(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
	FORCEINLINE class USphereComponent* GetCollisionComp() const { return CollisionComp; }
	FORCEINLINE class UProjectileMovementComponent* GetProjectileMovement() const { return ProjectileMovement; }

	UPROPERTY(EditDefaultsOnly , BlueprintReadOnly , Category="Velocity")
	float InitialSpeed = 5000;
	UPROPERTY(EditDefaultsOnly , BlueprintReadOnly , Category="Velocity")
	float MaxSpeed = 5000;
	UPROPERTY(EditDefaultsOnly , BlueprintReadOnly , Category="Life Time")
	float LifeSpan = 3.5f;
};
