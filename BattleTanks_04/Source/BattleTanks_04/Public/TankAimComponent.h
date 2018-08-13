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

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANKS_04_API UTankAimComponent : public UActorComponent
{
	GENERATED_BODY()

public:	

	// Sets default values for this component's properties
	UTankAimComponent();

	void SetBarrelRefference(UTankBarrel* BarrelToSet);

	void AimAt(FVector OUTHitLocation, float LaunchSpeed);

	void SetTurretReference(UTankTurret* TurretToSet);

private:

	UTankBarrel * Barrel = nullptr;

	UTankTurret * Turret = nullptr;

	void MoveBarrelTowards(FVector AimDirection);

	void MoveTurretTowards(FRotator RotateDirection);

protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
		EFiringStatus FiringStatus = EFiringStatus::Reload;

};
