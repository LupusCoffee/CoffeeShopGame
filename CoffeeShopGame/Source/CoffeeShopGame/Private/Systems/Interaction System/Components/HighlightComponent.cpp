//Note: move to "core/components" if used by more than interaction system


#include "Systems/Interaction System/Components/HighlightComponent.h"


UHighlightComponent::UHighlightComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UHighlightComponent::BeginPlay()
{
	Super::BeginPlay();

	HighlightedMesh = GetOwner()->FindComponentByClass<UStaticMeshComponent>();

	//todo: add which actor it is
	if (!HighlightedMesh) GEngine->AddOnScreenDebugMessage(0, 2, FColor::Red, "Highlighted mesh on actor with HighlightComponent is null");
}

void UHighlightComponent::EnableHighlight(EActorType ActorType)
{
	if (HighlightedMesh && HighlightData)
	{
		UMaterialInterface* HighlightMat = HighlightData->GetHighlightMaterial();
		
		//todo: create a subsystem that, upon start, makes a list UMaterialInstanceDynamic
		//for each ActorType from HighlightData --> take DynamicMats from there via ActorType enum
		UMaterialInstanceDynamic* DynMaterial = UMaterialInstanceDynamic::Create(HighlightMat, this);
		DynMaterial->SetVectorParameterValue(HighlightData->GetHighlightMatColorVariableName(), HighlightData->GetColor(ActorType));
		
		HighlightedMesh->SetOverlayMaterial(DynMaterial);
	}
}

void UHighlightComponent::DisableHighlight(EActorType ActorType)
{
	if (HighlightedMesh) HighlightedMesh->SetOverlayMaterial(nullptr);
}

