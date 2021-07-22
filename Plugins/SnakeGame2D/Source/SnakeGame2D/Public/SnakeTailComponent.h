// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SnakeTailComponent.generated.h"

UCLASS()
class SNAKEGAME2D_API ASnakeTailComponent : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASnakeTailComponent();
	UPROPERTY()
	FVector2D MyLocation; // Tail Component location on the screen grid
	UFUNCTION()
	void UpdateLocation(const int BoxSize); //  Update snake node tail position 
	protected:

	public:	
	UFUNCTION(BlueprintCallable , Category="")
	FVector2D GetPositionOnScreenGird(); // Get random position in the screen grid
	
};
