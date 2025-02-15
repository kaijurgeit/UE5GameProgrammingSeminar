// Fill out your copyright notice in the Description page of Project Settings.


#include "RaeCharacter.h"

#include "EnhancedInputComponent.h"

void ARaeCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Started, this, &ThisClass::Interact);
	}
}

void ARaeCharacter::Interact(const FInputActionValue& Value)
{
	// Impl. follows
}
