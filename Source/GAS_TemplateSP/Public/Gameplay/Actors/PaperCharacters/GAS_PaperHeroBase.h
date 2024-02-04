// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Gameplay/Actors/PaperCharacters/GAS_PaperCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "EnhancedInputComponent.h"
#include "GAS_PaperHeroBase.generated.h"


UCLASS()
class GAS_TEMPLATESP_API AGAS_PaperHeroBase : public AGAS_PaperCharacter
{
	GENERATED_BODY()

public:
	AGAS_PaperHeroBase();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UEnhancedInputComponent* EnhancedInputComp;

protected:

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "GAS|Camera")
	class USpringArmComponent* CameraBoom;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "GAS|Camera")
	class UCameraComponent* FollowCamera;
	
};
