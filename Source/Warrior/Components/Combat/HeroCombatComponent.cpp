// Piang


#include "HeroCombatComponent.h"

#include "Warrior/WarriorDebugHelper.h"
#include "Warrior/Items/Weapons/WarriorHeroWeapon.h"

AWarriorHeroWeapon* UHeroCombatComponent::GetHeroCarriedWeaponByTag(FGameplayTag InWeaponTag) const
{
	return Cast<AWarriorHeroWeapon>(GetCharacterCarriedWeaponByTag(InWeaponTag));
}

void UHeroCombatComponent::OnHitTargetActor(AActor* HitActor)
{
	Debug::Print(GetOwningPawn()->GetActorNameOrLabel()+TEXT(" Hit ")+HitActor->GetActorNameOrLabel(),FColor::Green);
}

void UHeroCombatComponent::OnWeaponPulledFromTargetActor(AActor* InterActedActor)
{
	Debug::Print(GetOwningPawn()->GetActorNameOrLabel()+TEXT("’s Weapon Pulled from ")+InterActedActor->GetActorNameOrLabel(),FColor::Red);
}
