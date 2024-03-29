// Qhax's GAS Template for 2D SinglePlayer


#include "Gameplay/Actors/PaperCharacters/GAS_PaperHeroBase.h"

AGAS_PaperHeroBase::AGAS_PaperHeroBase()
{
    // Create a camera boom (pulls in towards the player if there is a collision)
    CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
    CameraBoom->SetupAttachment(RootComponent);
    CameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character 
    CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

    // Create a follow camera
    FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
    FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
    FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm
}

void AGAS_PaperHeroBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
    EnhancedInputComp = Cast<UEnhancedInputComponent>(PlayerInputComponent);
}

void AGAS_PaperHeroBase::PossessedBy(AController* NewController)
{
    if (AbilitySystem) 
    {
        AbilitySystem->GiveAbilitySet(AbilitySet);
    }
}
