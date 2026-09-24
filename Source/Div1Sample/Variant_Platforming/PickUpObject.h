// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PickUpObject.generated.h"

UCLASS()
class DIV1SAMPLE_API APickUpObject : public AActor
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	int count;

	UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	float rotationSpeed;
	
public:	
	// Sets default values for this actor's properties
	APickUpObject();

protected:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void PostAddingPlayCount();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
