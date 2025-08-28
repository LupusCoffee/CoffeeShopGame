#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InteractionComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class COFFEESHOPGAME_API UInteractionComponent : public UActorComponent
{
	GENERATED_BODY()

	
public:
	//Contructor
	UInteractionComponent();

	//Variables
	UPROPERTY(EditAnywhere, Category="Interaction")
	float TraceLength = 500.0f;

	UPROPERTY(EditAnywhere, Category="Interaction")
	float TraceRadius = 12.0f;

	UPROPERTY(EditAnywhere, Category="Interaction")
	TEnumAsByte<ECollisionChannel> TraceChannel = ECC_Visibility;

	UPROPERTY(EditAnywhere, Category="Interaction")
	bool bDrawTraceDebug = false;
	
	UPROPERTY(EditAnywhere, Category="Interaction", meta = (ToolTip = "How many times we update the focus actor per second."))
	float UpdateFocusActorFrequency = 30.0f;
	

	//Methods
	UFUNCTION(BlueprintCallable, Category="Interaction")
	void TryInteract();
	
	
protected:
	virtual void BeginPlay() override;

	UPROPERTY()
	APlayerController* PlayerController = nullptr;
	
	UPROPERTY(VisibleAnywhere, Category="Interaction")
	AActor* FocusActor = nullptr;

	UFUNCTION()
	void UpdateFocusActor();
	
	
	//todo:
	//- configurable trace (lenght, channel, radius, frequency)
	//- currently looked-at interactable --> focus actor
	//- input hook --> call from pawn
	//- call interface on unhover / hover / interact

};
