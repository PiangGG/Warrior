// Piang


#include "WarriorHeroGameplayAbility.h"

#include "Warrior/AbilitySystem/WarriorAbilitySystemComponent.h"
#include "Warrior/Characters/WarriorHeroCharacter.h"
#include "Warrior/Controllers/WarriorHeroPlayerController.h"

AWarriorHeroCharacter* UWarriorHeroGameplayAbility::GetHeroCharacterFromActorInfo()
{
	if (!CachedWarriorHeroCharacter.IsValid())
	{
		CachedWarriorHeroCharacter = Cast<AWarriorHeroCharacter>(CurrentActorInfo->AvatarActor);
	}
	return CachedWarriorHeroCharacter.IsValid()?CachedWarriorHeroCharacter.Get():nullptr;
}

AWarriorHeroPlayerController* UWarriorHeroGameplayAbility::GetHeroControllerFromActorInfo()
{
	if (!CachedWarriorHeroPlayerController.IsValid())
	{
		CachedWarriorHeroPlayerController = Cast<AWarriorHeroPlayerController>(CurrentActorInfo->PlayerController);
	}
	return CachedWarriorHeroPlayerController.IsValid()?CachedWarriorHeroPlayerController.Get():nullptr;
}

UHeroCombatComponent* UWarriorHeroGameplayAbility::GetHeroCombatComponentFromActorInfo()
{
	return GetHeroCharacterFromActorInfo()->GetHeroCombatComponent();
}

FGameplayEffectSpecHandle UWarriorHeroGameplayAbility::MakeHeroDamageEffectSpecHandle(TSubclassOf<UGameplayEffect> EffectClass,float InWeaponBaseDamage,FGameplayTag InCurrentAttackTypeTag,int32 InUsedComboCount)
{
	check(EffectClass)
	FGameplayEffectContextHandle ContextHandle = GetWarriorAbilitySystemComponentFromActorInfo()->MakeEffectContext();
	ContextHandle.SetAbility(this);
	ContextHandle.AddSourceObject(GetAvatarActorFromActorInfo());
	ContextHandle.AddInstigator(GetAvatarActorFromActorInfo(),GetAvatarActorFromActorInfo());

	FGameplayEffectSpecHandle EffectSpecHandle = GetWarriorAbilitySystemComponentFromActorInfo()->MakeOutgoingSpec(EffectClass,GetAbilityLevel(),ContextHandle);

	EffectSpecHandle.Data->SetSetByCallerMagnitude(InCurrentAttackTypeTag,InWeaponBaseDamage);
	if (InCurrentAttackTypeTag.IsValid())
	{
		EffectSpecHandle.Data->SetSetByCallerMagnitude(InCurrentAttackTypeTag,InUsedComboCount);
	}
	return EffectSpecHandle;
}
