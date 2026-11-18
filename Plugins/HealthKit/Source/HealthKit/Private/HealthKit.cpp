// Copyright Epic Games, Inc. All Rights Reserved.

#include "HealthKit.h"

#define LOCTEXT_NAMESPACE "FHealthKitModule"

void FHealthKitModule::StartupModule()
{
	UE_LOG(LogTemp, Warning, TEXT("[HealthKit] StartupModule"));
}

void FHealthKitModule::ShutdownModule()
{
	UE_LOG(LogTemp, Warning, TEXT("[HealthKit] ShutdownModule"));
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FHealthKitModule, HealthKit)
