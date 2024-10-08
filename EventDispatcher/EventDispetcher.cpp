
#include "044_CreateEventDispetcher.generated.h" 

U_044_CreateEventDispetcher* U_044_CreateEventDispetcher::EventDispetcherSingleton = nullptr;


U_044_CreateEventDispetcher::U_044_CreateEventDispetcher()
{
    //set the singleton
    EventDispetcherSingleton = this;
}


U_044_CreateEventDispetcher::~U_044_CreateEventDispetcher()
{
    //destriy 
    EventDispetcherSingleton = nullptr;
}

U_044_CreativeEventDispatcher* U_044_CreativeEventDispatcher::GetEventDispatcherSingleton(){
    return U_044_CretiveEventDispatcher::EventDispatcherSingleton;
}


void U_044_CreateEventDispatcher::OnMultiDispatcherCalled()
{
    UE_LOG(LogTemp, Log, TEXT("OnMultiDispatcherCalled"));
}

void U_044_CreateEventDispatcher::OnMultiDispatcher_OneParamCalled(bool MyBool)
{
    UE_LOG(LogTemp, Log, TEXT("OnMultiDispatcher_OneParam_Called -%s"), *FString(MyBool ? "True" : "False"));
}


void U_044_CreateEventDispetcher::BindEventDispatchers(){
    //Because event dispatcher are on an object
    U_044_CreateEventDispatcher* Singleton = GetEventDispatcherSingleton();
    //bind event dispetchers
    Singleton->MultiDispatcher.AddUniqueDynamic(Singleton, &U_044_CreateEventDispatcher::OnMultiDispatcherCalled);
    Singleton->MultiDispatcher_OneParam.AddUniqueDynamic(Singleton, &U_044_CreateEventDispatcher::OnMultiDispatcher_OneParamCalled);
    Singleton->MultiDispatcher_TwoParams.AddUniqueDynamic(Singleton, &U_044_CreateEventDispatcher::OnMultiDispatcher_TwoParamsCalled);
}


void U_044_CreateEventDispetcher::UnbindEventDispatchers(){
    //Because event dispatcher are on an object
    U_044_CreateEventDispatcher* Singleton = GetEventDispatcherSingleton();
    //unbind event dispatcher
    Singleton->MultiDispatcher.RemoveDynamic(Singleton, &U_044_CreateEventDispatcher::OnMultiDispatcherCalled);
    Singleton->MultiDispatcher_OneParam.RemoveDynamic(Singleton, &U_044_CreateEventDispatcher::OnMultiDispatcher_OneParamCalled);
    Singleton->MultiDispatcher_TwoParams.RemoveDynamic(Singleton, &U_044_CreateEventDispatcher::OnMultiDispatcher_TwoParamsCalled);
}


void U_044_CreateEventDispetcher::CallEventDispatchers(){
    //Because event dispatcher are on an object
    U_044_CreateEventDispatcher* Singleton = GetEventDispatcherSingleton();
    //call event disaptchers
    Singleton->MultiDispatcher.Broadcast();
    Singleton->MultiDispatcher_OneParam.Broadcast(FMath::RandBool());
    Singleton->MultiDispatcher_TwoParams.Broadcast(FMath::RandBool(), FMath::RandRange(0.0f, 100.0f));
    Sin
}