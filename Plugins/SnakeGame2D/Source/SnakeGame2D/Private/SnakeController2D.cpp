// Fill out your copyright notice in the Description page of Project Settings.


#include "SnakeController2D.h"

#include "SnakeCharacter2D.h"
#include "Kismet/GameplayStatics.h"

ASnakeCharacter2D* ASnakeController2D::GetSnakeCharacter2D()
{
	if(SnakeCharacter2D == nullptr)
	{
		SnakeCharacter2D = Cast<ASnakeCharacter2D>( UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	}
	return SnakeCharacter2D;
}

void ASnakeController2D::BeginPlay()
{
	BindDelegates();
}

void ASnakeController2D::BindDelegates()
{
	EnableInput(this);
	check(InputComponent);
	InputComponent->BindAction("OnUpKeyPress",IE_Released,this,&ASnakeController2D::OnUpKeyPress);
	InputComponent->BindAction("OnDownKeyPress",IE_Released,this,&ASnakeController2D::OnDownKeyPress);
	InputComponent->BindAction("OnLeftKeyPress",IE_Released,this,&ASnakeController2D::OnLeftKeyPress);
	InputComponent->BindAction("OnRightKeyPress",IE_Released,this,&ASnakeController2D::OnRightKeyPress);
	
}

void ASnakeController2D::OnUpKeyPress()
{
	ASnakeCharacter2D * SnackCharacter = GetSnakeCharacter2D();
	if(SnackCharacter->GetDirection() != EDirection::EUp && SnackCharacter->GetDirection() != EDirection::EDown )
	{
		SnackCharacter->UpdateDirection(EDirection::EUp);
	}
}

void ASnakeController2D::OnDownKeyPress()
{
	ASnakeCharacter2D * SnackCharacter = GetSnakeCharacter2D();
	if(SnackCharacter->GetDirection() != EDirection::EUp && SnackCharacter->GetDirection() != EDirection::EDown )
	{
		SnackCharacter->UpdateDirection(EDirection::EDown);
	}
}

void ASnakeController2D::OnLeftKeyPress()
{
	ASnakeCharacter2D * SnackCharacter = GetSnakeCharacter2D();
	if(SnackCharacter->GetDirection() != EDirection::ELeft && SnackCharacter->GetDirection() != EDirection::ERight )
	{
		SnackCharacter->UpdateDirection(EDirection::ELeft);
	}

}

void ASnakeController2D::OnRightKeyPress()
{
	ASnakeCharacter2D * SnackCharacter = GetSnakeCharacter2D();
	if(SnackCharacter->GetDirection() != EDirection::ELeft && SnackCharacter->GetDirection() != EDirection::ERight )
	{
		SnackCharacter->UpdateDirection(EDirection::ERight);
	}
}
