// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "KeyObjectInteract.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UKeyObjectInteract : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class BW_PROJECT_API IKeyObjectInteract
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void OnKeyCollide(bool isKeyEntered){}
protected:
   
};
