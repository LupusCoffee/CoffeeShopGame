//Note: move to "core/components" if used by more than interaction system

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Core/Data/Enums/ActorType.h"
#include "Systems/Interaction System/DataAssets/HighlightData.h"
#include "HighlightComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class COFFEESHOPGAME_API UHighlightComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UHighlightComponent();

	UFUNCTION(BlueprintCallable, Category = "Highlight")
	void EnableHighlight(EActorType ActorType);

	UFUNCTION(BlueprintCallable, Category = "Highlight")
	void DisableHighlight(EActorType ActorType);

protected:
	virtual void BeginPlay() override;

	//Variables --> Edit
	UPROPERTY(EditAnywhere, Category = "Highlight")
	UHighlightData* HighlightData = nullptr;

	//Variables --> Hidden
	UPROPERTY()
	UStaticMeshComponent* HighlightedMesh = nullptr;
};
