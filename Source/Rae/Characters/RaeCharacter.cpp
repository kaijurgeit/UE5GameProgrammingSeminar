// Fill out your copyright notice in the Description page of Project Settings.


#include "RaeCharacter.h"

#include "EnhancedInputComponent.h"
#include "Components/HeroComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Interfaces/Interact.h"

ARaeCharacter::ARaeCharacter()
{
	HeroComponent = CreateDefaultSubobject<UHeroComponent>(TEXT("HeroComponent"));
	InteractionSphere = CreateDefaultSubobject<USphereComponent>("Interaction Sphere");
	InteractionSphere->SetupAttachment(RootComponent);
	InteractionSphere->SetCollisionProfileName("Interact");
	InteractionSphere->SetSphereRadius(100.f);
	InteractionSphere->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnBeginCapsuleOverlap);
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


void ARaeCharacter::OnBeginCapsuleOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
		
	if (IInteract* Interactable = Cast<IInteract>(OtherActor))
	{
		Interactable->Exec
	}
}