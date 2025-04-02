// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayAbility/AuraGameplayAbility.h"
#include "AuraFireBolt.generated.h"

class ICombatInterface;
class AAuraProjectileActor;
/**
 * 
 */
UCLASS()
class AURA_API UAuraFireBolt : public UAuraGameplayAbility
{
	GENERATED_BODY()
protected:
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;

	UPROPERTY(EditAnywhere, Category = "Combat")
	TSubclassOf<AAuraProjectileActor> ProjectileClass;

	TScriptInterface<ICombatInterface> CombatInterface;
};
