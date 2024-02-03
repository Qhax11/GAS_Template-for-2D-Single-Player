// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GAS_TemplateSP/Gameplay/Actors/PaperCharacter/GAS_PaperCharacter.h"

#include "AC_Moving2D.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAS_TEMPLATESP_API UAC_Moving2D : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAC_Moving2D();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	AGAS_PaperCharacter* PaperCharacter;

	UPROPERTY(EditAnywhere)
	const UInputAction* LeftInputAction;

	UPROPERTY(EditAnywhere)
	const UInputAction* RightInputAction;

	// Mouse + Gamepad
	void MoveLeft(const FInputActionValue& Value);
		
	// Mouse + Gamepad
	void MoveRight(const FInputActionValue& Value);
};
