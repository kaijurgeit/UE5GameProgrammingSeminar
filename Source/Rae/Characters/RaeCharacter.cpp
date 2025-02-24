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
	InteractSphere = CreateDefaultSubobject<USphereComponent>("Interaction Sphere");
	InteractSphere->SetupAttachment(RootComponent);
	InteractSphere->SetSphereRadius(200.f);
	InteractSphere->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnInteractSphereBeginOverlap);
	InteractSphere->OnComponentEndOverlap.AddDynamic(this, &ThisClass::OnInteractSphereEndOverlap);
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
	if (IInteract* Interactable = Cast<IInteract>(InteractActor))
	{
		Interactable->Execute_Interact(InteractActor, this);
	}
}


void ARaeCharacter::OnInteractSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{		
	if (IInteract* Interactable = Cast<IInteract>(OtherActor))
	{
		Interactable->Execute_Highlight(OtherActor, true);
		InteractActor = OtherActor;
	}
}

void ARaeCharacter::OnInteractSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (IInteract* Interactable = Cast<IInteract>(OtherActor))
	{
		Interactable->Execute_Highlight(OtherActor, false);
		InteractActor = nullptr;
	}
}
