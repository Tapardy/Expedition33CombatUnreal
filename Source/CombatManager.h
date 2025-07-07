#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "Components/ActorComponent.h"
#include "CombatManager.generated.h"

UCLASS(BlueprintType, Blueprintable)
class EXPEDITION33COMBAT_API ACombatManager : public AActor
{
    GENERATED_BODY()

public:
    ACombatManager();

protected:
    virtual void BeginPlay() override;

public:
    UPROPERTY(BlueprintReadOnly, Category = "Combat")
    TArray<class UActorComponent*> Combatants;

    UPROPERTY(BlueprintReadOnly, Category = "Combat")
    TMap<class UActorComponent*, int32> CombatantInitiativeMap;

    UFUNCTION(BlueprintCallable, Category = "Combat")
    void ProcessCombatants(const TArray<class UActorComponent*>& InputCombatants);

private:
    void SortCombatantsByInitiative();
};