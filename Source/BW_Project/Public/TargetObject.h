// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TeleportInterface.h"
#include "GameFramework/Actor.h"
#include "TargetObject.generated.h"

UCLASS()
class BW_PROJECT_API ATargetObject : public AActor, public ITeleportInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATargetObject();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void OnTargetTeleport(FVector targetTransform) override;

	void ResetPhysics();

	FTimerHandle physicsTimerDelayHandle;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* mesh;

};
