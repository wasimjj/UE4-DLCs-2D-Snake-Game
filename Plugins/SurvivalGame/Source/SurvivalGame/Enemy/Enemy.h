// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/Actor.h"
#include "Enemy.generated.h"

UCLASS()
class SURVIVALGAME_API AEnemy : public AActor
{
	GENERATED_BODY()
public:	
	AEnemy();
public:
	
	virtual void Tick(float DeltaTime) override;
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable , Category= "Player")
	void Initialize(AActor* Character);
	virtual void Initialize_Implementation( AActor* Character);
	
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly , Category="Player")
	AActor* PlayerCharacter;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="MovementSpeed")
	float MoveSpeed = .1f;
	
	UPROPERTY(BlueprintReadOnly , Category="GameMode")
	class ASurvivalGameMode* SurvivalGameMode;
};
