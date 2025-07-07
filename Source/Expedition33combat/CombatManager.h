#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
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

    UFUNCTION(BlueprintCallable, Category = "Combat")
    TMap<UActorComponent*, float> ProcessCombatants(UPARAM(ref) TMap<UActorComponent*, float>& TurnOrder);

private:
    TMap<UActorComponent*, float> SortCombatantsByInitiative(const TMap<UActorComponent*, float>& TurnOrder);
};
