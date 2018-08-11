// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "TankTrack.h"
#include "BattleTanks_04.h"

void UTankMovementComponent::Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
	if (!LeftTrackToSet || !RightTrackToSet) { return; }
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}

void UTankMovementComponent::RequestDirectMove(const FVector & MoveVelocity, bool bForceMaxSpeed)
{
	auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto AIMoveIntentions = MoveVelocity.GetSafeNormal();
	auto RotateThrow = FVector::CrossProduct(TankForward, AIMoveIntentions).Z;
	auto ForwardThrow = FVector::DotProduct(TankForward, AIMoveIntentions);
	IntendMoveForward(ForwardThrow);
	IntendRotate(RotateThrow);
}


void UTankMovementComponent::IntendMoveForward(float Throw)
{
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);

}
void UTankMovementComponent::IntendRotate(float Throw)
{
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);

}




