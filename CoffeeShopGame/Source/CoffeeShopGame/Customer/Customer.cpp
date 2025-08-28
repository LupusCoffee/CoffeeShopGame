// Fill out your copyright notice in the Description page of Project Settings.


#include "Customer.h"


// Sets default values
ACustomer::ACustomer()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
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

	if (shouldTickPatience)
		UpdatePatienceTick(DeltaTime);
}

void ACustomer::UpdatePatienceTime(float newTime)
{
	patienceTime = newTime;
}

void ACustomer::StartPatienceTick()
{
	shouldTickPatience = true;
}

void ACustomer::UpdatePatienceTick(float DeltaTime)
{
	if (patienceTime > 0)
	{
		patienceTime -= DeltaTime;
		
	}

	if (patienceTime <= 0)
		EndPatienceTick();
}

void ACustomer::EndPatienceTick()
{
	shouldTickPatience = false;

	OnCustomerLostPatience.Broadcast();
	
}
