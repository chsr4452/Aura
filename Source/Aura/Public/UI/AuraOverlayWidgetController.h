// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

#include "UI/AuraWidgetController.h"
#include "AuraOverlayWidgetController.generated.h"

class UAuraUserWidgetbase;

USTRUCT(BlueprintType)
struct FUTagWidgetRow: public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FGameplayTag Tag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FText Message = FText();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UAuraUserWidgetbase> WidgetClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UTexture2D* Texture = nullptr;
};

/**
 * 
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealthChangeSignature, float, HealthChange);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxHealthChangeSignature, float, MaxHealthChange);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnManaChangeSignature, float, ManaChange);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxManaChangeSignature, float, MaxManaChange);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGetRowFromTableSignature, const FUTagWidgetRow&, Row);

UCLASS(Blueprintable, BlueprintType)
class AURA_API UAuraOverlayWidgetController : public UAuraWidgetController
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void BroadCastInitAttribute();
	
	virtual void BindCallbacksToDependencies() override;

	UPROPERTY(BlueprintAssignable, BlueprintReadWrite, Category = "Attribute")
	FOnHealthChangeSignature OnHealthChange;
	
	UPROPERTY(BlueprintAssignable, BlueprintReadWrite, Category = "Attribute")
	FOnMaxHealthChangeSignature OnMaxHealthChange;
	
	UPROPERTY(BlueprintAssignable, BlueprintReadWrite, Category = "Attribute")
	FOnManaChangeSignature OnManaChange;
	
	UPROPERTY(BlueprintAssignable, BlueprintReadWrite, Category = "Attribute")
	FOnMaxManaChangeSignature OnMaxManaChange;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    UDataTable* TagToWidgetTable;

	UPROPERTY(BlueprintAssignable, BlueprintReadOnly, Category = "Widget")
	FOnGetRowFromTableSignature OnGetRowFromTable;

	FUTagWidgetRow* GetRowFromWidgetTable(UDataTable* InTagToWidgetTable, FGameplayTag InGameplayTag) const;
};



