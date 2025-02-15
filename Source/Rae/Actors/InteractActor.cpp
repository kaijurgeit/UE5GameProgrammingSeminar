// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractActor.h"

#include "Components/WidgetComponent.h"


AInteractActor::AInteractActor()
{
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent = Mesh;
	Mesh->SetCollisionProfileName(TEXT("Interaction"));

	InteractWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("Widget"));	
	InteractWidget->SetupAttachment(RootComponent);
	InteractWidget->SetWidgetSpace(EWidgetSpace::Screen);
	InteractWidget->SetVisibility(false);
	InteractWidget->InitWidget();
}

