// Fill out your copyright notice in the Description page of Project Settings.


#include "SnakeTailComponent.h"


// Sets default values
ASnakeTailComponent::ASnakeTailComponent()
{

}

void ASnakeTailComponent::UpdateLocation(const int BoxSize) // Update Current position after step move 
{
	MyLocation = FVector2D(static_cast<int>(GetActorLocation().Z/BoxSize) , static_cast<int>(GetActorLocation().Y/BoxSize));
}

FVector2D ASnakeTailComponent::GetPositionOnScreenGird() //  return node current position on screen grid
{
	return MyLocation;
}


