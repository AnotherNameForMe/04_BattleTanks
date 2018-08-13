// Copyright EmbraceIT Ltd.
#include "TankAimComponent.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "BattleTanks_04Classes.h"


void UTankAimComponent::Initialise(UTankBarrel * TankBarrelToSet, UTankTurret * TankTurretToSet)
{
	if (!TankBarrelToSet || !TankTurretToSet) { return; }
	TankBarrel = TankBarrelToSet;
	TankTurret = TankTurretToSet;
}

// Sets default values for this component's properties
UTankAimComponent::UTankAimComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}





void UTankAimComponent::AimAt(FVector OUTHitLocation, float LaunchSpeed)
{

	if (!ensure(TankBarrel)) { return; }


	FVector OUTLaunchVelocity;
	FVector StartLocation = TankBarrel->GetSocketLocation(FName("Projectile"));
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity(this, OUTLaunchVelocity, StartLocation, OUTHitLocation, LaunchSpeed, false, 0.f, 0.f, ESuggestProjVelocityTraceOption::DoNotTrace);

	if (bHaveAimSolution)
	{
		auto AimDirection = OUTLaunchVelocity.GetSafeNormal();
		auto TankName = GetOwner()->GetName();
		MoveBarrelTowards(AimDirection);
	}
	
		return;
	
}

void UTankAimComponent::MoveBarrelTowards(FVector AimDirection)
{
	if (ensure(TankBarrel)|| ensure(TankTurret)) { return; }
	auto BarrelRotator = TankBarrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;

	TankBarrel->Elevate(DeltaRotator.Pitch);
	TankTurret->TurretRotation(DeltaRotator.Yaw);
}

void UTankAimComponent::MoveTurretTowards(FRotator RotateDirection)
{

}



