// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "Robo_StudiosGameMode.h"
#include "Robo_StudiosHUD.h"
#include "Robo_StudiosCharacter.h"
#include "UObject/ConstructorHelpers.h"

ARobo_StudiosGameMode::ARobo_StudiosGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ARobo_StudiosHUD::StaticClass();
}
