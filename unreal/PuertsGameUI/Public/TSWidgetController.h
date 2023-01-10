#pragma once

#include "CoreMinimal.h"
#include "Tickable.h"
#include "TSWidgetController.generated.h"

UCLASS()
class PUERTSGAMEUI_API UTSWidgetController : public UObject, public FTickableGameObject
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintImplementableEvent)
    void Tick(float DeltaTime);

    virtual TStatId GetStatId() const;

    UFUNCTION(BlueprintImplementableEvent)
    void SetupWidget(UUserWidget* Widget);
}; 