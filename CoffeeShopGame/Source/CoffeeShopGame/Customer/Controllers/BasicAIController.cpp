// Fill out your copyright notice in the Description page of Project Settings.


#include "BasicAIController.h"


// Sets default values
ABasicAIController::ABasicAIController()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ABasicAIController::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABasicAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

