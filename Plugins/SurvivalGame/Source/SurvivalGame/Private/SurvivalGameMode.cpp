// Fill out your copyright notice in the Description page of Project Settings.


#include "SurvivalGameMode.h"
#include "Kismet/GameplayStatics.h"

void ASurvivalGameMode::BeginPlay()
{
	Super::BeginPlay();
	SurvivalCharacter = Cast<ASurvivalCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(),0));
	OnEnemyKilledDelegate.AddDynamic(this,&ASurvivalGameMode::OnEnemyKilled);
	
	if(EnemyWaveList.Num() > 0)
	{
		NextWave();
	}
}

void ASurvivalGameMode::OnEnemyKilled(AEnemy* Enemy)
{
	EnemyPresetPool.Add(Enemy);
	EnemiesInWave--;
	Score++;
	if(EnemiesInWave <= 0)
	{
		if(++CurrentWave < EnemyWaveList.Num())
		{
			KillWavesToWin++;
			NextWave();
		}else
		{
			OnGameEndDelegate.Broadcast(true);
		}
	}
	GLog->Log(FString::Printf(TEXT("Enemy Get Killed..:::EnemiesInWave ::: %d ::: CurrentWave:::%d "),EnemiesInWave,CurrentWave));
}
void ASurvivalGameMode::NextWave()
{
	EnemiesInWave = EnemyWaveList[CurrentWave].TotalEnemy;
	FTimerDelegate TimerDel;
	TimerDel.BindUFunction(this, FName("SpawnEnemyWave") ,EnemyWaveList[CurrentWave].TotalEnemy);
	FTimerHandle TimerHandle;
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, TimerDel, EnemyWaveList[CurrentWave].InitialDelay, false);
}

void ASurvivalGameMode::SpawnEnemyWave(int Enemies)
{
	if(EnemyPreset != nullptr && SurvivalCharacter != nullptr)
	{
		for(int Index = 0 ; Index < Enemies ; Index++)
		{
			AEnemy* Enemy = GetEnemyFromPool();
			Enemy->Initialize(SurvivalCharacter);
		}
	}
}

AEnemy* ASurvivalGameMode::GetEnemyFromPool()
{
	if(EnemyPresetPool.Num() > 0)
	{
		AEnemy* Enemy = EnemyPresetPool[0];
		Enemy->SetActorLocation(GetEnemyRandomLocation());
		EnemyPresetPool.RemoveAtSwap(0);
		return Enemy;
	}
	
	return  GetWorld()->SpawnActor<AEnemy>(EnemyPreset,GetEnemyRandomLocation(),FRotator::ZeroRotator);
	
}

FVector ASurvivalGameMode::GetEnemyRandomLocation()
{
	FVector Location = SurvivalCharacter->GetActorLocation();
	
	if(SurvivalCharacter != nullptr)
	{
		Location.Y += FMath::RandRange(EnemyWaveList[CurrentWave].MinDistanceFromPlayer , EnemyWaveList[CurrentWave].MaxDistanceFromPlayer);
		Location.X += FMath::RandRange(EnemyWaveList[CurrentWave].MinDistanceFromPlayer , EnemyWaveList[CurrentWave].MaxDistanceFromPlayer); 
	
	}
	return Location;
}
