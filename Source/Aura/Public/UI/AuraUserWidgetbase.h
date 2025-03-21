// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AuraUserWidgetbase.generated.h"

class UAuraWidgetController;
/**
 * 
 */
UCLASS()
class AURA_API UAuraUserWidgetbase : public UUserWidget
{
	GENERATED_BODY()
public:
		UFUNCTION(BlueprintCallable, Category = "Widget")
    	void SetWidgetController(UAuraWidgetController* InWidgetController);
protected:
	
	UPROPERTY(BlueprintReadOnly, Category = "Widget")
	UAuraWidgetController* WidgetController;
	
	UFUNCTION(BlueprintImplementableEvent, Category = "Widget")
	void EventWidgetControllerSet();
};
