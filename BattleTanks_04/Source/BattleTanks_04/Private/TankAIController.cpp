// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include"TankAimComponent.h"
#include "Tank.h"
#include "BattleTanks_04Classes.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	
}

void ATankAIController::SetPawn(APawn * InPawn)
{
	Super::SetPawn(InPawn);
	if (InPawn)
	{
		auto PossessedTank = Cast<ATank>(InPawn);
		if (!(PossessedTank)) { return; }
		PossessedTank->OnDeath.AddUniqueDynamic(this, &ATankAIController::OnTanksDeath);
	}
}

void ATankAIController::OnTanksDeath()
{
	if (!GetPawn()) { return; }
	GetPawn()->DetachFromControllerPendingDestroy();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControlledTank = GetPawn();

	if (!(PlayerTank && ControlledTank)) { return; }
	
		MoveToActor(PlayerTank, AcceptanceRadius);

		auto AimingComp = ControlledTank->FindComponentByClass<UTankAimComponent>();
		AimingComp->AimAt(PlayerTank->GetActorLocation());
		
		if (AimingComp->GetFiringSatus() == EFiringStatus::Locked)
		{
			AimingComp->Fire();
		}
	
}





