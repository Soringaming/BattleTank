// Copyright (C) 2017 Soringaming

#pragma once

#include "Tank.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

public:
	
	ATank* GetAITank() const;

	virtual void BeginPlay() override;
	
	
};
