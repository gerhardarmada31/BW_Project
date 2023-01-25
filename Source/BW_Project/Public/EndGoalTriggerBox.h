// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "EndGoalTriggerBox.generated.h"

/**
 * 
 */
UCLASS()
class BW_PROJECT_API AEndGoalTriggerBox : public ATriggerBox
{
	GENERATED_BODY()
	//Make Scene component as the rootcomponent
	//Create Constructor
	//BeginOverlap Function
	//Future proof on nextlevel script
	//Begin overlap goes to the next level
	
public:
	AEndGoalTriggerBox();

		
	UFUNCTION()
	void OnOverLapBegin(class AActor* OverlappedActor, class AActor* OtherActor);

	UFUNCTION()
	void OnOverLapEnd(class AActor* OverlappedActor, class AActor* OtherActor);
	
protected:
	UPROPERTY(EditAnywhere, Category="NextMap")
	FName nextLevelName;

	//UPROPERTY(EditAnywhere)
	class ABW_ProjectCharacter* playerCharacter;
	

	

	
};
