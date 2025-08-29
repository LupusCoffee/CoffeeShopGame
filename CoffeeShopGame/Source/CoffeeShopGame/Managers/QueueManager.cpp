// Fill out your copyright notice in the Description page of Project Settings.


#include "QueueManager.h"

// Sets default values
AQueueManager::AQueueManager()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AQueueManager::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AQueueManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

