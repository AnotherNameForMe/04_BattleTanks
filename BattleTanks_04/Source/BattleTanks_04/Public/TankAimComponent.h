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

	UFUNCTION(BlueprintCallable, Category = "Setup")
		void Initialise(UTankBarrel * TankBarrel, UTankTurret * TankTurret);

	void AimAt(FVector OUTHitLocation, float LaunchSpeed);

private:
	UTankAimComponent();

	UTankBarrel * TankBarrel = nullptr;

	UTankTurret * TankTurret = nullptr;

	void MoveBarrelTowards(FVector AimDirection);

	void MoveTurretTowards(FRotator RotateDirection);

protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
		EFiringStatus FiringStatus = EFiringStatus::Reload;

};
