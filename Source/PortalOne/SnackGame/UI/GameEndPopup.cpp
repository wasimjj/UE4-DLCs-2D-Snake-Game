// Fill out your copyright notice in the Description page of Project Settings.


#include "GameEndPopup.h"

bool UGameEndPopup::Initialize()
{
	if(ButtonRestart != nullptr)
	{
		ButtonRestart->OnReleased.AddDynamic(this,&UGameEndPopup::UGameEndPopup::OnRestartClick);
	}
	return true;
}

void UGameEndPopup::OnRestartClick()
{
	GLog->Log("Button Clickd");
}

void UGameEndPopup::OnMainMenuClick()
{
}
void UGameEndPopup::Setup()
{
	this->AddToViewport();
	// UWorld* World = GetWorld();
	// APlayerController* PlayerController = World->GetFirstPlayerController();
	// FInputModeUIOnly InputModeData;
	// InputModeData.SetWidgetToFocus(this->TakeWidget());
	// InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	// PlayerController->SetInputMode(InputModeData);
	// PlayerController->bShowMouseCursor = true;
}
