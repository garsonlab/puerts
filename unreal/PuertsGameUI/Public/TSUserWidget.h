#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "TSUserWidget.generated.h"

class UTSWidgetController;

/**
 * BASE CLASS
 */
UCLASS()
class PUERTSGAMEUI_API UTSUserWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    UTSUserWidget(const FObjectInitializer& ObjectInitializer);

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