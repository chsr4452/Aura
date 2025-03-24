// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayEffectTypes.h"
#include "AuraEffectActor.generated.h"

class UAbilitySystemComponent;
class UGameplayEffect;
class AAuraCharacterBase;
class USphereComponent;

UENUM(BlueprintType)
enum class EOnOverlapPolicy : uint8
{
	ApplyEffectOnBeginOverlap,
	DoNotApplyEffectOnBeginOverlap
};
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnItemOverlapBegin, float, AttrChange);
UCLASS()
class AURA_API AAuraEffectActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAuraEffectActor();
	virtual void BeginPlay() override;

protected:
	UFUNCTION(BlueprintCallable, Category = "Gameplay Effect")
    void ApplyEffectToTarget(AActor* TargetActor, TSubclassOf<UGameplayEffect> EffectClass);
    
    UFUNCTION(BlueprintCallable, Category = "Gameplay Effect")
    void ApplyEffectOnBeginOverlap(AActor* TargetActor);
    
    UFUNCTION(BlueprintCallable, Category = "Gameplay Effect")
    void ApplyEffectOnEndOverlap(AActor* TargetActor);
    
    UPROPERTY(EditDefaultsOnly, Category = "Gameplay Effect")
    TSubclassOf<UGameplayEffect> InstantEffectClass;
    UPROPERTY(EditDefaultsOnly, Category = "Gameplay Effect")
    EOnOverlapPolicy InstantEffectOverlapPolicy = EOnOverlapPolicy::DoNotApplyEffectOnBeginOverlap;
    
    UPROPERTY(EditDefaultsOnly, Category = "Gameplay Effect")
    TSubclassOf<UGameplayEffect> DurationEffectClass;
    UPROPERTY(EditDefaultsOnly, Category = "Gameplay Effect")
    EOnOverlapPolicy DurationEffectOverlapPolicy = EOnOverlapPolicy::DoNotApplyEffectOnBeginOverlap;
    
    UPROPERTY(EditDefaultsOnly, Category = "Gameplay Effect")
    TSubclassOf<UGameplayEffect> InfiniteEffectClass;
    UPROPERTY(EditDefaultsOnly, Category = "Gameplay Effect")
    EOnOverlapPolicy InfiniteEffectOverlapPolicy = EOnOverlapPolicy::DoNotApplyEffectOnBeginOverlap;

	TMap<FActiveGameplayEffectHandle, UAbilitySystemComponent*> ActiveGameplayEffectMap;

	bool bInfinite = false;

};
