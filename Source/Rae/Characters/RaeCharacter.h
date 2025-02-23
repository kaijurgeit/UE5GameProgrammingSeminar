// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ThirdPersonCharacter.h"
#include "RaeCharacter.generated.h"

UCLASS()
class RAE_API ARaeCharacter : public AThirdPersonCharacter
{
	GENERATED_BODY()
public:
	ARaeCharacter();
	void Die();
	
protected:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	//~ Input Mapping Context / Input Actions
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Input")
	TObjectPtr<UInputAction> InteractAction;
	//~ End of Input Mapping Context / Input Actions

	UPROPERTY(EditAnywhere, Category="Rae|Hero")
	TObjectPtr<UAnimMontage> DeathAnimMontage;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Rae|Hero")
	bool bIsDead = false;

private:
	void Interact(const FInputActionValue& Value);
	
	//~ Components
	//~ End of Components
};
