// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Interact.generated.h"

class ARaeCharacter;
class APlayerCharacter;

UINTERFACE()
class UInteract : public UInterface
{
	GENERATED_BODY()
};

class RAE_API IInteract
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void Interact(ARaeCharacter* RaeCharacter);

	UFUNCTION(BlueprintNativeEvent)
	void Highlight(bool bHighlighted);
};
