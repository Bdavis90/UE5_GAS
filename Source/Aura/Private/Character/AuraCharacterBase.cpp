// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/AuraCharacterBase.h"

#include "AbilitySystemComponent.h"

// Sets default values
AAuraCharacterBase::AAuraCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);

}

UAbilitySystemComponent* AAuraCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}


// Called when the game starts or when spawned
void AAuraCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void AAuraCharacterBase::InitAbilityActorInfo()
{
}

void AAuraCharacterBase::InitializePrimaryAttributes() const
{
	check(IsValid(AbilitySystemComponent));
	check(IsValid(DefaultPrimaryAttributes));
	FGameplayEffectContextHandle EffectContextHandle = AbilitySystemComponent->MakeEffectContext();
	FGameplayEffectSpecHandle EffectSpecHandle = AbilitySystemComponent->MakeOutgoingSpec(
		DefaultPrimaryAttributes, 1, EffectContextHandle);
	AbilitySystemComponent->ApplyGameplayEffectSpecToTarget(*EffectSpecHandle.Data.Get(), AbilitySystemComponent);
}

	

