// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.


#include "Tabernacle_UE4GameModeBase.h"

void ATabernacle_UE4GameModeBase::StartPlay()
{
	Super::StartPlay();

	check(GEngine != nullptr);

	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Hello world!"));
}