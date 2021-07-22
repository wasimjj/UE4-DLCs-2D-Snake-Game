// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SnakeTailComponent.h"
#include "SnackGameMode2D.generated.h"

/**
 * 
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSpawnNewNode, ASnakeTailComponent* , SnakeTailNode);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FNotifyDelegate);
UCLASS()
class SNAKEGAME2D_API ASnackGameMode2D : public AGameModeBase
{
	GENERATED_BODY()
	virtual void BeginPlay() override;
	UFUNCTION()
	void OnNodePicked();
	public:
	
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly , Category=" Game Rule")
	int BoxSize = 16; // Screen divided in grid and its one cell size 
	UPROPERTY(VisibleAnywhere ,BlueprintReadOnly, Category=" Game Rule")
	int ScreenRows = 32; // Screen divided in grid and its one cell in rows
	UPROPERTY(VisibleAnywhere ,BlueprintReadOnly ,Category=" Game Rule")
	int ScreenColumn = 32; // Screen divided in grid and its one cell in columns
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Game Rule")
	float GameSpeed = .25f; // Default snake move speed
	UPROPERTY(VisibleAnywhere , BlueprintReadOnly , Category= "Game Rule")
	int Score = 0; // number of nodes eaten or chased 
	UPROPERTY(EditDefaultsOnly , Category="Snake Tail")
	TSubclassOf<ASnakeTailComponent> SnakeTailNode; // Snake tail preset
	UPROPERTY(BlueprintAssignable , Category="Snake Tail")
	FOnSpawnNewNode OnSpawnNewNode; // Delegate when node is spwan 
	
	UFUNCTION(BlueprintCallable , Category="Snake Tail")
	void SpawnSnakeNode(); // spawn snake node at random position 
	UFUNCTION(BlueprintCallable , Category="Grid Rule")
	FVector GetNextGridPosition() const; // get random grid position 
	UPROPERTY(BlueprintAssignable , Category="Snake Game End")
	FNotifyDelegate OnGameEndDelegate; // Trigger Game End Delegate to show game end menu
	UFUNCTION(BlueprintCallable , Category="Snake Game End")
	void GameEnd();
};
