// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Math/UnrealMathUtility.h"
#include "Containers/UnrealString.h"
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

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		void RandomObjective(int32 MinTile, int32 MaxTile, int32 MaxObj);
};
