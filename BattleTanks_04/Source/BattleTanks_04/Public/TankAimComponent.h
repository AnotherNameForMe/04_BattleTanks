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
	Locked,
	OutOfAmmo
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

	EFiringStatus GetFiringSatus() const;

	UFUNCTION(BlueprintCallable, Category = "Firing")
	int GetRoundsLeft() const;

private:
	UTankAimComponent();


	virtual void BeginPlay()override;

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;


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

	bool bIsBarrelMoving() const;

	FVector AimDirection;

	int RoundsLeft = 3;


protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
		EFiringStatus FiringStatus = EFiringStatus::Reload;

};
