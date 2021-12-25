// Fill out your copyright notice in the Description page of Project Settings.

#include "ObjectivesGenerator.h"

// Sets default values
AObjectivesGenerator::AObjectivesGenerator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AObjectivesGenerator::BeginPlay()
{
	Super::BeginPlay();
	
	RandomObjective(MinTileNum, MaxTileNum, MaxObjectiveNum);
}

// Called every frame
void AObjectivesGenerator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AObjectivesGenerator::RandomObjective(int32 MinTile, int32 MaxTile, int32 MaxObj)
{
	// Randomly Generated Seed for the Tile Location of Objective
	int32 TileSeed = FMath::RandRange(MinTile, MaxTile);

	// Randomly Generated Objective Type
	int32 ObjectiveSeed = FMath::RandRange(0, MaxObj);

	FString objective = Objectives[ObjectiveSeed];
	
	check(GEngine != nullptr);

	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Black, objective);
}


