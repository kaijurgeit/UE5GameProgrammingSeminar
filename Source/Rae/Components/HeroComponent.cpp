// Fill out your copyright notice in the Description page of Project Settings.


#include "HeroComponent.h"


UHeroComponent::UHeroComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UHeroComponent::BeginPlay()
{
	Super::BeginPlay();	
}
