// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/AuraWidgetController.h"

#include "Characters/AuraPlayerController.h"
#include "Game/AuraPlayerState.h"
#include "GameplayAbilitySystem/AuraAbilitySystemComponent.h"
#include "GameplayAbilitySystem/AuraAttributeSet.h"


FAuraWidgetControllerParam::FAuraWidgetControllerParam()
{
}

UAuraWidgetController::UAuraWidgetController()
{
}

void UAuraWidgetController::SetAuraWidgetController(FAuraWidgetControllerParam& WCParams)
{
	AuraPC = Cast<AAuraPlayerController>(WCParams.PlayerControllerParam);
	AuraPS = Cast<AAuraPlayerState>(WCParams.PlayerStateParam);
	AuraASC = Cast<UAuraAbilitySystemComponent>(WCParams.AbilitySystemComponentParam);
	AuraAS = Cast<UAuraAttributeSet>(WCParams.AttributeSetParam);
}
