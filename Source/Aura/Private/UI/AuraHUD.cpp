// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/AuraHUD.h"

#include "Blueprint/UserWidget.h"
#include "UI/AuraOverlayWidgetController.h"
#include "UI/AuraUserWidgetbase.h"


UAuraOverlayWidgetController* AAuraHUD::GetOverlayWidgetController(FAuraWidgetControllerParam& WidgetParams)
{
	if (OverlayWidgetController == nullptr)
	{
		UAuraOverlayWidgetController* OverlayWidgetControllerNew = NewObject<UAuraOverlayWidgetController>();
		OverlayWidgetControllerNew->SetAuraWidgetController(WidgetParams);
		return OverlayWidgetControllerNew;
	}
	return OverlayWidgetController;
}
void AAuraHUD::InitAuraHUD(	APlayerController* InPlayerController,
		UAttributeSet* InAttributeSet,
		UAbilitySystemComponent* InAbilitySystemComponent,
		APlayerState* InPlayerState)
{
		checkf(OverlayWidgetClass, TEXT("Insert OverlayWidgetClass."))
    	OverlayWidget = CreateWidget(GetWorld(), OverlayWidgetClass);

	// Set widget Controller
		FAuraWidgetControllerParam WidgetControllerParam = FAuraWidgetControllerParam(InPlayerController, InAttributeSet, InAbilitySystemComponent, InPlayerState);
		OverlayWidgetController = GetOverlayWidgetController(WidgetControllerParam);
		AuraOverlayWidget = Cast<UAuraUserWidgetbase>(OverlayWidget);
		AuraOverlayWidget->SetWidgetController(OverlayWidgetController);
	//
    	OverlayWidget->AddToViewport();
}


