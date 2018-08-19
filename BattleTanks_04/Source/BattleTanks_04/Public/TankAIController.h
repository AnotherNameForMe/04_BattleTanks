// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "TankAIController.generated.h"


UCLASS()
class BATTLETANKS_04_API ATankAIController : public AAIController
{
	GENERATED_BODY()

private:
	virtual void BeginPlay() override;

	virtual void SetPawn(APawn* InPawn) override;

	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		void OnTanksDeath();
	
protected:
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		float AcceptanceRadius = 3000;
};
