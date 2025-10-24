// Piang

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "WarriorBaseCharacter.h"
#include "WarriorHeroCharacter.generated.h"

class UDataAsset_InputConfig;
class USpringArmComponent;
class UCameraComponent;

class UHeroCombatComponent;
struct FInputActionValue;
/**
 * 
 */
UCLASS()
class WARRIOR_API AWarriorHeroCharacter : public AWarriorBaseCharacter
{
	GENERATED_BODY()
	
public:
	AWarriorHeroCharacter();
	
protected:
	//~Begin APawn Interface.
	virtual void PossessedBy(AController* NewController) override;
	//~End APawn Interface.

	//~Begin IPawnCombatInterface Interface.
	virtual UPawnCombatComponent* GetPawnCombatComponent()const override;
	//~End IPawnCombatInterface Interface.
	
	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
private:

#pragma region Components
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,category="Camera",meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,category="Camera",meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FollowCamera;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,category="Combat",meta = (AllowPrivateAccess = "true"))
	UHeroCombatComponent* HeroCombatComponent;
#pragma endregion

#pragma region Inputs
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,category="CharacterData",meta = (AllowPrivateAccess = "true"))
	UDataAsset_InputConfig* InputConfigDataAsset;

	void Input_Move(const FInputActionValue& InputActionValue);
	void Input_Look(const FInputActionValue& InputActionValue);
	
	void Input_AbilityInputPressed(FGameplayTag InInputTag);
	void Input_AbilityInputReleased(FGameplayTag InInputTag);
#pragma endregion

public:
	FORCEINLINE UHeroCombatComponent* GetHeroCombatComponent()const { return HeroCombatComponent;}
};
