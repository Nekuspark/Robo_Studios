// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "KeyPickup.h"
#include "Blueprint/UserWidget.h"
#include "InventorySlotWidget.generated.h"

/**
 * 
 */
UCLASS()
class ROBO_STUDIOS_API UInventorySlotWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	/*Holds a reference to the item texture*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UTexture2D* ItemTexture;

	/*Tells the player the equip the represented item from this widget*/
	UFUNCTION(BlueprintCallable, Category = UI)
		void SetEquippedItem();

public:
	/*Sets the item texture*/
	UFUNCTION(BlueprintCallable, Category = UI)
		void SetItemTexture(AKeyPickup* Item);
	
public:
	/*Adds the widget into the viewport and populates the inventory slots*/
	UFUNCTION(BlueprintImplementableEvent, Category = UI)
		void Show();

	/*Removes the widget from the viewport*/
	UFUNCTION(BlueprintImplementableEvent, Category = UI)
		void Hide();

	/*Stores a reference in order to bind information on inventory slots*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		TArray<AKeyPickup*> ItemsArray;
};
