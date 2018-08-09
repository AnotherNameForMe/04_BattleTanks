// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimComponent.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "BattleTanks_04Classes.h"



// Sets default values for this component's properties
UTankAimComponent::UTankAimComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}
void UTankAimComponent::SetBarrelRefference(UTankBarrel* BarrelToSet)
{
	if (!BarrelToSet) { return; }
	Barrel = BarrelToSet;
}

void UTankAimComponent::SetTurretReference(UTankTurret * TurretToSet)
{
	if (!TurretToSet){ return; }
	Turret = TurretToSet;
}


void UTankAimComponent::AimAt(FVector OUTHitLocation, float LaunchSpeed)
{

	if (!Barrel) { return; }


	FVector OUTLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity(this, OUTLaunchVelocity, StartLocation, OUTHitLocation, LaunchSpeed, false, 0.f, 0.f, ESuggestProjVelocityTraceOption::DoNotTrace);

	if (bHaveAimSolution)
	{
		auto AimDirection = OUTLaunchVelocity.GetSafeNormal();
		auto TankName = GetOwner()->GetName();
		MoveBarrelTowards(AimDirection);
	}
	else
	{

		return;
	}
}

void UTankAimComponent::MoveBarrelTowards(FVector AimDirection)
{
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;

	Barrel->Elevate(DeltaRotator.Pitch);
	Turret->TurretRotation(DeltaRotator.Yaw);
}



