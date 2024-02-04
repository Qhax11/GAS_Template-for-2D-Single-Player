// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/Actors/PaperCharacters/GAS_PaperCharacterBase.h"

AGAS_PaperCharacterBase::AGAS_PaperCharacterBase()
{ 
	AbilitySystem = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
}

UAbilitySystemComponent* AGAS_PaperCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystem;
}


