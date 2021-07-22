// Fill out your copyright notice in the Description page of Project Settings.


#include "SnakeHUD.h"

#include "GameEndPopup.h"
#include "Blueprint/UserWidget.h"

void ASnakeHUD::BeginPlay()
{
	Super::BeginPlay();
  
	//GameEndPopup = CreateWidget<UGameEndPopup>(GetOwningPlayerController(), GameEndPopupClass);
	// /GameEndPopup->Setup();
}
