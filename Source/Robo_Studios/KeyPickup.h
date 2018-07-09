// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "KeyPickup.generated.h"

UCLASS()
class ROBO_STUDIOS_API AKeyPickup : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AKeyPickup();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	/*Enables/Disables the glow effect on the pickup*/
	void SetGlowEffect(bool Status);

	/*Returns the Texture of our Pickup*/
	FORCEINLINE UTexture2D* GetKeyPickupTexture() { return KeyPickupTexture; }

protected:
	/*The Static Mesh of the pickup*/
	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* KeyPickupSM;

	/*The Texture of the item in case we want to add it in the secrets or inventory*/
	UPROPERTY(EditAnywhere, Category = "PickupProperties")
		UTexture2D* KeyPickupTexture;

	/*The name of the item*/
	UPROPERTY(EditAnywhere, Category = "PickupProperties")
		FString ItemName;
	
};
