#include "CombatManager.h"

ACombatManager::ACombatManager()
{
    PrimaryActorTick.bCanEverTick = false;
}

void ACombatManager::BeginPlay()
{
    Super::BeginPlay();
}

TMap<UActorComponent*, float> ACombatManager::ProcessCombatants(UPARAM(ref) TMap<UActorComponent*, float>& TurnOrder)
{
    TMap<UActorComponent*, float> SortedTurnOrder = SortCombatantsByInitiative(TurnOrder);
    
    TurnOrder = SortedTurnOrder;
    
    for (int32 i = 0; i < Combatants.Num(); i++)
    {
        if (Combatants[i])
        {
            FString ComponentName = Combatants[i]->GetName();
            float Initiative = SortedTurnOrder[Combatants[i]];
            UE_LOG(LogTemp, Log, TEXT("Combatant: %s | Initiative: %.2f"), *ComponentName, Initiative);
        }
    }
    
    return SortedTurnOrder;
}

TMap<UActorComponent*, float> ACombatManager::SortCombatantsByInitiative(const TMap<UActorComponent*, float>& TurnOrder)
{
    TArray<TPair<UActorComponent*, float>> SortingArray = TurnOrder.Array();
    SortingArray.Sort([](const TPair<UActorComponent*, float>& A, const TPair<UActorComponent*, float>& B)
    {
        return A.Value > B.Value;
    });
    
    Combatants.Empty();
    TMap<UActorComponent*, float> SortedTurnOrder;
    
    for (const auto& Pair : SortingArray)
    {
        Combatants.Add(Pair.Key);
        SortedTurnOrder.Add(Pair.Key, Pair.Value);
    }
    
    return SortedTurnOrder;
}