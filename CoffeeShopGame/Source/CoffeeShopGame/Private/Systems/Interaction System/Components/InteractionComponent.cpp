#include "Systems/Interaction System/Components/InteractionComponent.h"

#include "Core/Data/Interfaces/Interactable.h"
#include "Kismet/GameplayStatics.h"


UInteractionComponent::UInteractionComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

}

void UInteractionComponent::BeginPlay()
{
	Super::BeginPlay();

	PlayerController = Cast<APlayerController>(UGameplayStatics::GetPlayerController(this, 0));
	
	//update focus frequency
	//--> if 0 or less, do tick
	//--> if over 0, do timer
	if (UpdateFocusActorFrequency <= 0.0f)
	{
		PrimaryComponentTick.bCanEverTick = true;
		SetComponentTickEnabled(true);
	}
	else
	{
		const float Interval = 1.f / UpdateFocusActorFrequency;
		GetWorld()->GetTimerManager().SetTimer(FocusTimer, this, &UInteractionComponent::UpdateFocusActor, Interval, true);
	}
}

void UInteractionComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	GetWorld()->GetTimerManager().ClearTimer(FocusTimer);
	Super::EndPlay(EndPlayReason);
}

void UInteractionComponent::TickComponent(float DeltaTime, enum ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	UpdateFocusActor();
}


void UInteractionComponent::TryInteract()
{
	UpdateFocusActor();
	
	if (!FocusActor) return;

	IInteractable::Execute_Interact(FocusActor, GetOwner());
}

//todo: refactor some of these into functions
//todo: if i start using more traces like this, create a helper function for it
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

	//Set HitActor based on hit and interface implemented
	AActor* HitActor = nullptr;
	
	if (bHit) HitActor = Hit.GetActor();
	if (HitActor && !HitActor->GetClass()->ImplementsInterface(UInteractable::StaticClass()))
		HitActor = nullptr;

	//Hover - todo: refactor?
	if (!FocusActor && HitActor)
	{
		IInteractable::Execute_Hover(HitActor, GetOwner());
	}
	else if (FocusActor && !HitActor)
	{
		IInteractable::Execute_Unhover(FocusActor, GetOwner());
	}
	else if (FocusActor && HitActor && FocusActor != HitActor)
	{
		IInteractable::Execute_Unhover(FocusActor, GetOwner());
		IInteractable::Execute_Hover(HitActor, GetOwner());
	}

	//Set FocusActor to HitActor
	FocusActor = HitActor;
}


