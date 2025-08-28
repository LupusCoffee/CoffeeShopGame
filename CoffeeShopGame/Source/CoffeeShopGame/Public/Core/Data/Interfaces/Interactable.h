#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Interactable.generated.h"

UINTERFACE(Blueprintable)
class UInteractable : public UInterface
{
	GENERATED_BODY()
};

class COFFEESHOPGAME_API IInteractable
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void Hover(AActor* InstigatorActor);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void Unhover(AActor* InstigatorActor);
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void Interact(AActor* InstigatorActor);
};
