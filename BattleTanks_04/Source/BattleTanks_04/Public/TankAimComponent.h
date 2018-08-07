// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/GameplayStatics.h"
#include "Components/StaticMeshComponent.h" 
#include "Components/ActorComponent.h"
#include "Engine/World.h"
#include "TankAimComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANKS_04_API UTankAimComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimComponent();

	void SetBarrelRefference(UStaticMeshComponent* BarrelToSet);

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void AimAt(FVector OUTHitLocation, float LaunchSpeed);

	
		
private:

	UStaticMeshComponent * Barrel = nullptr;


protected:
	// Called when the game starts
	virtual void BeginPlay() override;
};
