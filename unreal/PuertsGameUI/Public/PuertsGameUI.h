#pragma once

#include "CoreMinimal.h"

class PUERTSGAMEUI_API FPuertsGameUI : public IModuleInterface
{
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};