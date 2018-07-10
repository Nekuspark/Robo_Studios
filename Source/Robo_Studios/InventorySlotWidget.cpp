// Fill out your copyright notice in the Description page of Project Settings.

#include "InventorySlotWidget.h"
#include "Robo_StudiosCharacter.h"
#include "Kismet/GameplayStatics.h"

void UInventorySlotWidget::SetEquippedItem()
{
	ARobo_StudiosCharacter* Char = Cast<ARobo_StudiosCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	if (Char)
	{
		Char->SetEquippedItem(ItemTexture);
	}
}

void UInventorySlotWidget::SetItemTexture(AKeyPickup* Item)
{
	//If the item is valid update the widget's texture.
	//If not, assign a null ptr to it so the widget won't broadcast wrong information to the player
	(Item) ? ItemTexture = Item->GetKeyPickupTexture() : ItemTexture = nullptr;
}




