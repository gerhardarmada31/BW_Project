// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "BW_ProjectHUD.generated.h"

UCLASS()
class ABW_ProjectHUD : public AHUD
{
	GENERATED_BODY()

public:
	ABW_ProjectHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

