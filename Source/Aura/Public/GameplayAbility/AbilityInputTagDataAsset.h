// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DataAsset.h"
#include "AbilityInputTagDataAsset.generated.h"

/**
 * 
 */

class UGameplayAbility;
class UInputAction;

USTRUCT(BlueprintType)
struct FInputActionAbilityDataAsset
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	FGameplayTag InputTag;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UGameplayAbility> GameplayAbility;
}; 
UCLASS()
class AURA_API UAbilityInputTagDataAsset : public UDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Gameplay Ability System")
	TArray<FInputActionAbilityDataAsset> InputActionAbility;

	TSubclassOf<UGameplayAbility>  MatchInputTagWithAbility(FName& InInputTag);
};
