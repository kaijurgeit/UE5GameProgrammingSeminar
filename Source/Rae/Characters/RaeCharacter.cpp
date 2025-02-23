// Fill out your copyright notice in the Description page of Project Settings.


#include "RaeCharacter.h"

#include "EnhancedInputComponent.h"
#include "Components/HeroComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

ARaeCharacter::ARaeCharacter()
{
	HeroComponent = CreateDefaultSubobject<UHeroComponent>(TEXT("HeroComponent"));
}

void ARaeCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Started, this, &ThisClass::Interact);
	}
}

void ARaeCharacter::Die()
{
	if(bIsDead || !DeathAnimMontage) return;

	bIsDead = true;
	
	if(UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance())
	{
		AnimInstance->Montage_Play(DeathAnimMontage);
	}
	GetCharacterMovement()->DisableMovement();
}

void ARaeCharacter::Interact(const FInputActionValue& Value)
{
	// Impl. follows
}
