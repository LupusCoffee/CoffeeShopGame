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

	//Variables --> Editable
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
	//Contructors
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason);
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	
	//Variables --> Visible
	UPROPERTY(VisibleAnywhere, Category="Interaction")
	AActor* FocusActor = nullptr;

	//Variables --> Hidden
	UPROPERTY()
	APlayerController* PlayerController = nullptr;

	UPROPERTY()
	FTimerHandle FocusTimer;
	

	//Methods
	UFUNCTION()
	void UpdateFocusActor();
};
