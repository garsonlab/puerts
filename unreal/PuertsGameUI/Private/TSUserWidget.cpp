#include "TSUserWidget.h"
#include "TSWidgetController.h"


UTSUserWidget::UTSUserWidget(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
    TSController = nullptr;
}

void UTSUserWidget::NativePreConstruct()
{
    Super::NativePreConstruct();
}

void UTSUserWidget::NativeConstruct()
{
    Super::NativeConstruct();
    CreateTSController();
}

void UTSUserWidget::NativeDestruct()
{
    Super::NativeDestruct();
}

void UTSUserWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
    Super::NativeTick(MyGeometry, InDeltaTime);
}

void UTSUserWidget::CreateTSController()
{
    if (TSControllerClass)
    {
        TSController = NewObject<UTSWidgetController>(this, TSControllerClass.Get());
        TSController->SetupWidget(this);
    }
}

void UTSUserWidget::PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent)
{
    if (TSControllerClass != nullptr)
    {
        TSController = NewObject<UTSWidgetController>(this, TSControllerClass.Get());
        TSController->SetupWidget(this);
    }
}