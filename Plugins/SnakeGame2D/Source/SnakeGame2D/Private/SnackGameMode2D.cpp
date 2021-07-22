// Fill out your copyright notice in the Description page of Project Settings.


#include "SnackGameMode2D.h"

#include "SnakeCharacter2D.h"
#include "Kismet/GameplayStatics.h"


void ASnackGameMode2D::BeginPlay()
{
	Super::BeginPlay();
	Cast<ASnakeCharacter2D>( UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))->OnNodePicked.AddDynamic(this
		,&ASnackGameMode2D::OnNodePicked);
}

void ASnackGameMode2D::OnNodePicked()
{
	SpawnSnakeNode();
}

void ASnackGameMode2D::SpawnSnakeNode()
{
	if(SnakeTailNode != nullptr)
	{
		const FActorSpawnParameters ActorSpawnParameters;
		ASnakeTailComponent* TailNode = GetWorld()->SpawnActor<ASnakeTailComponent>(SnakeTailNode,GetNextGridPosition(),FRotator::ZeroRotator,ActorSpawnParameters);
		TailNode->UpdateLocation(BoxSize);
		OnSpawnNewNode.Broadcast(TailNode);
		Score++;
	}
}

FVector ASnackGameMode2D::GetNextGridPosition() const
{
	return FVector(10,
	FMath::RandRange (1,ScreenRows)  * BoxSize ,
	FMath::RandRange (1,ScreenRows) * BoxSize 
	);
	
}

void ASnackGameMode2D::GameEnd()
{
	OnGameEndDelegate.Broadcast();
}
