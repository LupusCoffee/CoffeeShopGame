#include "Systems/Interaction System/Components/InteractionComponent.h"

#include "Core/Data/Interfaces/Interactable.h"
#include "Kismet/GameplayStatics.h"


UInteractionComponent::UInteractionComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}

void UInteractionComponent::BeginPlay()
{
	Super::BeginPlay();

	PlayerController = Cast<APlayerController>(UGameplayStatics::GetPlayerController(this, 0));
	
	//update focus frequency
	//--> if 0 or less, do tick
	//--> if over 0, do timer
}


void UInteractionComponent::TryInteract()
{
	UpdateFocusActor();
	
	if (!FocusActor) return;

	IInteractable::Execute_Interact(FocusActor, GetOwner());
}

void UInteractionComponent::UpdateFocusActor()
{
	FHitResult Hit;

	//Start and End Locations
	FVector ViewLocation;
	FRotator ViewRotation;
	PlayerController->GetPlayerViewPoint(ViewLocation, ViewRotation);
	FVector StartLocation = ViewLocation;
	FVector EndLocation = ViewLocation + ViewRotation.Vector() * TraceLength;
	
	//Sphere, Params
	FCollisionShape Sphere = FCollisionShape::MakeSphere(TraceRadius);
	FCollisionQueryParams Params(SCENE_QUERY_STAT(SphereTraceSingle),false);

	//Shoot sphere trace
	const bool bHit = GetWorld()->SweepSingleByChannel(
		Hit, StartLocation, EndLocation,
		FQuat::Identity, TraceChannel, Sphere, Params
	);

	//Debug
	if (bDrawTraceDebug)
	{
		DrawDebugCapsule(
			GetWorld(), (StartLocation+EndLocation)*0.5f,
			(EndLocation-StartLocation).Size()*0.5f,TraceRadius,
			FRotationMatrix::MakeFromZ(ViewRotation.Vector()).ToQuat(),
			bHit ? FColor::Green : FColor::Red, false, 0.05f
		);
	}

	//Return based on hit and interface implemented
	AActor* HitActor = nullptr;
	
	if (bHit) HitActor = Hit.GetActor();
	if (HitActor && !HitActor->GetClass()->ImplementsInterface(UInteractable::StaticClass()))
		HitActor = nullptr;
	
	FocusActor = HitActor;
}


