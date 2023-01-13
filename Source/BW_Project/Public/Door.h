// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OutputActor.h"
#include "Door.generated.h"

/**
 * 
 */
UCLASS()
class BW_PROJECT_API ADoor : public AOutputActor
{
	GENERATED_BODY()

public:

	//Constructor
	ADoor();

	virtual void Tick(float DeltaTime) override;

	virtual void BeginPlay() override;

	//When the object opens

	

protected:
	UPROPERTY(EditAnywhere)
	USceneComponent* endPoint = nullptr;

	AActor* parent = nullptr;
	FVector startLocation;

	UPROPERTY(EditAnywhere,Category="Lerp",meta=(MakeEditWidget=true))
	FVector endLocation;

	UPROPERTY(EditAnywhere, Category="Lerp")
	float lerpDuration=5.0f;

	UPROPERTY(EditAnywhere,Category="Lerp")
	float timeElapsed = 0.0f;

	FVector targetlocation;

	void DoorOpening();
};

