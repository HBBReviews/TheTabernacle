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

	RandomObjective(MinTileNum, MaxTileNum);
}

// Called every frame
void AObjectivesGenerator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AObjectivesGenerator::RandomObjective(int32 MinTile, int32 MaxTile)
{
	// Randomly Generated Seed for the Tile Location of Objective
	int32 Tile1Seed = FMath::RandRange(MinTile, 7);
	int32 Tile2Seed = FMath::RandRange(MinTile, 7);

	// Randomly Generated Objective Type
	int32 ObjectiveSeed = FMath::RandRange(0, Objectives.Num());

	FString tileSeedString = FString::FromInt(Tile1Seed);

	// Initialize and Set Mission Objectives
	InitObjectives(tileSeedString);
	Objective = Objectives[ObjectiveSeed];

	check(GEngine != nullptr);

	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, Objective);

	SpawnMap(Tile1Seed, Tile2Seed, Tile1Seed, Tile1Seed, LevelNames);
}

void AObjectivesGenerator::SpawnMap(int32 Path1Seed, int32 Path2Seed, int32 Path3Seed, int32 Path4Seed, TArray<FName> namesOfLevels)
{
	check(GEngine != nullptr);

	// Path One (Tiles 4 -> 16)
	if (Path1Seed >= 1)
	{
		LoadLevel4();
	}

	if (Path1Seed >= 2)
	{
		LoadLevel6();
	}

	if (Path1Seed >= 3)
	{
		LoadLevel14();
	}

	if (Path1Seed >= 4)
	{
		LoadLevel8();
	}

	if (Path1Seed >= 5)
	{
		LoadLevel12();
	}

	if (Path1Seed >= 6)
	{
		LoadLevel10();
	}

	if (Path1Seed >= 7)
	{
		LoadLevel16();
	}

	// Path Two
	if (Path2Seed >= 1)
	{
		LoadLevel5();
	}

	if (Path2Seed >= 2)
	{
		LoadLevel7();
	}

	if (Path2Seed >= 3)
	{
		LoadLevel9();
	}

	if (Path2Seed >= 4)
	{
		LoadLevel11();
	}

	if (Path2Seed >= 5)
	{
		LoadLevel13();
	}

	if (Path2Seed >= 6)
	{
		LoadLevel15();
	}

	// Path Three: NOT USED

	// Path Four: NOT USED
}

void AObjectivesGenerator::InitObjectives(FString tileString)
{
	// Objective 1
	Objectives.Add("Pick Up Cube");

	// Objective 2
	Objectives.Add("Pick Up Cube Under Timer");

	// Objective 3
	Objectives.Add("Shoot Enemies Under Timer");

	// Objective 4
	// Includes Tile Number
	FString Objective4 = "Run to Tile ";
	FString Objective4_2 = " Under a Timer";

	Objective4 += tileString;
	Objective4 += Objective4_2;

	Objectives.Add(Objective4);

	// Objective 5
	Objectives.Add("Find Map from Mystery Chest");
}

FString AObjectivesGenerator::GetObjective()
{
	return Objective;
}

void AObjectivesGenerator::LoadLevel4()
{
	++LatentInfo.UUID;
	UGameplayStatics::LoadStreamLevel(this, LevelNames[4], true, true, LatentInfo);
}

void AObjectivesGenerator::LoadLevel5()
{
	++LatentInfo.UUID;
	UGameplayStatics::LoadStreamLevel(this, LevelNames[5], true, true, LatentInfo);
}

void AObjectivesGenerator::LoadLevel6()
{
	++LatentInfo.UUID;
	UGameplayStatics::LoadStreamLevel(this, LevelNames[6], true, true, LatentInfo);
}

void AObjectivesGenerator::LoadLevel7()
{
	++LatentInfo.UUID;
	UGameplayStatics::LoadStreamLevel(this, LevelNames[7], true, true, LatentInfo);
}

void AObjectivesGenerator::LoadLevel8()
{
	++LatentInfo.UUID;
	UGameplayStatics::LoadStreamLevel(this, LevelNames[8], true, true, LatentInfo);
}

void AObjectivesGenerator::LoadLevel9()
{
	++LatentInfo.UUID;
	UGameplayStatics::LoadStreamLevel(this, LevelNames[9], true, true, LatentInfo);
}

void AObjectivesGenerator::LoadLevel10()
{
	++LatentInfo.UUID;
	UGameplayStatics::LoadStreamLevel(this, LevelNames[10], true, true, LatentInfo);
}

void AObjectivesGenerator::LoadLevel11()
{
	++LatentInfo.UUID;
	UGameplayStatics::LoadStreamLevel(this, LevelNames[11], true, true, LatentInfo);
}

void AObjectivesGenerator::LoadLevel12()
{
	++LatentInfo.UUID;
	UGameplayStatics::LoadStreamLevel(this, LevelNames[12], true, true, LatentInfo);
}

void AObjectivesGenerator::LoadLevel13()
{
	++LatentInfo.UUID;
	UGameplayStatics::LoadStreamLevel(this, LevelNames[13], true, true, LatentInfo);
}

void AObjectivesGenerator::LoadLevel14()
{
	++LatentInfo.UUID;
	UGameplayStatics::LoadStreamLevel(this, LevelNames[14], true, true, LatentInfo);
}

void AObjectivesGenerator::LoadLevel15()
{
	++LatentInfo.UUID;
	UGameplayStatics::LoadStreamLevel(this, LevelNames[15], true, true, LatentInfo);
}

void AObjectivesGenerator::LoadLevel16()
{
	++LatentInfo.UUID;
	UGameplayStatics::LoadStreamLevel(this, LevelNames[16], true, true, LatentInfo);
}