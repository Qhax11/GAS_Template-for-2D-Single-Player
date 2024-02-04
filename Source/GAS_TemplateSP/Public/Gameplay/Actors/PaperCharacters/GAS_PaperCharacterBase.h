// Qhax's GAS Template for 2D SinglePlayer

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "AbilitySystemInterface.h"
#include "Gameplay/Components/GAS_AbilitySystemComponent.h"
#include "GAS_PaperCharacterBase.generated.h"


UCLASS()
class GAS_TEMPLATESP_API AGAS_PaperCharacterBase : public APaperCharacter, public IAbilitySystemInterface 
{
	GENERATED_BODY()
	
public:
	AGAS_PaperCharacterBase();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Abilities, meta = (AllowPrivateAccess = "true"))
	UGAS_AbilitySystemComponent* AbilitySystem;
	
	UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	UPROPERTY(EditAnywhere)
	UGAS_GameplayAbilitySet* AbilitySet;

};
