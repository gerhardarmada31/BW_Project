// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "KeyObjectInteract.h"
#include "CoreMinimal.h"
#include "OutputActor.h"
#include "GameFramework/Actor.h"
#include "TriggerObject.generated.h"


UCLASS()
class BW_PROJECT_API ATriggerObject : public AActor, public IKeyObjectInteract
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATriggerObject();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//virtual void OnKeyCollide(bool isKeyEntered) override;
	
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* mesh;

	UPROPERTY(EditAnywhere, Category="Secondary Mesh")
	UStaticMeshComponent* secondaryMesh = nullptr;

	//UPROPERTY(EditAnywhere)
	class ATargetObject* targetObject;
	
	//UPROPERTY(EditAnywhere)
	class ABW_ProjectCharacter* playerCharacter;

	// UPROPERTY(EditAnywhere, Category="OutputActor")
	// AActor* doorActor;

	UPROPERTY(EditAnywhere, Category="OutputActor")
	AOutputActor* doorActor;



	UPROPERTY(EditAnywhere, Category="Player Trigger")
	bool isPlayerTrigger;



public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	


};
