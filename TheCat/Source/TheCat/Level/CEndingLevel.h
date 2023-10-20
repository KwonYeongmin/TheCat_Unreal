// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "CEndingLevel.generated.h"

/**
 * 
 */
UCLASS()
class THECAT_API ACEndingLevel : public ALevelScriptActor
{
	GENERATED_BODY()
public:
	ACEndingLevel();

public:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleDefaultsOnly)
		TSubclassOf<class UCEndingWidgetInterface> pEndingWidgetInterfaceClass;

	class UCEndingWidgetInterface* pEndingWidgetInterface;
};
