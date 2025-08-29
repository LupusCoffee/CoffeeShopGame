// Fill out your copyright notice in the Description page of Project Settings.


#include "UCustomerAISubsystem.h"

void UUCustomerAISubsystem::EnterQueue(ACustomer* customer)
{
	Queue.Push(customer);
}

void UUCustomerAISubsystem::LeaveQueue(ACustomer* customer)
{
	if (Queue.Contains(customer))
		Queue.Remove(customer);
}

int UUCustomerAISubsystem::GetQueueLength()
{
	return Queue.Num();
}

void UUCustomerAISubsystem::MoveAIQueue()
{
	//TODO: Call each and every ai and give them the next queue position
}
