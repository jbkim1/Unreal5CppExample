// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"

class FHealthKitModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;    // 모듈이 로드된 직후
	virtual void ShutdownModule() override;   // 모듈이 내려가기 직전
};
