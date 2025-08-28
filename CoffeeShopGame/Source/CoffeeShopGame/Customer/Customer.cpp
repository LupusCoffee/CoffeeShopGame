// Fill out your copyright notice in the Description page of Project Settings.


#include "Customer.h"


// Sets default values
ACustomer::ACustomer()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ACustomer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACustomer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ACustomer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

float ACustomer::CalculateTip() const
{
	//TODO: When manager is up and running, call it and gather all necessary data in here and add to the tip ammount
	return tipAmount;
}

void ACustomer::AddPatience(float addAmount)
{
	stats.patienceTime += addAmount;
}

FCustomerStats ACustomer::GetCustomerStats() const
{
	return stats;
}

