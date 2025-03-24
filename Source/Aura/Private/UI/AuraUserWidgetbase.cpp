// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/AuraUserWidgetbase.h"

void UAuraUserWidgetbase::SetWidgetController(UAuraWidgetController* InWidgetController)
{
	WidgetController = InWidgetController;
	EventWidgetControllerSet();
	// GEngine->AddOnScreenDebugMessage(1, 2, FColor::Red, "SetWidgetController");
}
