// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "CTitleLevel.generated.h"

/**
 * 
 */
UCLASS()
class THECAT_API ACTitleLevel : public ALevelScriptActor
{
	GENERATED_BODY()
public:
	ACTitleLevel();
protected:
	virtual void BeginPlay();

	UPROPERTY(VisibleDefaultsOnly)
		TSubclassOf<class UCTitleWidgetInterface> pTitleWidgetInterfaceClass;

	class UCTitleWidgetInterface* pTitleWidgetInterface;
};
