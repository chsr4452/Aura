// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AuraWidgetController.generated.h"

class UAttributeSet;
class UAbilitySystemComponent;
class AAuraPlayerController;
class AAuraPlayerState;
class UAuraAbilitySystemComponent;
class UAuraAttributeSet;
/**
 * 
 */
USTRUCT(BlueprintType, Blueprintable)
struct FAuraWidgetControllerParam
{
	GENERATED_BODY();
public:
	FAuraWidgetControllerParam();
	FAuraWidgetControllerParam(
		APlayerController* InPlayerController,
		UAttributeSet* InAttributeSet,
		UAbilitySystemComponent* InAbilitySystemComponent,
		APlayerState* InPlayerState):
		PlayerControllerParam(InPlayerController), AttributeSetParam(InAttributeSet), AbilitySystemComponentParam(InAbilitySystemComponent), PlayerStateParam(InPlayerState)
		{
		}
	
	UPROPERTY()
	APlayerController* PlayerControllerParam = nullptr;
	
	UPROPERTY()
    UAttributeSet* AttributeSetParam = nullptr;
	
	UPROPERTY()
	UAbilitySystemComponent* AbilitySystemComponentParam = nullptr;

	UPROPERTY()
	APlayerState* PlayerStateParam = nullptr;
};
UCLASS(BlueprintType, Blueprintable)
class AURA_API UAuraWidgetController : public UObject
{
	GENERATED_BODY()

public:
	
	UAuraWidgetController();

	UFUNCTION(BlueprintCallable)
	virtual void BindCallbacksToDependencies();
	
	
	UPROPERTY(BlueprintReadOnly, Category = "Widget Parameter")
	TObjectPtr<AAuraPlayerController> AuraPC;
	
	UPROPERTY(BlueprintReadOnly, Category = "Widget Parameter")
	TObjectPtr<AAuraPlayerState> AuraPS;

	UPROPERTY(BlueprintReadOnly, Category = "Widget Parameter")
	TObjectPtr<UAuraAbilitySystemComponent> AuraASC;

	UPROPERTY(BlueprintReadOnly, Category = "Widget Parameter")
	TObjectPtr<UAuraAttributeSet> AuraAS;

	UFUNCTION(BlueprintCallable, Category = "Widget Parameter")
	void SetAuraWidgetController(FAuraWidgetControllerParam& WCParams);
};
