// Copyright (C) 2017 Jay Eggleston

#include "BattleTank.h"
#include "TankAIController.h"

// This function is called at runtime
void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto PossesedAITank = GetAITank();

	if (!PossesedAITank)
	{
		UE_LOG(LogTemp, Warning, TEXT("TankAIContoller is not controlling a tank!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("TankAIController is possesing: %s"), *(PossesedAITank->GetName()));
	}
}

// Return a pawn that is casted to "ATank"
ATank* ATankAIController::GetAITank() const
{
	return Cast<ATank>(GetPawn());
}
