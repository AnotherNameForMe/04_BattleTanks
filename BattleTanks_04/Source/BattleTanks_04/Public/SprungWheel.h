// Copyright EmbraceIT LTD.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PhysicsEngine/PhysicsConstraintComponent.h"
#include "Components/SphereComponent.h"
#include "SprungWheel.generated.h"

UCLASS()
class BATTLETANKS_04_API ASprungWheel : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASprungWheel();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	
	UPROPERTY(VisibleDefaultsOnly)
		USphereComponent* Wheels = nullptr;

	UPROPERTY(VisibleDefaultsOnly)
		USphereComponent* Axles = nullptr;
	
	UPROPERTY(VisibleDefaultsOnly)
		UPhysicsConstraintComponent* WheelConstraintComponent = nullptr;
	
	UPROPERTY(VisibleDefaultsOnly)
		UPhysicsConstraintComponent* AxleConstraintComponent = nullptr;

	void SetupConstraints();

};
