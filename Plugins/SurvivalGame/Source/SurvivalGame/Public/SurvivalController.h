// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Bullet.h"
#include "SurvivalCharacter.h"
#include "GameFramework/PlayerController.h"
#include "SurvivalController.generated.h"

/**
 * 
 */
UCLASS()
class SURVIVALGAME_API ASurvivalController : public APlayerController
{
	GENERATED_BODY()
	virtual void BeginPlay() override;
	public:
	UPROPERTY(EditDefaultsOnly , BlueprintReadWrite , Category= "Bullet Spawn")
	FVector BulletOffset;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly , Category="Player Charater")
	ASurvivalCharacter* SurvivalCharacter;
	UPROPERTY(EditDefaultsOnly, Category=Projectile)
	TSubclassOf<ABullet> BulletPreset;
	UFUNCTION(BlueprintCallable, Category="Movement")
	void MoveForward(float InputValue);
	UFUNCTION(BlueprintCallable, Category="Movement")
	void MoveRight(float InputValue);
	UFUNCTION(BlueprintCallable, Category="Movement")
	void OnFire();
	
};
