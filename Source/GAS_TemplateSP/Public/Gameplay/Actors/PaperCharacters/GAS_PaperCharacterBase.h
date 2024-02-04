// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystemComponent.h"
#include "GAS_PaperCharacterBase.generated.h"


UCLASS()
class GAS_TEMPLATESP_API AGAS_PaperCharacterBase : public APaperCharacter, public IAbilitySystemInterface 
{
	GENERATED_BODY()
	
public:
	AGAS_PaperCharacterBase();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Abilities, meta = (AllowPrivateAccess = "true"))
	UAbilitySystemComponent* AbilitySystem;
	
	UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	
};
