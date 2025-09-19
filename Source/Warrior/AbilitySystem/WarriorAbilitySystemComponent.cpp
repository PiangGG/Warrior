// Piang


#include "WarriorAbilitySystemComponent.h"

void UWarriorAbilitySystemComponent::OnAbilityInputPressed(const FGameplayTag& InInputTag)
{
	if (!InInputTag.IsValid())
	{
		return;
	}
	for (auto Element : GetActivatableAbilities())
	{
		if (!Element.GetDynamicSpecSourceTags().HasTagExact(InInputTag))continue;
		TryActivateAbility(Element.Handle);
	}
}

void UWarriorAbilitySystemComponent::OnAbilityInputReleased(const FGameplayTag& InInputTag)
{
}
