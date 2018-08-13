// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/World.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"


class UTankBarrel;
class UTankAimComponent;
class AProjectile;

UCLASS()
class BATTLETANKS_04_API ATank : public APawn
{
	GENERATED_BODY()

public:

	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable)
		void Fire();
private:
	virtual void BeginPlay() override;
	
	// Sets default values for this pawn's properties
	ATank();
	
	UPROPERTY(EditAnywhere, Category = "Setup")
		float ReloadTimeInSeconds = 3.f;

	UPROPERTY(EditAnywhere, Category = "Firing")
		float LaunchSpeed = 4000.f;

	UPROPERTY(EditAnywhere, Category = "Setup")
		TSubclassOf<AProjectile> ProjectileBlueprint;
	
	double LastFireTime = 0.f;

	UTankBarrel* Barrel = nullptr;

protected:

	UPROPERTY(BlueprintReadOnly)
		UTankAimComponent * TankAimComponent = nullptr;

	
	
};
