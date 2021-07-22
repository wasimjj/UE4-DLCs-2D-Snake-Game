// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemy.h"
#include "Components/BoxComponent.h"

#include "CubeEnemy.generated.h"

/**
 * 
 */
UCLASS()
class SURVIVALGAME_API ACubeEnemy : public AEnemy
{
	GENERATED_BODY()
	virtual void BeginPlay() override;
	virtual void Initialize_Implementation(AActor* Character) override;
	public:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Mesh")
	UStaticMeshComponent* StaticMeshComponents;
	public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable , Category="Bullet Hit")
	void BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult );
	void BeginOverlap_Implementation(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,

	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
