// Fill out your copyright notice in the Description page of Project Settings.


#include "SurvivalController.h"

#include <concrt.h>

#include "Kismet/GameplayStatics.h"

void ASurvivalController::BeginPlay()
{
	EnableInput(this);
	check(InputComponent);
	InputComponent->BindAxis("MoveRight",this,&ASurvivalController::MoveRight);
	InputComponent->BindAxis("MoveForward",this,&ASurvivalController::MoveForward);
	InputComponent->BindAction("Fire", IE_Pressed, this, &ASurvivalController::OnFire);
	
}
void ASurvivalController::MoveForward(float InputValue)
{
	if(InputValue)
	{
		SurvivalCharacter =  Cast<ASurvivalCharacter>( UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
		const FVector Direction = FRotationMatrix(SurvivalCharacter->GetControlRotation()).GetScaledAxis(EAxis::X);
		SurvivalCharacter->AddMovementInput(Direction,InputValue);
	}
	
}

void ASurvivalController::MoveRight(float InputValue)
{
	if(InputValue)
	{
			SurvivalCharacter =  Cast<ASurvivalCharacter>( UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
			const FVector Direction = FRotationMatrix(SurvivalCharacter->GetControlRotation()).GetScaledAxis(EAxis::Y);
			SurvivalCharacter->AddMovementInput(Direction,InputValue);
	}

}

void ASurvivalController::OnFire()
{
	if (BulletPreset != nullptr)
	{
		UWorld* const World = GetWorld();
		if (World != nullptr)
		{
			SurvivalCharacter =  Cast<ASurvivalCharacter>( UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
			const FRotator SpawnRotation = GetControlRotation();
			const FVector Location =  SurvivalCharacter->GetActorLocation() + SpawnRotation.RotateVector(BulletOffset);
			FActorSpawnParameters ActorSpawnParams;
			ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;
			World->SpawnActor<ABullet>(BulletPreset, Location, SpawnRotation, ActorSpawnParams);
		}
	}
}
