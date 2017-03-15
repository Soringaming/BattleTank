// Copyright (C) 2017 Soringaming

#include "BattleTank.h"
#include "TankPlayerController.h"



ATank* ATankPlayerController::GetControlldTank() const
{
	return Cast<ATank>(GetPawn());
}


