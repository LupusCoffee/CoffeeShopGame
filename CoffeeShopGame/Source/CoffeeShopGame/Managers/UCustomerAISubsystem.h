// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AISubsystem.h"
#include "CoffeeShopGame/Customer/Customer.h"
#include "UCustomerAISubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCustomerLeftQueue, ACustomer*, customer);

/**
 * 
 */
UCLASS()
class COFFEESHOPGAME_API UUCustomerAISubsystem : public UAISubsystem
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category="AI|Queue")
	void EnterQueue(ACustomer* customer);

	UFUNCTION(BlueprintCallable, Category="AI|Queue")
	void LeaveQueue(ACustomer* customer);

	UFUNCTION(BlueprintCallable, Category="AI|Queue");
	int GetQueueLength();

	UFUNCTION(BlueprintCallable, Category="AI|Queue");
	void MoveAIQueue();

	
private:

	UPROPERTY() TArray<ACustomer*> Queue;
	UPROPERTY() int QueueSize = 0;

	UPROPERTY()
	TArray<ACustomer*> AllCustomers;

	UPROPERTY()
	ACustomer* LeftQueueCustomer;
};
