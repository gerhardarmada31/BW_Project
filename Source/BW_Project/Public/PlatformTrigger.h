// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Components/BoxComponent.h"
#include "CoreMinimal.h"
#include "TriggerObject.h"
#include "PlatformTrigger.generated.h"

/**
 * 
 */
UCLASS()
class BW_PROJECT_API APlatformTrigger : public ATriggerObject
{

	GENERATED_BODY()


	
public:


	//Set Default values
	APlatformTrigger();


	UPROPERTY(VisibleAnywhere)
	UBoxComponent* platformCollisionBox = nullptr;

	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);


};
