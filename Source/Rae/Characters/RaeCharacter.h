// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ThirdPersonCharacter.h"
#include "RaeCharacter.generated.h"

UCLASS()
class RAE_API ARaeCharacter : public AThirdPersonCharacter
{
	GENERATED_BODY()
protected:	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	//~ Input Mapping Context / Input Actions
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Input")
	TObjectPtr<UInputAction> InteractAction;
	//~ End of Input Mapping Context / Input Actions

private:	
	void Interact(const FInputActionValue& Value);
};
