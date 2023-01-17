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
	USceneComponent* rootPoint = nullptr;

	AActor* parent = nullptr;
	FVector startLocation;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Lerp",meta=(MakeEditWidget=true))
	FVector endLocation;
	

	FVector targetlocation;

	void DoorOpening();
};

