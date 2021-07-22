// Fill out your copyright notice in the Description page of Project Settings.


#include "CubeEnemy.h"
#include "SurvivalGameMode.h"
#include "Bullet.h"
#include "SphereBullet.h"


void ACubeEnemy::BeginPlay()
{
	Super::BeginPlay();

	SurvivalGameMode = Cast<ASurvivalGameMode>(GetWorld()->GetAuthGameMode());

	UActorComponent* ActorComponent = GetComponentByClass(UStaticMeshComponent::StaticClass());
	if(ActorComponent)
	{
		StaticMeshComponents = Cast<UStaticMeshComponent>(ActorComponent);
		if(StaticMeshComponents)
		{
			StaticMeshComponents->OnComponentBeginOverlap.AddDynamic( this, &ACubeEnemy::BeginOverlap );
		}
	}
}

void ACubeEnemy::Initialize_Implementation(AActor* Character)
{
	Super::Initialize_Implementation(Character);
	StaticMeshComponents->SetGenerateOverlapEvents(true);
	StaticMeshComponents->SetCollisionEnabled(ECollisionEnabled::QueryOnly);

	SetActorHiddenInGame(false);
	GLog->Log("ACubeEnemy :::Initialize_Implementation");
}

void ACubeEnemy::BeginOverlap_Implementation(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	OtherComp->AddImpulseAtLocation(GetVelocity() * 100.0f, GetActorLocation());
	GLog->Log(FString::Printf(TEXT("Hited Object ::: %s"),*OtherActor->GetName()));
	if(Cast<ASphereBullet>(OtherActor))
	{
		SurvivalGameMode->OnEnemyKilledDelegate.Broadcast(this);
		StaticMeshComponents->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		StaticMeshComponents->SetGenerateOverlapEvents(false);
		SetActorHiddenInGame(true);
	}else if(Cast<ASurvivalCharacter>(OtherActor))
	{
		SurvivalGameMode->OnGameEndDelegate.Broadcast(false);
	}
}

