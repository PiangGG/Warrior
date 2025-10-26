// Piang

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Warrior/Components/PawnExtensionComponent.h"
#include "PawnCombatComponent.generated.h"

class AWarriorWeaponBase;
struct FGameplayTag;

UENUM()
enum class EToggleDamageType : uint8
{
	CurrentEquipmentWeapon,
	LeftHand,
	RightHand
};
/**
 * 
 */
UCLASS()
class WARRIOR_API UPawnCombatComponent : public UPawnExtensionComponent
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Category = "Warrior|Combat")
	void RegisterSpawnedWeapon(FGameplayTag InWeaponTagToRegister,AWarriorWeaponBase* InWeaponToRegister,bool bRegisterAsEquippedWeapon = false);
	
	UFUNCTION(BlueprintCallable, Category = "Warrior|Combat")
	AWarriorWeaponBase* GetCharacterCarriedWeaponByTag(FGameplayTag InWeaponTagToGet)const;

	UPROPERTY(BlueprintReadWrite, Category = "Warrior|Combat")
	FGameplayTag CurrentEquippedWeaponTag;

	UFUNCTION(BlueprintCallable, Category = "Warrior|Combat")
	AWarriorWeaponBase* GetCharacterCurrentEquippedWeapon();

	UFUNCTION(BlueprintCallable, Category = "Warrior|Combat")
	void ToggleWeaponCollision(bool bShouldEnable,EToggleDamageType ToggleDamageType = EToggleDamageType::CurrentEquipmentWeapon);
private:
	
	TMap<FGameplayTag,AWarriorWeaponBase*> CharacterCarriedWeaponMap;
};
