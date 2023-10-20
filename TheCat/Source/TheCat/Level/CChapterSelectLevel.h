// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "CChapterSelectLevel.generated.h"

/**
 * 
 */
UCLASS()
class THECAT_API ACChapterSelectLevel : public ALevelScriptActor
{
	GENERATED_BODY()

public:
	ACChapterSelectLevel();

public:
	virtual void BeginPlay() override;

protected:
	UPROPERTY(VisibleDefaultsOnly)
		TSubclassOf<class UCChapterSelectWidgetInterface> pChapterSelectionWidgetInterfaceClass;
	
	class UCChapterSelectWidgetInterface* pChapterSelectionInterface;
};
