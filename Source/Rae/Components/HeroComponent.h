// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HeroComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FAttributChangedSignature, float, Value, float, MaxValue, float, Ratio);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class RAE_API UHeroComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UHeroComponent();

	UPROPERTY(BlueprintAssignable)
	FAttributChangedSignature OnHealthChanged;
	
	UPROPERTY(BlueprintAssignable)
	FAttributChangedSignature OnStaminaChanged;

	UFUNCTION(BlueprintCallable, Category="Rae|Hero")
	void SetHealth(float Value);
	UFUNCTION(BlueprintCallable, Category="Rae|Hero")
	void AddHealth(float Value);
	
	UFUNCTION(BlueprintCallable, Category="Rae|Hero")
	void AddStamina(float Value);
	UFUNCTION(BlueprintCallable, Category="Rae|Hero")
	void SetStamina(float Value);
	
	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Rae|Hero")
	float HealthRatio() { return Health / MaxHealth; }	
	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Rae|Hero")
	float StaminaRatio() { return Stamina / MaxStamina; }
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, BlueprintSetter=SetHealth, Category="Rae|Hero")
	float Health = 50.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Rae|Hero")
	float MaxHealth = 100.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, BlueprintSetter=SetHealth, Category="Rae|Hero")
	float Stamina = 100.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Rae|Hero")
	float MaxStamina = 100.f;

	UPROPERTY(EditDefaultsOnly, Category="Rae|Hero")
	float Amount = 1.0f;
	UPROPERTY(EditDefaultsOnly, Category="Rae|Hero")
	float Rate = 0.1f;
	UPROPERTY(EditDefaultsOnly, Category="Rae|Hero")
	float FirstDelay = 2.0;
		
private:
	FTimerHandle TimerHandle;
	
	UFUNCTION()
	void RecoverStamina();
};