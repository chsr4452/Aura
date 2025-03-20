// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "AuraCharacterBase.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;

UCLASS()
class AURA_API AAuraCharacterBase : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:

	// Sets default values for this character's properties
	AAuraCharacterBase();
	virtual void BeginPlay() override;

	// Getter
	UFUNCTION(BlueprintCallable, Category = "Gameplay Ability System")
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override{return AbilitySystemComponent;}

	UFUNCTION(BlueprintCallable, Category = "Gameplay Ability System")
	virtual UAttributeSet* GetAttributeSet() const{return AttributeSet;}

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Weapon")
	TObjectPtr<USkeletalMeshComponent> WeaponMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Gameplay Ability System")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Gameplay Ability System")
	TObjectPtr<UAttributeSet> AttributeSet;

	
};
