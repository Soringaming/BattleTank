// Copyright (C) 2017 Soringaming

#include "BattleTank.h"
#include "TankAIController.h"

// This function is called at runtime
void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto PlayerTank = GetPlayerTank();

	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("TankAIContoller can't find player tank!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("TankAIController found player: %s"), *(PlayerTank->GetName()));
	}

}

void ATankAIController::Tick( float DeltaTime )
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank())
	{
		// TODO Move towards the player

		// Aim towards the player
		GetAITank()->AimAt(GetPlayerTank()->GetActorLocation());

		// Fire if ready
	}
}

// Return a pawn that is casted to "ATank"
ATank* ATankAIController::GetAITank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	return Cast<ATank>(PlayerPawn);
}
