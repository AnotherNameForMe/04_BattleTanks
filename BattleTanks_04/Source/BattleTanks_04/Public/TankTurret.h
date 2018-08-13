// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/World.h"
#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent), hidecategories = ("Collision"))
class BATTLETANKS_04_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void TurretRotation(float RelativeSpeed);
	
private:
	UPROPERTY(EditAnywhere, Category = "Setup")
		float MaxDegreePerSecond = 30.f;
};
