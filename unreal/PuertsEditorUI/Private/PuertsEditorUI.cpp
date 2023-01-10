#include "PuertsEditorUI.h"

void FPuertsEditorUI::StartupModule()
{
	IModuleInterface::StartupModule();
}

void FPuertsEditorUI::ShutdownModule()
{
	IModuleInterface::ShutdownModule();
}

IMPLEMENT_MODULE(FPuertsEditorUI, PuertsEditorUI)