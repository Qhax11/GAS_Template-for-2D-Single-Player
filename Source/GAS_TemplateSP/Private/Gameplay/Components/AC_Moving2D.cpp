// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/Components/AC_Moving2D.h"
#include "GameFramework/PlayerController.h"

// Sets default values for this component's properties
UAC_Moving2D::UAC_Moving2D()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

}

// Called when the game starts
void UAC_Moving2D::BeginPlay()
{
	Super::BeginPlay();

	PaperCharacter = Cast<AGAS_PaperHeroBase>(GetOwner());
	if (!PaperCharacter)
	{
		UE_LOG(LogTemp, Warning, TEXT("PaperCharacter is null! (This message comes from %s)"), *this->GetName());
		return;
	}

	if (LeftInputAction && RightInputAction)
	{
		if (PaperCharacter->EnhancedInputComp) 
		{
			PaperCharacter->EnhancedInputComp->BindAction(LeftInputAction, ETriggerEvent::Triggered, this, &UAC_Moving2D::MoveLeft);
			PaperCharacter->EnhancedInputComp->BindAction(RightInputAction, ETriggerEvent::Triggered, this, &UAC_Moving2D::MoveRight);
			PaperCharacter->EnhancedInputComp->BindAction(JumpInputAction, ETriggerEvent::Triggered, this, &UAC_Moving2D::Jump);
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Input actions are null! (This message comes from %s)"), *this->GetName());
	}
}

// Called every frame
void UAC_Moving2D::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UAC_Moving2D::MoveLeft(const FInputActionValue& Value)
{
	PaperCharacter->AddMovementInput(FVector(0, -100, 0));
}

void UAC_Moving2D::MoveRight(const FInputActionValue& Value)
{
	PaperCharacter->AddMovementInput(FVector(0, 100, 0));
}

void UAC_Moving2D::Jump(const FInputActionValue& Value)
{
	PaperCharacter->Jump();
}

