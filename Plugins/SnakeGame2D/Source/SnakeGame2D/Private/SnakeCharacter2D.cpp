// Fill out your copyright notice in the Description page of Project Settings.


#include "SnakeCharacter2D.h"

// Fill out your copyright notice in the Description page of Project Settings.
#include "SnackGameMode2D.h"

void ASnakeCharacter2D::BeginPlay()
{
	// Get Game to Set Game Rule Speed etc
	SnackGameMode = Cast<ASnackGameMode2D>(GetWorld()->GetAuthGameMode());
	BindDelegates();
	// Spawn Snake Node And Start Moving
	SnackGameMode->SpawnSnakeNode();
	SnakeSpeed = SnackGameMode->GameSpeed;
	StartMovement();
}
inline void ASnakeCharacter2D::BindDelegates()
{
	SnackGameMode->OnSpawnNewNode.AddDynamic(this,&ASnakeCharacter2D::OnSpawnNewNode);
	SnackGameMode->OnGameEndDelegate.AddDynamic(this,&ASnakeCharacter2D::OnGameEnd);
}

inline void ASnakeCharacter2D::UnBindDelegates()
{
	SnackGameMode->OnSpawnNewNode.RemoveDynamic(this,&ASnakeCharacter2D::OnSpawnNewNode);
	SnackGameMode->OnGameEndDelegate.RemoveDynamic(this,&ASnakeCharacter2D::OnGameEnd);
}

void ASnakeCharacter2D::StartMovement()
{
	// Snake Auto Step will be taken after speed perm "SnakeSpeed"
	FTimerDelegate TimerDel;
	FTimerHandle TimerHandle;
	TimerDel.BindUFunction(this, FName("MoveSnakeOneStep") , 0, 0.0);
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, TimerDel, SnakeSpeed, true);
}

void ASnakeCharacter2D::AddNodeToTail()
{
	// Add Node To tail when snake eat it  or chase it 
	SnakeTail.AddTail(CurrentNodeToPick);
}

bool ASnakeCharacter2D::CheckIfNodePickAble()
{
	// Check if snake head is equal to node position
	if(IsNodePickAble(CurrentNodeToPick))
	{
		AddNodeToTail();
		OnNodePicked.Broadcast();
		return true;
	}
	return false;
}

void ASnakeCharacter2D::OnSpawnNewNode(ASnakeTailComponent* SnakeTailNode)
{
	// Set new node to pick so we can match player position with it 
	CurrentNodeToPick = SnakeTailNode;
}

void ASnakeCharacter2D::OnGameEnd()
{
	// End Game because of wrong movement 
	GetWorld()->GetTimerManager().ClearAllTimersForObject(this); // Stop Snake Movement
	UnBindDelegates();
}

void ASnakeCharacter2D::MoveSnakeOneStep()
{
	
	if(!bIsSkipStep) // if player hit direction key skip auto timer 
	{
		///  Move each node to one step
		FVector SnakeLocation = this->GetActorLocation();
		FVector NodeLocation = this->GetActorLocation();
		for (TDoubleLinkedList<ASnakeTailComponent*>::TIterator Itr(SnakeTail.GetHead()); Itr; ++Itr)
		{
			if(*Itr != nullptr)
			{
				NodeLocation = Itr->GetActorLocation();
				Itr->SetActorLocation(SnakeLocation);
				SnakeLocation = NodeLocation;
			}
				
		}
		////
		SnakeLocation = this->GetActorLocation();
		switch (CurrentDirection) // move player one step
		{
		case EDirection::EUp :
			SnakeLocation.Z = static_cast<int>( SnakeLocation.Z + GetMoveStepSize());
			break;
		case EDirection::EDown:
			SnakeLocation.Z = static_cast<int>( SnakeLocation.Z - GetMoveStepSize());
			break;
		case EDirection::ELeft:
			SnakeLocation.Y =  static_cast<int>( SnakeLocation.Y - GetMoveStepSize());
			break;
		case EDirection::ERight:
			SnakeLocation.Y = static_cast<int>( SnakeLocation.Y + GetMoveStepSize());
			break;
		}
		this->SetActorLocation(SnakeLocation);
		// Now  check if player at node or player at wrong move position 
		UpdateLocation();
		CheckIfSnakeCanDie();
		CheckIfNodePickAble();
	}
	
	bIsSkipStep = false;
}
void ASnakeCharacter2D::CheckIfSnakeCanDie()
{
	if(IsSnakeOutOfBound()) // Out of screen boundaries 
	{
		SnackGameMode->GameEnd();
	}
	for (auto Node : SnakeTail) // If head is position of its node 
	{
		if(IsNodePickAble(Node))
		{
			SnackGameMode->GameEnd();
		}
	}
}
void ASnakeCharacter2D::UpdateDirection(EDirection Direction) // update direction when player change direction 
{
	CurrentDirection = Direction;
	MoveSnakeOneStep();
	bIsSkipStep = !bIsSkipStep;
}


int ASnakeCharacter2D::GetMoveStepSize()// Get step size to move player after interval 
{
	return SnackGameMode->BoxSize;
}

bool ASnakeCharacter2D::IsNodePickAble(ASnakeTailComponent* SnakeTailNode) // check if snake head is at node position 
{
	return SnakeTailNode->GetPositionOnScreenGird().X  == RowOfhHead && // Row
		SnakeTailNode->GetPositionOnScreenGird().Y  == ColumnOfhHead; // Column
}

void ASnakeCharacter2D::UpdateLocation() 
{
	RowOfhHead = GetActorLocation().Z /SnackGameMode->BoxSize;
	ColumnOfhHead = GetActorLocation().Y /SnackGameMode->BoxSize;
	for (auto Node : SnakeTail)
	{
		Node->UpdateLocation(SnackGameMode->BoxSize);
	}
	
}
bool ASnakeCharacter2D::IsSnakeOutOfBound() const
{
	return  RowOfhHead < 0 || RowOfhHead > SnackGameMode->ScreenRows || ColumnOfhHead < 0 ||ColumnOfhHead > SnackGameMode->ScreenColumn;
}
EDirection ASnakeCharacter2D::GetDirection()
{
	return CurrentDirection;
}

