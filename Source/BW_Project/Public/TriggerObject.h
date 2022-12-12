// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "TeleportInterface.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TriggerObject.generated.h"


UCLASS()
class BW_PROJECT_API ATriggerObject : public AActor, public ITeleportInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATriggerObject();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void OnObjectTrigger() override;
	
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* mesh;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
