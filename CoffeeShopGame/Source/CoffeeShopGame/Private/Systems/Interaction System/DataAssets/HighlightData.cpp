#include "Systems/Interaction System/DataAssets/HighlightData.h"

UMaterialInterface* UHighlightData::GetHighlightMaterial()
{
	return HighlightMaterial;
}

FLinearColor UHighlightData::GetColor(EActorType ActorType)
{
	return HighlightData[ActorType];
}
