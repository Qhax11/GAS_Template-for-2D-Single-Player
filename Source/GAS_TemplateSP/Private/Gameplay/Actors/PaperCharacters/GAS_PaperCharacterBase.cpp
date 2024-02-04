// Qhax's GAS Template for 2D SinglePlayer


#include "Gameplay/Actors/PaperCharacters/GAS_PaperCharacterBase.h"

AGAS_PaperCharacterBase::AGAS_PaperCharacterBase()
{ 
	AbilitySystem = CreateDefaultSubobject<UGAS_AbilitySystemComponent>(TEXT("GAS_AbilitySystemComponent"));
}

UAbilitySystemComponent* AGAS_PaperCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystem;
}


