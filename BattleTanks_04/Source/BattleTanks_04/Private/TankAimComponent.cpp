// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimComponent.h"
#include "BattleTanks_04Classes.h"



// Sets default values for this component's properties
UTankAimComponent::UTankAimComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}
void UTankAimComponent::SetBarrelRefference(UStaticMeshComponent* BarrelToSet)
{
	Barrel = BarrelToSet;
}


// Called when the game starts
void UTankAimComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UTankAimComponent::AimAt(FVector OUTHitLocation, float LaunchSpeed)
{

	if (!Barrel) { return; }


	FVector OUTLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));

	if (UGameplayStatics::SuggestProjectileVelocity(this,OUTLaunchVelocity,StartLocation,OUTHitLocation,LaunchSpeed, false, 0.f, 0.f, ESuggestProjVelocityTraceOption::DoNotTrace))//calculate OUTLaunchVelocity
	{
		auto AimDirection = OUTLaunchVelocity.GetSafeNormal();
		auto TankName = GetOwner()->GetName();
		UE_LOG(LogTemp, Warning, TEXT("%s Aiming at: %s"), *TankName, *AimDirection.ToString());
	}
}



