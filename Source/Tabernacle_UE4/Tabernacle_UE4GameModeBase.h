// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Tabernacle_UE4GameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class TABERNACLE_UE4_API ATabernacle_UE4GameModeBase : public AGameModeBase
{
	GENERATED_BODY()

		virtual void StartPlay() override;
};
