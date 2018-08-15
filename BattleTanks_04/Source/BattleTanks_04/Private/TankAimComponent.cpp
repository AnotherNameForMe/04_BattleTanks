// Copyright EmbraceIT Ltd.
#include "TankAimComponent.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "Projectile.h"
#include "BattleTanks_04Classes.h"






// Sets default values for this component's properties
UTankAimComponent::UTankAimComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	//bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UTankAimComponent::BeginPlay()
{
	Super::BeginPlay();

	LastFireTime = FPlatformTime::Seconds();

}

void UTankAimComponent::Initialise(UTankBarrel * TankBarrelToSet, UTankTurret * TankTurretToSet)
{
	if (!TankBarrelToSet || !TankTurretToSet) { return; }
	TankBarrel = TankBarrelToSet;
	TankTurret = TankTurretToSet;
}


void UTankAimComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if ((FPlatformTime::Seconds() - LastFireTime) < ReloadTimeInSeconds)
	{
		FiringStatus = EFiringStatus::Reload;
	}
	else if(bIsBarrelMoving())
	{
		FiringStatus = EFiringStatus::Aiming;
	}
	else
	{
		FiringStatus = EFiringStatus::Locked;

	}

}

bool UTankAimComponent::bIsBarrelMoving() const
{
	if (!ensure(TankBarrel)) { return false; }
	auto BarrelForward = TankBarrel->GetForwardVector();
		return !BarrelForward.Equals(AimDirection, 0.01f);
}

void UTankAimComponent::AimAt(FVector OUTHitLocation)
{

	if (!ensure(TankBarrel)) { return; }


	FVector OUTLaunchVelocity;
	FVector StartLocation = TankBarrel->GetSocketLocation(FName("Projectile"));
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity(this, OUTLaunchVelocity, StartLocation, OUTHitLocation, LaunchSpeed, false, 0.f, 0.f, ESuggestProjVelocityTraceOption::DoNotTrace);

	if (bHaveAimSolution)
	{
		AimDirection = OUTLaunchVelocity.GetSafeNormal();
		MoveBarrelTowards(AimDirection);
	}
	
		return;
	
}

void UTankAimComponent::MoveBarrelTowards(FVector AimDirection)
{
	if (!ensure(TankBarrel) || !ensure(TankTurret)) { return; }
	auto BarrelRotator = TankBarrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;

	TankBarrel->Elevate(DeltaRotator.Pitch);
	TankTurret->TurretRotation(DeltaRotator.Yaw);
}


void UTankAimComponent::Fire()
{
	
	if (FiringStatus != EFiringStatus::Reload)
	{
		if (!ensure(TankBarrel)) { return; }
		if (!ensure(ProjectileBlueprint)) { return; }
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint, TankBarrel->GetSocketLocation(FName("Projectile")), TankBarrel->GetSocketRotation(FName("Projectile")));

		Projectile->LaunchProjectile(LaunchSpeed);
	}
}
