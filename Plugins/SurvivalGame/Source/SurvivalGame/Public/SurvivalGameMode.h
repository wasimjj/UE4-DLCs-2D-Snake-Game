// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "SurvivalCharacter.h"
#include "GameFramework/GameModeBase.h"
#include "SurvivalGame/Enemy/Enemy.h"

#include "SurvivalGameMode.generated.h"

/**
 * 
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FNotifyDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEnemyKilledDelegate , AEnemy* , Enemy);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FBOnePermDelegate,bool , bIsLevleCompleted);

USTRUCT(BlueprintType,Blueprintable)
struct FEnemyWaveStruct
{
	GENERATED_BODY()
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite , Category="WaveInfo")
	int TotalEnemy;
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite , Category="WaveInfo")
	int MinDistanceFromPlayer;
	UPROPERTY(EditDefaultsOnly , Category="WaveInfo")
	int MaxDistanceFromPlayer;
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite , Category="WaveInfo")
	float WaveSpeed;
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite , Category="WaveInfo")
	float InitialDelay;
};

UCLASS()
class SURVIVALGAME_API ASurvivalGameMode : public AGameModeBase
{
	GENERATED_BODY()
	virtual void BeginPlay() override;
	public:
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, Category="Game Settings")
	TArray<FEnemyWaveStruct> EnemyWaveList;
	
	UPROPERTY(VisibleAnywhere , BlueprintReadOnly , Category= "Game Rule")
	int EnemiesInWave; // Total Enemies In Wave
	UPROPERTY(VisibleAnywhere , BlueprintReadOnly , Category= "Game Rule")
	int WaveCounter; // Number Of Waves Killd
	UPROPERTY(VisibleAnywhere , BlueprintReadOnly , Category= "Game Rule")
	int CurrentWave = 0; // Current Game Player is killing
	UPROPERTY(VisibleAnywhere , BlueprintReadOnly , Category= "Game Rule")
	int Score = 0;
	UPROPERTY(EditDefaultsOnly , BlueprintReadOnly , Category= "Game Rule")
	int KillWavesToWin = 3;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly , Category="Enemy Spwan")
	TSubclassOf<AEnemy> EnemyPreset;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly , Category="Enemy Spwan")
	TArray<AEnemy*> EnemyPresetPool;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly ,  Category="Player Character")
	ASurvivalCharacter* SurvivalCharacter;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly , Category="Game Mode" )
	class ASurvivalGameMode* SurvivalGameMode;
	UPROPERTY(BlueprintAssignable , Category="Enemy")
	FOnEnemyKilledDelegate OnEnemyKilledDelegate;
	UPROPERTY(BlueprintAssignable , Category="Game End")
	FBOnePermDelegate OnGameEndDelegate;

	UFUNCTION(BlueprintCallable , Category="Enemy")
	void OnEnemyKilled(AEnemy* Enemy);
	UFUNCTION(BlueprintCallable , Category="Enemy")
	void NextWave();
	UFUNCTION(BlueprintCallable, Category="Enemy Spwan")
	void SpawnEnemyWave(int Enemies);
	UFUNCTION(BlueprintCallable , Category="Enemy Pool")
	AEnemy* GetEnemyFromPool();
	UFUNCTION(BlueprintCallable, Category="Enemy Spwan")
	FVector GetEnemyRandomLocation();
};
