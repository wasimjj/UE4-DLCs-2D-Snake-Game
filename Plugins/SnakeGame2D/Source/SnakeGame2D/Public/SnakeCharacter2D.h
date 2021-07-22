// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "SnackGameMode2D.h"
#include "SnakeTailComponent.h"
#include "SnakeGame2D/Enums/USnakeGameEnum.h"
#include "Containers/List.h"
#include "SnakeCharacter2D.generated.h"

/**
 * 
 */
UCLASS()
class SNAKEGAME2D_API ASnakeCharacter2D : public APaperCharacter
{
	GENERATED_BODY()
	virtual void BeginPlay() override;
	

	UPROPERTY()
	EDirection CurrentDirection; 
	UPROPERTY()
	ASnakeTailComponent* CurrentNodeToPick;
	UPROPERTY(EditDefaultsOnly , Category= "Snale Tail")
	TSubclassOf<ASnakeTailComponent> TailNode;
	TDoubleLinkedList<ASnakeTailComponent*> SnakeTail; 

	void AddNodeToTail();
	UFUNCTION(BlueprintCallable , Category="Pick Node")
	bool CheckIfNodePickAble();
	UFUNCTION(BlueprintCallable , Category="Snake Killed")
	bool IsSnakeOutOfBound() const ;
	UFUNCTION(BlueprintCallable , Category="Snake Killed")
	void CheckIfSnakeCanDie();
	public:

	UFUNCTION()
	void MoveSnakeOneStep();
	UFUNCTION()
	void UpdateDirection(EDirection Direction);
	public:

	UPROPERTY(BlueprintReadOnly , Category="GameMode")
	ASnackGameMode2D * SnackGameMode; // get reference of game mode for game rules 
	UPROPERTY(BlueprintAssignable)
	FNotifyDelegate OnNodePicked; // Trigger delegate  when node chased or picked 
	UPROPERTY(BlueprintAssignable)
	FNotifyDelegate OnSnakeKilled; // Trigger when player get killed 
	UPROPERTY(EditDefaultsOnly, Category="Snake Speed")
	float SnakeSpeed = 0.5f;
	UPROPERTY(BlueprintReadOnly , Category="Location")
	int RowOfhHead; // track snake position row number 
	UPROPERTY(BlueprintReadOnly , Category="Location")
	int ColumnOfhHead;// track snake position column number 
	UFUNCTION(BlueprintCallable , Category="Location")
	void UpdateLocation(); //  update location 
	UFUNCTION(BlueprintCallable , Category="Movement")
	void StartMovement(); // start snake movement after game start 
	UPROPERTY(BlueprintReadOnly , Category="Movement")
	bool bIsSkipStep; // If Player Press Input to change Directions Skip one Auto Step to Avoid double step

	UFUNCTION(BlueprintCallable , Category="Movement")
	EDirection GetDirection(); // Get snake current direction 
	UFUNCTION(BlueprintCallable , Category="Movement")
	int GetMoveStepSize(); // Get move step size 
	UFUNCTION(BlueprintCallable , Category="Movement")
	bool IsNodePickAble(ASnakeTailComponent* SnakeTailNode); // check if node id chased 
	UFUNCTION(BlueprintCallable , Category="Snake Tail Node")
	void OnSpawnNewNode(ASnakeTailComponent* SnakeTailNode); // spawn new node after chased first one 
	void BindDelegates(); // bind delegates 
	void UnBindDelegates(); // unbind delegates 
	UFUNCTION(BlueprintCallable , Category="Game End")
	void OnGameEnd(); // on game end 
	
};
