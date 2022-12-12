// Copyright Epic Games, Inc. All Rights Reserved.

#include "BW_ProjectGameMode.h"
#include "BW_ProjectHUD.h"
#include "BW_ProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

ABW_ProjectGameMode::ABW_ProjectGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ABW_ProjectHUD::StaticClass();
}
