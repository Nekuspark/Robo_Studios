// Fill out your copyright notice in the Description page of Project Settings.

#include "KeyPickup.h"


// Sets default values
AKeyPickup::AKeyPickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Initializing our properties
	KeyPickupSM = CreateDefaultSubobject<UStaticMeshComponent>(FName("KeyPickupSM"));

	KeyPickupTexture = CreateDefaultSubobject<UTexture2D>(FName("ItemTexture"));
}

// Called when the game starts or when spawned
void AKeyPickup::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AKeyPickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AKeyPickup::SetGlowEffect(bool Status)
{
	KeyPickupSM->SetRenderCustomDepth(Status);
}