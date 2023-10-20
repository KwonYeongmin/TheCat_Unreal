// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "../Level/CChapterLevelBase.h"
#include "CChapter1Level.generated.h"

/**
 * 
 */
UCLASS()
class THECAT_API ACChapter1Level : public ALevelScriptActor
{
	GENERATED_BODY()
public:
	ACChapter1Level();
	virtual void BeginPlay() override;
	bool SetPlayerAnimation(int32 animationIndex);

public :
	virtual bool StartDialogue();
protected:
	UPROPERTY()
	TSubclassOf<class UCChapter1WidgetInterface> pWidgetInterfaceClass;
	class UCChapter1WidgetInterface* pWidgetInterface;

	UPROPERTY()
	TSubclassOf<class ACPlayer> pPlayerClass;
	class ACPlayer* pPlayer;
};
