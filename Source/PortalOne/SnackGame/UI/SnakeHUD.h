// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "SnakeHUD.generated.h"

class UGameEndPopup;
/**
 * 
 */
UCLASS()
class PORTALONE_API ASnakeHUD : public AHUD
{
	GENERATED_BODY()
	virtual void BeginPlay() override;
	public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly , Category="Game End ")
	TSubclassOf<UGameEndPopup> GameEndPopupClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly , Category="Game End ")
	class UGameEndPopup* GameEndPopup;
};
