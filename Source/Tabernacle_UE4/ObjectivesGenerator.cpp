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
	int32 TileSeed = FMath::RandRange(MinTile, 7);

	// Randomly Generated Objective Type
	int32 ObjectiveSeed = FMath::RandRange(0, MaxObj);

	FString objective = Objectives[ObjectiveSeed];
	FString tileSeedString = FString::FromInt(TileSeed);

	check(GEngine != nullptr);

	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Black, tileSeedString);

	SpawnMap(TileSeed, TileSeed, TileSeed, TileSeed, LevelNames);
}

void AObjectivesGenerator::SpawnMap(int32 Path1Seed, int32 Path2Seed, int32 Path3Seed, int32 Path4Seed, TArray<FName> namesOfLevels)
{
	check(GEngine != nullptr);

	// Path One (Tiles 4 -> 16)
	if (Path1Seed >= 1)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Black, "Spawn Tile 4");
		LoadLevel4();
	}

	if (Path1Seed >= 2)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Black, "Spawn Tile 6");
		LoadLevel6();
	}

	if (Path1Seed >= 3)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Black, "Spawn Tile 14");
		LoadLevel14();
	}

	if (Path1Seed >= 4)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Black, "Spawn Tile 8");
		LoadLevel8();
	}

	if (Path1Seed >= 5)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Black, "Spawn Tile 12");
		LoadLevel12();
	}

	if (Path1Seed >= 6)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Black, "Spawn Tile 10");
		LoadLevel10();
	}

	if (Path1Seed >= 7)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Black, "Spawn Tile 16");
		LoadLevel16();
	}
}

void AObjectivesGenerator::LoadLevel4()
{
	FLatentActionInfo LatentInfo;
	UGameplayStatics::LoadStreamLevel(this, LevelNames[4], true, true, LatentInfo);
}

void AObjectivesGenerator::LoadLevel6()
{
	FLatentActionInfo LatentInfo;
	UGameplayStatics::LoadStreamLevel(this, LevelNames[6], true, true, LatentInfo);
}

void AObjectivesGenerator::LoadLevel8()
{
	FLatentActionInfo LatentInfo;
	UGameplayStatics::LoadStreamLevel(this, LevelNames[8], true, true, LatentInfo);
}

void AObjectivesGenerator::LoadLevel10()
{
	FLatentActionInfo LatentInfo;
	UGameplayStatics::LoadStreamLevel(this, LevelNames[10], true, true, LatentInfo);
}

void AObjectivesGenerator::LoadLevel12()
{
	FLatentActionInfo LatentInfo;
	UGameplayStatics::LoadStreamLevel(this, LevelNames[12], true, true, LatentInfo);
}

void AObjectivesGenerator::LoadLevel14()
{
	FLatentActionInfo LatentInfo;
	UGameplayStatics::LoadStreamLevel(this, LevelNames[14], true, true, LatentInfo);
}

void AObjectivesGenerator::LoadLevel16()
{
	FLatentActionInfo LatentInfo;
	UGameplayStatics::LoadStreamLevel(this, LevelNames[16], true, true, LatentInfo);
}