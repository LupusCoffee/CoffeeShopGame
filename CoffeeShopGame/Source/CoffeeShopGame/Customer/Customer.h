// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Customer.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCustomerLostPatience);

USTRUCT()
struct FCustomerStats
{
	GENERATED_BODY()

	//TODO: Add prefered drinks
	//TODO: Relationship with player
	//TODO: Add preffered attractions

	FString name;
	float Patience;
};

UCLASS()
class COFFEESHOPGAME_API ACustomer : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACustomer();

	virtual void Tick(float DeltaTime) override;

	void UpdatePatienceTime(float newTime);

	void StartPatienceTick();
	void UpdatePatienceTick(float DeltaTime);
	void EndPatienceTick();

	UPROPERTY(BlueprintAssignable, Category="Events")
	FOnCustomerLostPatience OnCustomerLostPatience;
	
	FCustomerStats stats;

protected:
	virtual void BeginPlay() override;

private:
	float patienceTime = 0;

	bool shouldTickPatience = false;
};
