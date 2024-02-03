// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystemComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "EnhancedInputComponent.h"
#include "GAS_PaperCharacter.generated.h"

/**
 * 
 */
UCLASS()
class GAS_TEMPLATESP_API AGAS_PaperCharacter : public APaperCharacter, public IAbilitySystemInterface 
{
	GENERATED_BODY()
	
public:

	AGAS_PaperCharacter();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Abilities, meta = (AllowPrivateAccess = "true"))
	UAbilitySystemComponent* AbilitySystem;
	
	UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UEnhancedInputComponent* EnhancedInputComp;

protected:

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "GAS|Camera")
	class USpringArmComponent* CameraBoom;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "GAS|Camera")
	class UCameraComponent* FollowCamera;
	
};
