// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/AuraWidgetController.h"
#include "AuraOverlayWidgetController.generated.h"

struct FOnAttributeChangeData;
/**
 * 
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealthChangeSignature, float, HealthChange);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxHealthChangeSignature, float, MaxHealthChange);


UCLASS(Blueprintable, BlueprintType)
class AURA_API UAuraOverlayWidgetController : public UAuraWidgetController
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void BroadCastInitAttribute();
	
	virtual void BindCallbacksToDependencies() override;

	UPROPERTY(BlueprintAssignable, BlueprintReadWrite, Category = "Attribute")
	FOnHealthChangeSignature OnHealthChange;
	
	UPROPERTY(BlueprintAssignable, BlueprintReadWrite, Category = "Attribute")
	FOnMaxHealthChangeSignature OnMaxHealthChange;
	
	void OnHealthChangeCallback(const FOnAttributeChangeData& Data);
	void OnMaxHealthChangeCallback(const FOnAttributeChangeData& Data);
};



