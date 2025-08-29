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
		
		//todo: undo the hardcoding + dont create everytime
		UMaterialInstanceDynamic* DynMaterial = UMaterialInstanceDynamic::Create(HighlightMat, this);
		DynMaterial->SetVectorParameterValue(FName("Color"), HighlightData->GetColor(ActorType));
		
		HighlightedMesh->SetOverlayMaterial(DynMaterial);
	}
}

void UHighlightComponent::DisableHighlight(EActorType ActorType)
{
	if (HighlightedMesh) HighlightedMesh->SetOverlayMaterial(nullptr);
}

