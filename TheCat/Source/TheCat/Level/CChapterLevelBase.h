// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "CChapterLevelBase.generated.h"

/**
 * 
 */
UCLASS()
class THECAT_API ACChapterLevelBase : public ALevelScriptActor
{
	GENERATED_BODY()
public:
	ACChapterLevelBase();
protected:
	virtual void BeginPlay();
public:
	virtual bool StartDialogue();

protected:
	// UPROPERTY(VisibleDefaultsOnly)
	// TSubclassOf<class UCIntroWidgetInterface> pWidgetInterfaceClass;
	// class UCWidgetInterfaceBase* pWidgetInterface;
	// class ACPlayer* pPlayer;
};
