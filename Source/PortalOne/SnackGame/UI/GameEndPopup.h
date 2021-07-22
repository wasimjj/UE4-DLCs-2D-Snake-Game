// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"

#include "GameEndPopup.generated.h"

/**
 * 
 */
UCLASS()
class PORTALONE_API UGameEndPopup : public UUserWidget
{
	GENERATED_BODY()
	virtual bool Initialize() override;
	public:
	UPROPERTY(meta = (BindWidget))
	UButton* ButtonRestart;

	UPROPERTY(meta = (BindWidget))
	UButton* ButtonMainMenu;
	UFUNCTION(BlueprintCallable , Category="Button Events")
	void OnRestartClick();
	UFUNCTION(BlueprintCallable , Category="Button Events")
	void OnMainMenuClick();
	UFUNCTION(BlueprintCallable , Category="Setup")
	void Setup( );
};
