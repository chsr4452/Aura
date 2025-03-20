// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/AuraEffectActor.h"
#include "Components/SphereComponent.h"
#include "Characters/AuraCharacterbase.h"
#include "GameplayAbilitySystem/AuraAttributeSet.h"

// Sets default values
AAuraEffectActor::AAuraEffectActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));

	SetRootComponent(SphereComp);
	MeshComp->SetupAttachment(SphereComp);

	SphereComp->OnComponentBeginOverlap.AddDynamic(this, &AAuraEffectActor::OnBeginOverlapFunc);
}

// Called when the game starts or when spawned
void AAuraEffectActor::BeginPlay()
{
	Super::BeginPlay();
}

void AAuraEffectActor::OnBeginOverlapFunc(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if ((OverlappedCharacter = Cast<AAuraCharacterBase>(OtherActor)))
	{
			
        	if (UAuraAttributeSet* AuraAttributeSet = Cast<UAuraAttributeSet>(OverlappedCharacter->GetAttributeSet()))
        	{
        		AuraAttributeSet->SetHealth(AuraAttributeSet->GetHealth() + 20);
        	}
		this->Destroy();
	}
	
}


