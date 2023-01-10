// Fill out your copyright notice in the Description page of Project Settings.


#include "TsDynamicInvokerEditor.h"
#if WITH_EDITOR
#include "Editor.h"
#endif

namespace puerts
{
    
TsDynamicInvokerEditor::TsDynamicInvokerEditor(TSharedPtr<ITsDynamicInvoker> InEditorInvoker)
    : EditorInvoker(InEditorInvoker)
{
}

void TsDynamicInvokerEditor::TsConstruct(UTypeScriptGeneratedClass* Class, UObject* Object)
{
    if (GameInvoker != nullptr && !IsEditorScopedObject(Object))
        GameInvoker->TsConstruct(Class, Object);
    else
        EditorInvoker->TsConstruct(Class, Object);
}

void TsDynamicInvokerEditor::InvokeTsMethod(UObject* ContextObject, UFunction* Function, FFrame& Stack, void* Z_Param__Result)
{
    if (GameInvoker != nullptr && !IsEditorScopedObject(ContextObject))
        GameInvoker->InvokeTsMethod(ContextObject, Function, Stack, Z_Param__Result);
    else
        EditorInvoker->InvokeTsMethod(ContextObject, Function, Stack, Z_Param__Result);
}

void TsDynamicInvokerEditor::NotifyReBind(UTypeScriptGeneratedClass* Class)
{
    if (GameInvoker != nullptr)
        GameInvoker->NotifyReBind(Class);
    EditorInvoker->NotifyReBind(Class);
}

void TsDynamicInvokerEditor::SetGameInvoker(TSharedPtr<ITsDynamicInvoker> InGameInvoker)
{
    GameInvoker = InGameInvoker;
}

void TsDynamicInvokerEditor::ResetGameInvoker()
{
    GameInvoker.Reset();
}

bool TsDynamicInvokerEditor::IsEditorScopedObject(UObject* Object)
{
#if WITH_EDITOR
    if (!GIsEditor)
        return false;

    UWorld* ObjectWorld = GEngine->GetWorldFromContextObject(Object, EGetWorldErrorMode::LogAndReturnNull);
    UWorld* EditorWorld = GEditor->GetEditorWorldContext().World();
    return ObjectWorld == EditorWorld;
#else
    return false;
#endif
}

}
