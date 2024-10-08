#pragma once

#include "Kismet/BlueprintFunctionLibrary.h" // Engine
#include "Delegates/DelegateCombinations.h" // Core
#include "044_CreateEventDispetcher.generated.h" 

//Delegat that can bind to multiple UNFUNCTIONs simutaneously
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FMultiDispathcer); //class
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMultiDispathcer_OneParam, bool, MyBool);
DECLARE_DYNAMIC_MULRICAS_DELEGATE_TwoParams(FMultiDispathcer_TwoParams, bool, MyBool, float, MyFloat);

UCLASS()
class U_044_CreateEventDispetcher : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public: //this are the event dispatchers
    UPROPETRY(BlueprintAssignable, Category = "Event Dispetcher")
        FMultiDispathcer MultiDispatcher;
    UPROPETRY(BlueprintAssignable, Category = "Event Dispetcher")
        FMultiDispathcer_OneParam MultiDispatcher_OneParam;
    UPROPETRY(BlueprintAssignable, Category = "Event Dispetcher")
        FMultiDispathcer_TwoParams MultiDispatcher_TwoParams;
private:
    UFUNCTION()
        void OnMultiDispatcherCalled();
    UFUNCTION()
        void OnMultiDispatcher_OneParamCalled(bool MyBool);
    UFUNCTION()
        void OnMultiDispatcher_TwoParamsCalled(bool MyBool, float MyFloat);

private:
    static U_044_CreateEventDispetcher* EventDispetcherSingleton;

     U_044_CreateEventDispetche();
      ~U_044_CreateEventDispetche();
public:

    UFUNCTION(BlueprintPure, Category = "Event Dispetcher")
        static U_044_CreateEventDispetcher* GetEventDispetcherSingleton();
public:
//Bind all the event dispatchers 
    UFUNCTION(BlueprintCallable, Category = "Event Dispetcher")
        static void BindEventDispatchers();
    UFUNCTION(BlueprintCallable, Category = "Event Dispetcher")
        static void UnbindEventDispatchers();
    UFUNCTION(BlueprintCallable, Category = "Event Dispetcher")
        static void CallEventDispatchers();
};

