#include "PuertsGameUI.h"

void FPuertsGameUI::StartupModule()
{
	IModuleInterface::StartupModule();
}

void FPuertsGameUI::ShutdownModule()
{
	IModuleInterface::ShutdownModule();
}

IMPLEMENT_MODULE(FPuertsGameUI, PuertsGameUI)