// Piang


#include "DataAsset_HeroStartUpDataBase.h"

#include "Warrior/AbilitySystem/WarriorAbilitySystemComponent.h"
#include "Warrior/AbilitySystem/Abilities/WarriorGameplayAbility.h"

bool FWarriorHeroAbility::IsValid() const
{
	return InputTag.IsValid() && AbilityToGrant;
}

void UDataAsset_HeroStartUpDataBase::GiveToWarriorAbilitySystemComponent(UWarriorAbilitySystemComponent* InAscToGive,
	int32 ApplyLevel)
{
	Super::GiveToWarriorAbilitySystemComponent(InAscToGive, ApplyLevel);

	for (auto Element : HeroStartUpAbilitySets)
	{
		if (!Element.IsValid())continue;
		FGameplayAbilitySpec AbilitySpec(Element.AbilityToGrant);
		AbilitySpec.SourceObject = InAscToGive->GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;
		AbilitySpec.GetDynamicSpecSourceTags().AddTag(Element.InputTag);
		
		InAscToGive->GiveAbility(AbilitySpec);
	}
}
