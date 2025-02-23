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
	
	if(Health == 0)
	{
		if(ARaeCharacter* RaeCharacter = Cast<ARaeCharacter>(GetOwner()))
		{
			// RaeCharacter->Die();
		}
	}
}

void UHeroComponent::AddHealth(float Value)
{
	SetHealth(Health + Value);
}
