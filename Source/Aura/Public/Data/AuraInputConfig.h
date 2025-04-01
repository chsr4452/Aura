// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DataAsset.h"
#include "AuraInputConfig.generated.h"

class UInputAction;

USTRUCT(BlueprintType)
struct FAuraInputTag
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly,Category="InputConfig")
	FGameplayTag GameplayTag;

	UPROPERTY(EditDefaultsOnly,Category="InputConfig")
	const UInputAction* InputAction;
};
/**
 * 
 */
UCLASS()
class AURA_API UAuraInputConfig : public UDataAsset
{
	GENERATED_BODY()

	public:
	UPROPERTY(EditDefaultsOnly,Category="InputConfig")
	TArray<FAuraInputTag> InputConfigs;
		
	const UInputAction* GetInputAction(FGameplayTag InGameplayTag) const;
};
