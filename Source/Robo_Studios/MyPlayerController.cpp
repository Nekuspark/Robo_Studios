// Fill out your copyright notice in the Description page of Project Settings.

#include "MyPlayerController.h"
#include "Robo_StudiosCharacter.h"

void AMyPlayerController::Possess(APawn* InPawn)
{
	Super::Possess(InPawn);

	if (InventoryWidgetBP)
	{
		//Create the Inventory Widget based on the Blueprint reference we will input from within the Editor
		InventoryWidgetRef = CreateWidget<UInventoryWidget>(this, InventoryWidgetBP);

	}

	//Initial value
	bIsInventoryOpen = false;
}

void AMyPlayerController::HandleInventoryInput()
{
	ARobo_StudiosCharacter* Char = Cast<ARobo_StudiosCharacter>(GetPawn());
	if (InventoryWidgetRef)
	{
		if (bIsInventoryOpen)
		{
			//Mark the inventory as closed
			bIsInventoryOpen = false;

			//Remove it from the viewport
			InventoryWidgetRef->RemoveFromViewport();

			//Hide the cursor of our game
			bShowMouseCursor = false;

			//Tell the game that we want to register inputs for our game only and not for our UI
			FInputModeGameOnly InputMode;
			SetInputMode(InputMode);

			UE_LOG(LogTemp, Warning, TEXT("7"));

			//Unpause the game
			SetPause(false);
		}
		else
		{
			//Mark the inventory as open
			bIsInventoryOpen = true;

			//Re-populate the ItemsArray
			InventoryWidgetRef->ItemsArray = Char->GetInventory();

			//Show the inventory
			InventoryWidgetRef->AddToViewport();;

			//Show the cursor of our game
			bShowMouseCursor = true;

			//Tell the game that we want to register inputs both for our game and UI
			FInputModeGameAndUI InputMode;
			SetInputMode(InputMode);

			//Pause the game
			SetPause(true);
		}

	}
}

