#pragma once

#include "TsDynamicInvoker.h"

class UTypeScriptGeneratedClass;

namespace puerts
{
class TsDynamicInvokerEditor : public ITsDynamicInvoker
{
public:
    TsDynamicInvokerEditor(TSharedPtr<ITsDynamicInvoker> InEditorInvoker);
    virtual ~TsDynamicInvokerEditor() {};
    
    /** Begin of ITsDynamicInvoker */
    virtual void TsConstruct(UTypeScriptGeneratedClass* Class, UObject* Object) override;

    virtual void InvokeTsMethod(UObject* ContextObject, UFunction* Function, FFrame& Stack, void* RESULT_PARAM) override;

    virtual void NotifyReBind(UTypeScriptGeneratedClass* Class) override;
    /** End of ITsDynamicInvoker */

    void SetGameInvoker(TSharedPtr<ITsDynamicInvoker> InGameInvoker);
    
    void ResetGameInvoker();

private:

    bool IsEditorScopedObject(UObject *Object);
    
    TSharedPtr<ITsDynamicInvoker> EditorInvoker;
    TSharedPtr<ITsDynamicInvoker> GameInvoker;
};
}    // namespace puerts
