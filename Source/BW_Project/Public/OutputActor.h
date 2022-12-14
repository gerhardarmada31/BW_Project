// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "KeyObjectInteract.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "OutputActor.generated.h"

UCLASS()
class BW_PROJECT_API AOutputActor : public AActor, public IKeyObjectInteract
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AOutputActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;



	UPROPERTY(VisibleAnywhere, Category=Mesh)
	UStaticMeshComponent* mesh;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	virtual void OnKeyCollide(bool isKeyEntered) override;

};
