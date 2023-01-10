#include "TSEditorUtilityWidget.h"
#include "TSWidgetController.h"


UTSEditorUtilityWidget::UTSEditorUtilityWidget(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
    TSController = nullptr;
}

void UTSEditorUtilityWidget::NativePreConstruct()
{
    Super::NativePreConstruct();
}

void UTSEditorUtilityWidget::NativeConstruct()
{
    Super::NativeConstruct();
    CreateTSController();
}

void UTSEditorUtilityWidget::NativeDestruct()
{
    Super::NativeDestruct();
}

void UTSEditorUtilityWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
    Super::NativeTick(MyGeometry, InDeltaTime);
}

void UTSEditorUtilityWidget::CreateTSController()
{
    if (TSControllerClass)
    {
        TSController = NewObject<UTSWidgetController>(this, TSControllerClass.Get());
        TSController->SetupWidget(this);
    }
}

void UTSEditorUtilityWidget::PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent)
{
    if (TSControllerClass != nullptr)
    {
        TSController = NewObject<UTSWidgetController>(this, TSControllerClass.Get());
        TSController->SetupWidget(this);
    }
}