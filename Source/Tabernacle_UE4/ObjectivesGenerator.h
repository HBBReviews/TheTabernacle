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

		FString Objective;

public:
	// Sets default values for this actor's properties
	AObjectivesGenerator();

	TArray<FString> Objectives;

	UPROPERTY(EditAnywhere)
		int32 MinTileNum;

	UPROPERTY(EditAnywhere)
		int32 MaxTileNum;

	UPROPERTY(EditAnywhere)
		TArray<FName> LevelNames;

	FLatentActionInfo LatentInfo;
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		void RandomObjective(int32 MinTile, int32 MaxTile);

	UFUNCTION()
		void SpawnMap(int32 Path1Seed, int32 Path2Seed, int32 Path3Seed, int32 Path4Seed, TArray<FName> namesOfLevels);

	UFUNCTION()
		void InitObjectives(FString tileString);

	UFUNCTION(BlueprintCallable)
		FString GetObjective();

	UFUNCTION(BlueprintCallable)
		void CompleteObjective();

	UFUNCTION()
		void LoadLevel4();

	UFUNCTION()
		void LoadLevel5();

	UFUNCTION()
		void LoadLevel6();

	UFUNCTION()
		void LoadLevel7();

	UFUNCTION()
		void LoadLevel8();

	UFUNCTION()
		void LoadLevel9();

	UFUNCTION()
		void LoadLevel10();

	UFUNCTION()
		void LoadLevel11();

	UFUNCTION()
		void LoadLevel12();

	UFUNCTION()
		void LoadLevel13();

	UFUNCTION()
		void LoadLevel14();

	UFUNCTION()
		void LoadLevel15();

	UFUNCTION()
		void LoadLevel16();
};
