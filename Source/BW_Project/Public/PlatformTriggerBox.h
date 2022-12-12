// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "PlatformTriggerBox.generated.h"

/**
 * 
 */
UCLASS()
class BW_PROJECT_API APlatformTriggerBox : public ATriggerBox
{
	APlatformTriggerBox();
	GENERATED_BODY()

protected:


public:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* mesh;
};
