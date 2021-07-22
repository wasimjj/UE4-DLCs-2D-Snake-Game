// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "SnakeCharacter2D.h"
#include "GameFramework/PlayerController.h"
#include "SnakeController2D.generated.h"

/**
 * 
 */
UCLASS()
class SNAKEGAME2D_API ASnakeController2D : public APlayerController
{
	GENERATED_BODY()
	public:
	UPROPERTY(BlueprintReadOnly , Category="Charater")
	ASnakeCharacter2D* SnakeCharacter2D;
	UFUNCTION(BlueprintCallable , Category="Charater")
	ASnakeCharacter2D* GetSnakeCharacter2D();
	virtual void BeginPlay() override;
	UFUNCTION(BlueprintCallable ,Category= "Delegates")
	void BindDelegates();
	UFUNCTION(BlueprintCallable ,Category= "Input")
	void OnUpKeyPress();
	UFUNCTION(BlueprintCallable ,Category= "Input")
	void OnDownKeyPress();
	UFUNCTION(BlueprintCallable ,Category= "Input")
	void OnLeftKeyPress();
	UFUNCTION(BlueprintCallable ,Category= "Input")
	void OnRightKeyPress();
};
