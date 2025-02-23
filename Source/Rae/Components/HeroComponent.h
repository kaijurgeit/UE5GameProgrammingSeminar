﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HeroComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class RAE_API UHeroComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UHeroComponent();

	UFUNCTION(BlueprintCallable, Category="Rae|Hero")
	void SetHealth(float Value);

	UFUNCTION(BlueprintCallable, Category="Rae|Hero")
	void AddHealth(float Value);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, BlueprintSetter=SetHealth, Category="Rae|Hero")
	float Health = 50.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Rae|Hero")
	float MaxHealth = 100.f;
};