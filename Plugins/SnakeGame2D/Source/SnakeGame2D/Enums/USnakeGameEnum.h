// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/UserDefinedEnum.h"
#include "USnakeGameEnum.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class EDirection : uint8
{
	EUp 	UMETA(DisplayName = "Up Direction"),
	EDown 	UMETA(DisplayName = "Down Direction"),
	ELeft 	UMETA(DisplayName = "Left Direction"),
	ERight 	UMETA(DisplayName = "Right Direction")
};
UCLASS()
class SNAKEGAME2D_API UUSnakeGameEnum : public UUserDefinedEnum
{
	GENERATED_BODY()
	
};
