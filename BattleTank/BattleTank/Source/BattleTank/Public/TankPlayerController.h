// Copyright (C) 2017 Soringaming

#pragma once

#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" // This has to be the last Pre-Processor directive!

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:

private:

	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = 0.5;

	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = 0.3333;

	UPROPERTY(EditAnywhere)
	float LineTraceRange = 1000000;

	// Called on runtime
	virtual void BeginPlay() override;

	// Called every frame to "tick"
	virtual void Tick( float DeltaTime ) override;

	// Returns a reference to the current tank
	ATank* GetControlledTank() const;

	/*
	Start moving the tank barrel so that a shot would hit where
	the crosshair intersects with the world
	*/
	void AimTowardsCrosshair();

	// Return an out parameter, true if hit landscape
	bool GetSightRayHitLocation(FVector& HitLocation) const;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;
	
};
