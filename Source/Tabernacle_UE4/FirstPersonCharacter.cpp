// Fill out your copyright notice in the Description page of Project Settings.


#include "FirstPersonCharacter.h"

// Sets default values
AFirstPersonCharacter::AFirstPersonCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFirstPersonCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AFirstPersonCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFirstPersonCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Player Movement
	PlayerInputComponent->BindAxis("MoveForward", this, &AFirstPersonCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AFirstPersonCharacter::MoveRight);

	// Player Camera Control
	PlayerInputComponent->BindAxis("Turn", this, &AFirstPersonCharacter::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &AFirstPersonCharacter::AddControllerPitchInput);

	// Interact
	PlayerInputComponent->BindAction("Interact", IE_Pressed, this, &AFirstPersonCharacter::Interact);

	// Turn Reticule On and Off
	PlayerInputComponent->BindAction("CamReticule", IE_Pressed, this, &AFirstPersonCharacter::SwitchReticule);

	// Pause
	PlayerInputComponent->BindAction("Pause", IE_Pressed, this, &AFirstPersonCharacter::PauseGame);
}

void AFirstPersonCharacter::MoveForward(float value)
{
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
	AddMovementInput(Direction, value);
}

void AFirstPersonCharacter::MoveRight(float value)
{
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
	AddMovementInput(Direction, value);
}

void AFirstPersonCharacter::Interact()
{
	check(GEngine != nullptr);

	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("Interact"));
}

void AFirstPersonCharacter::SwitchReticule()
{
	check(GEngine != nullptr);

	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("Switch Reticule"));
}

void AFirstPersonCharacter::PauseGame()
{
	check(GEngine != nullptr);

	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("Pause"));
}