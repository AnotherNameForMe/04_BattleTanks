// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"


UCLASS()
class BATTLETANKS_04_API ATank : public APawn
{
	GENERATED_BODY()

public:
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent, class AController * EventInstigator, AActor * DamageCauser) override;
	ATank();
	
private:
	UPROPERTY(EditDefaultsOnly)
	int32 StartingHealth = 100;

	UPROPERTY(VisibleAnywhere)
	int32 CurrentHealth = StartingHealth;
};
