// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Math/UnrealMathUtility.h"
#include "Containers/UnrealString.h"
#include "Kismet/GameplayStatics.h"
#include "ObjectivesGenerator.generated.h"

UCLASS()
class TABERNACLE_UE4_API AObjectivesGenerator : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AObjectivesGenerator();

	UPROPERTY(EditAnywhere)
		TArray<FString> Objectives;

	UPROPERTY(EditAnywhere)
		int32 MinTileNum;

	UPROPERTY(EditAnywhere)
		int32 MaxTileNum;

	UPROPERTY(EditAnywhere)
		int32 MaxObjectiveNum;

	UPROPERTY(EditAnywhere)
		TArray<FName> LevelNames;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		void RandomObjective(int32 MinTile, int32 MaxTile, int32 MaxObj);

	UFUNCTION()
		void SpawnMap(int32 Path1Seed, int32 Path2Seed, int32 Path3Seed, int32 Path4Seed, TArray<FName> namesOfLevels);

	UFUNCTION()
		void LoadLevel4();

	UFUNCTION()
		void LoadLevel6();

	UFUNCTION()
		void LoadLevel8();

	UFUNCTION()
		void LoadLevel10();

	UFUNCTION()
		void LoadLevel12();

	UFUNCTION()
		void LoadLevel14();

	UFUNCTION()
		void LoadLevel16();
};
