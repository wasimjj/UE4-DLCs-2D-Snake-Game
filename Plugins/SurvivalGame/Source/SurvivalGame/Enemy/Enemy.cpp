// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"

// Sets default values
AEnemy::AEnemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}
// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if(PlayerCharacter!= nullptr)
	{
		SetActorLocation(FMath::VInterpTo(GetActorLocation(),PlayerCharacter->GetActorLocation(),DeltaTime,MoveSpeed));
	}
}

void AEnemy::Initialize_Implementation( AActor* Character)
{
	PlayerCharacter = Character; // Set Player Character to flollow
}

