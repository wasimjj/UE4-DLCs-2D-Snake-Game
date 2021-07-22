// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "PortalOneGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class PORTALONE_API UPortalOneGameInstance : public UGameInstance
{
	GENERATED_BODY()
	virtual void Init() override;
	public:
	UFUNCTION(BlueprintCallable, Category="Files")
	void FindFiles();
	UPROPERTY(BlueprintReadOnly, Category="Files")
	TArray<FString> GamesList;
	
};
