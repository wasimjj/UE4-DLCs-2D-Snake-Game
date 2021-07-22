// Fill out your copyright notice in the Description page of Project Settings.


#include "SurvivalCharacter.h"

// Sets default values
ASurvivalCharacter::ASurvivalCharacter()
{
}

// Called when the game starts or when spawned
void ASurvivalCharacter::BeginPlay()
{
	Super::BeginPlay();
	InputComponent->BindAxis("Turn", this, &ASurvivalCharacter::AddControllerYawInput);
	InputComponent->BindAxis("LookUp", this, &ASurvivalCharacter::AddControllerPitchInput);
}

// Called to bind functionality to input
void ASurvivalCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}


