// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/World.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"


class UTankBarrel;
class UTankAimComponent;
class UTankMovementComponent;
class AProjectile;

UCLASS()
class BATTLETANKS_04_API ATank : public APawn
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrelReference(UTankBarrel* BarrelToSet);

	UFUNCTION(BlueprintCallable, Category = Setup)
		void SetTurretReference(UTankTurret* TurretToSet);

	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable)
		void Fire();
private:
	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, Category = Setup)
		float ReloadTimeInSeconds = 3.f;

	UPROPERTY(EditAnywhere, Category = Firing)
		float LaunchSpeed = 4000.f;

	UPROPERTY(EditAnywhere, Category = Setup)
		TSubclassOf<AProjectile> ProjectileBlueprint;

	UTankBarrel* Barrel = nullptr;
	
	double LastFireTime = 0.f;

protected:
<<<<<<< HEAD
	UPROPERTY(BlueprintReadOnly)
	UTankAimComponent * TankAimComponent = nullptr;

	UPROPERTY(BlueprintReadOnly)
		UTankMovementComponent* TankMovementComponent = nullptr;
=======
	UFUNCTION(BlueprintReadOnly)
	UTankAimComponent * TankAimComponent = nullptr;

	UFUNCTION(BlueprintReadOnly)
		UTankMovementComponent * TankMovementComponent = nullptr;

>>>>>>> a7e7791aecd14aba1a21a85151cec33ae293f663
};
