// Piang


#include "HeroCombatComponent.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "Warrior/WarriorDebugHelper.h"
#include "Warrior/WarriorGameplayTags.h"
#include "Warrior/Items/Weapons/WarriorHeroWeapon.h"

AWarriorHeroWeapon* UHeroCombatComponent::GetHeroCarriedWeaponByTag(FGameplayTag InWeaponTag) const
{
	return Cast<AWarriorHeroWeapon>(GetCharacterCarriedWeaponByTag(InWeaponTag));
}

void UHeroCombatComponent::OnHitTargetActor(AActor* HitActor)
{
	//Debug::Print(GetOwningPawn()->GetActorNameOrLabel()+TEXT(" Hit ")+HitActor->GetActorNameOrLabel(),FColor::Green);
	if (OverlappedActors.Contains(HitActor))
	{
		return;
	}
	OverlappedActors.AddUnique(HitActor);
	FGameplayEventData Data;
	Data.Instigator = GetOwningPawn();
	Data.Target = HitActor;
	UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(GetOwningPawn(),WarriorGameplayTags::Shared_Event_MeleeHit,Data);
}

void UHeroCombatComponent::OnWeaponPulledFromTargetActor(AActor* InterActedActor)
{
	//Debug::Print(GetOwningPawn()->GetActorNameOrLabel()+TEXT("’s Weapon Pulled from ")+InterActedActor->GetActorNameOrLabel(),FColor::Red);
}
