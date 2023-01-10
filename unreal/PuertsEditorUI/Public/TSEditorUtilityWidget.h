#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "EditorUtilityWidget.h"

#include "TSEditorUtilityWidget.generated.h"

class UTSWidgetController;

/**
 * BASE CLASS
 */
UCLASS()
class PUERTSEDITORUI_API UTSEditorUtilityWidget : public UEditorUtilityWidget
{
    GENERATED_BODY()

public:
    UTSEditorUtilityWidget(const FObjectInitializer& ObjectInitializer);

    UFUNCTION()
    virtual void NativeConstruct() override;
    virtual void NativeDestruct() override;
    virtual void NativePreConstruct() override;
    virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

    void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent);

private:
    void CreateTSController();

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TSubclassOf<UTSWidgetController> TSControllerClass;

private:
    UPROPERTY()
    UTSWidgetController* TSController;

};