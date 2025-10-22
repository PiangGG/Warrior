// Piang


#include "WarriorEnemyCharacter.h"

#include "Engine/AssetManager.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Warrior/WarriorDebugHelper.h"
#include "Warrior/Components/Combat/EnemyCombatComponent.h"
#include "Warrior/DataAssets/StartUpData/DataAsset_StartUpDataBase.h"

AWarriorEnemyCharacter::AWarriorEnemyCharacter()
{
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	GetCharacterMovement()->bUseControllerDesiredRotation = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0, 180.f, 0);
	GetCharacterMovement()->MaxWalkSpeed = 300.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 1000.f;

	EnemyCombatComponent = CreateDefaultSubobject<UEnemyCombatComponent>("EnemyCombatComponent");
}

void AWarriorEnemyCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	InitEnemyStartUpData();
}

void AWarriorEnemyCharacter::InitEnemyStartUpData()
{
	if (CharacterStartUpData.IsNull())
	{
		return;
	}
	UAssetManager::GetStreamableManager().RequestAsyncLoad(CharacterStartUpData.ToSoftObjectPath(),FStreamableDelegate::CreateLambda(
[this]()
		{
			if (UDataAsset_StartUpDataBase* LoadData = CharacterStartUpData.Get())
			{
				LoadData->GiveToWarriorAbilitySystemComponent(WarriorAbilitySystemComponent);

				Debug::Print(TEXT("Enemy Start Up Data Loaded"));
			}
		}));
}
