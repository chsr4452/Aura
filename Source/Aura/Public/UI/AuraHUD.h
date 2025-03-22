// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "AuraHUD.generated.h"

class UAuraUserWidgetbase;
class UAbilitySystemComponent;
class UAttributeSet;
class UAuraOverlayWidgetController;
struct FAuraWidgetControllerParam;

/**
 *
 * 
 */

UCLASS()
class AURA_API AAuraHUD : public AHUD
{
	GENERATED_BODY()

public:
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Overlay Widget")
	TSubclassOf<UUserWidget> OverlayWidgetClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Overlay Widget")
	TObjectPtr<UAuraOverlayWidgetController> OverlayWidgetController;
	
	void InitAuraHUD(	APlayerController* InPlayerController,
		UAttributeSet* InAttributeSet,
		UAbilitySystemComponent* InAbilitySystemComponent,
		APlayerState* InPlayerState);

	UPROPERTY()
    TObjectPtr<UUserWidget> OverlayWidget;
	
	UPROPERTY()
    TObjectPtr<UAuraUserWidgetbase> AuraOverlayWidget;
	
	UFUNCTION()
    UAuraOverlayWidgetController* GetOverlayWidgetController(FAuraWidgetControllerParam& WidgetParams);

protected:

};
