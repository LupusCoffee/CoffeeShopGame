#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TempToGenerateSourceFiles.generated.h"

UCLASS()
class COFFEESHOPGAME_API ATempToGenerateSourceFiles : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATempToGenerateSourceFiles();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
