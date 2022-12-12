// Fill out your copyright notice in the Description page of Project Settings.


#include "PlatformTriggerBox.h"

APlatformTriggerBox::APlatformTriggerBox()
{
	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MESH"));
	mesh->AttachToComponent(RootComponent,FAttachmentTransformRules::KeepRelativeTransform);
}

