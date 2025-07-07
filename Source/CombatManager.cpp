#include "CombatManager.h"
#include "Engine/World.h"
#include "Components/ActorComponent.h"

ACombatManager::ACombatManager()
{
    PrimaryActorTick.bCanEverTick = false;
}

void ACombatManager::BeginPlay()
{
    Super::BeginPlay();
}

void ACombatManager::ProcessCombatants(const TArray<UActorComponent*>& InputCombatants)
{
    Combatants.Empty();
    CombatantInitiativeMap.Empty();

    for (UActorComponent* CombatantComponent : InputCombatants)
    {
        if (CombatantComponent)
        {
            int32 Initiative = 0;
            
            FProperty* InitiativeProperty = CombatantComponent->GetClass()->FindPropertyByName("Initiative");
            if (InitiativeProperty)
            {
                if (FIntProperty* IntProp = CastField<FIntProperty>(InitiativeProperty))
                {
                    Initiative = IntProp->GetPropertyValue_InContainer(CombatantComponent);
                }
            }

            CombatantInitiativeMap.Add(CombatantComponent, Initiative);
        }
    }

    SortCombatantsByInitiative();
}

void ACombatManager::SortCombatantsByInitiative()
{
    TArray<TPair<UActorComponent*, int32>> SortingArray;
    
    for (auto& Pair : CombatantInitiativeMap)
    {
        SortingArray.Add(TPair<UActorComponent*, int32>(Pair.Key, Pair.Value));
    }

    // Sort by initiative (highest first)
    SortingArray.Sort([](const TPair<UActorComponent*, int32>& A, const TPair<UActorComponent*, int32>& B)
    {
        return A.Value > B.Value;
    });

    Combatants.Empty();
    for (const auto& Pair : SortingArray)
    {
        Combatants.Add(Pair.Key);
    }

    CombatantInitiativeMap.Empty();
    for (const auto& Pair : SortingArray)
    {
        CombatantInitiativeMap.Add(Pair.Key, Pair.Value);
    }
}