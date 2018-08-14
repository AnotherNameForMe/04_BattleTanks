// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/GameplayStatics.h"
#include "Components/StaticMeshComponent.h" 
#include "Components/ActorComponent.h"
#include "Engine/World.h"
#include "TankAimComponent.generated.h"

//Enum Aim State
UENUM()
enum class EFiringStatus : uint8
{
	Reload,
	Aiming,
	Locked
};

class UTankBarrel;
class UTankTurret;
class AProjectile;


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANKS_04_API UTankAimComponent : public UActorComponent
{
	GENERATED_BODY()

public:	

	UFUNCTION(BlueprintCallable, Category = "Setup")
		void Initialise(UTankBarrel * TankBarrel, UTankTurret * TankTurret);

	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = "Firing")
		void Fire();

private:
	UTankAimComponent();

	void MoveBarrelTowards(FVector AimDirection);


	UTankBarrel * TankBarrel = nullptr;
	UTankTurret * TankTurret = nullptr;

	UPROPERTY(EditAnywhere, Category = "Firing")
		float LaunchSpeed = 4000.f;

	UPROPERTY(EditAnywhere, Category = "Setup")
		float ReloadTimeInSeconds = 3.f;

	UPROPERTY(EditAnywhere, Category = "Setup")
		TSubclassOf<AProjectile> ProjectileBlueprint;

	double LastFireTime = 0.f;


protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
		EFiringStatus FiringStatus = EFiringStatus::Reload;

};
