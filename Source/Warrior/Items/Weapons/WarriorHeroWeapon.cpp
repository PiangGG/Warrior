// Piang


#include "WarriorHeroWeapon.h"

void AWarriorHeroWeapon::AssignGrantedAbilitySpecHandles(const TArray<FGameplayAbilitySpecHandle>& InsSpecHandles)
{
	GrantedAbilitySpecHandles = InsSpecHandles;
}

TArray<FGameplayAbilitySpecHandle> AWarriorHeroWeapon::GetGrantedAbilitySpecHandles() const
{
	return GrantedAbilitySpecHandles;
}
