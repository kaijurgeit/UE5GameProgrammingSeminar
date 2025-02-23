// Fill out your copyright notice in the Description page of Project Settings.


#include "HeroComponent.h"

#include "Characters/RaeCharacter.h"


UHeroComponent::UHeroComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UHeroComponent::SetHealth(float Value)
{
	Health = FMath::Clamp(Value, 0.0f, MaxHealth);
	OnHealthChanged.Broadcast(Value, MaxHealth, HealthRatio());
	
	if(Health == 0)
	{
		if(ARaeCharacter* RaeCharacter = Cast<ARaeCharacter>(GetOwner()))
		{
			RaeCharacter->Die();
		}
	}
}

void UHeroComponent::AddHealth(float Value)
{
	SetHealth(Health + Value);
}

void UHeroComponent::SetStamina(float Value)
{
	Stamina = FMath::Clamp(Value, 0.0f, MaxStamina);
	OnStaminaChanged.Broadcast(Value, MaxStamina, StaminaRatio());

	RecoverStamina();
}

void UHeroComponent::AddStamina(float Value)
{
	SetStamina(Stamina + Value);
}

void UHeroComponent::RecoverStamina()
{
	if (Stamina == MaxStamina)
	{
		// If stamina fully recovered, delete timer
		GetWorld()->GetTimerManager().ClearTimer(TimerHandle);
	}
	else if (!TimerHandle.IsValid())
	{
		// A timer delegate pointing to: AddStamina(Amount) with Amount being 1.0
		FTimerDelegate TimerDelegate;
		TimerDelegate.BindLambda([this]() { AddStamina(Amount); } );

		// The timer that is calling the delegate at a rate of 0.1s, looping, after a first delay of 2s
		GetWorld()->GetTimerManager().SetTimer(TimerHandle, TimerDelegate, Rate, true, FirstDelay);		
	}	
}