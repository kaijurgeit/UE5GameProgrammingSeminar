// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractActor.generated.h"

class UWidgetComponent;

UCLASS()
class RAE_API AInteractActor : public AActor
{
	GENERATED_BODY()

public:
	AInteractActor();
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<UStaticMeshComponent> Mesh;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Rae|Interaction")
	TObjectPtr<UWidgetComponent> InteractWidget;
};
