// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/PlayerState.h"
#include "AuraPlayerState.generated.h"

class UAttributeSet;
class UAbilitySystemComponent;
/**
 * 
 */
UCLASS()
class AURA_API AAuraPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AAuraPlayerState();
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Gameplay Ability System")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Gameplay Ability System")
	TObjectPtr<UAttributeSet> AttributeSet;

	UFUNCTION(BlueprintCallable, Category = "Gameplay Ability System")
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override{return AbilitySystemComponent;}

	UFUNCTION(BlueprintCallable, Category = "Gameplay Ability System")
	virtual UAttributeSet* GetAttributeSet() const{return AttributeSet;}
};
