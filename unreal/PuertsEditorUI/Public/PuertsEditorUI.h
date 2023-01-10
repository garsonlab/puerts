#pragma once

#include "CoreMinimal.h"

class PUERTSEDITORUI_API FPuertsEditorUI : public IModuleInterface
{
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};