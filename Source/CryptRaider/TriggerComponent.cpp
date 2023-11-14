// Fill out your copyright notice in the Description page of Project Settings.


#include "TriggerComponent.h"

UTriggerComponent::UTriggerComponent()
{
  PrimaryComponentTick.bCanEverTick = true;

}

// Called when the game starts
void UTriggerComponent::BeginPlay()
{
	Super::BeginPlay();	
}

void UTriggerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
  Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

  TArray<AActor*> Actors;
  GetOverlappingActors(Actors);

  for(int32 i = 0; i < Actors.Num(); i++)
  {
    FString ActorName = Actors[i]->GetActorNameOrLabel();
    UE_LOG(LogTemp, Display, TEXT("Overlapping: %s"), *ActorName);
  }
}