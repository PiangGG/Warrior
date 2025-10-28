// Piang


#include "WarriorWeaponBase.h"

#include "Components/BoxComponent.h"
#include "Warrior/WarriorDebugHelper.h"

// Sets default values
AWarriorWeaponBase::AWarriorWeaponBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WeaponMesh"));
	SetRootComponent(WeaponMesh);
	
	WeaponCollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("WeaponCollisionBox"));
	WeaponCollisionBox->SetupAttachment(RootComponent);
	WeaponCollisionBox->SetBoxExtent(FVector(20.0));
	WeaponCollisionBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	WeaponCollisionBox->OnComponentBeginOverlap.AddUniqueDynamic(this,&ThisClass::OnCollisionBoxBeginOverlap);
	WeaponCollisionBox->OnComponentEndOverlap.AddUniqueDynamic(this,&ThisClass::OnCollisionBoxEndOverlap);
}

void AWarriorWeaponBase::OnCollisionBoxBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResul)
{
	APawn * WeaponOwningPawn = Cast<APawn>(GetInstigator());

	if (APawn* HitPawn = Cast<APawn>(OtherActor))
	{
		if (HitPawn != WeaponOwningPawn)
		{
			//Debug::Print(GetName()+TEXT("Begin overlap with ")+HitPawn->GetName(),FColor::Green);
			OnWeaponHitTarget.ExecuteIfBound(OtherActor);
		}
	}
}

void AWarriorWeaponBase::OnCollisionBoxEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	APawn * WeaponOwningPawn = Cast<APawn>(GetInstigator());

	if (APawn* HitPawn = Cast<APawn>(OtherActor))
	{
		if (HitPawn != WeaponOwningPawn)
		{
			//Debug::Print(GetName()+TEXT("End overlap with ")+HitPawn->GetName(),FColor::Red);
			OnWeaponPullFromTarget.ExecuteIfBound(OtherActor);
		}
	}
}

