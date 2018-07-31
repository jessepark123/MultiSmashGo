// Fill out your copyright notice in the Description page of Project Settings.

#include "CharacterBase.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Engine.h"


// Sets default values
ACharacterBase::ACharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bCanEverTick = true;
	TapTherhold = 0.25f;
	Dashdistance = 500.0f;
	addforce = GetActorForwardVector();
	LastTaptime = 0.0f;
	Deltatime = 0.0f;
	Movespeed = 10.0f;
}

// Called when the game starts or when spawned
void ACharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	this->SetActorLocation(FVector(1206.637085, this->GetActorLocation().Y, this->GetActorLocation().Z));

}

// Called to bind functionality to input
void ACharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMyCharactertest::MoveRight);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
}

void ACharacterBase::MoveRight(float amount)
{
	if (Controller != nullptr && !FMath::IsNearlyZero(amount))
	{

		AddMovementInput(this->GetActorForwardVector(), amount*Movespeed, false);
	}
}

void ACharacterBase::doubletap()
{
	LaunchCharacter(FVector(addforce.X*Dashdistance, 0, 0), false, true);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Dashing"));
}

void ACharacterBase::Dashinput()
{
}

void ACharacterBase::Dashrelease()
{
}

