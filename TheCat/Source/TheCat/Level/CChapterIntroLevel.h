#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "CChapterLevelBase.h"
#include "CChapterIntroLevel.generated.h"

UCLASS()
class THECAT_API ACChapterIntroLevel : public ALevelScriptActor
{
	GENERATED_BODY()
public:
	ACChapterIntroLevel();
protected:
	virtual void BeginPlay();

	UPROPERTY(VisibleDefaultsOnly)
		TSubclassOf<class UCIntroWidgetInterface> pTitleWidgetInterfaceClass;
	class UCIntroWidgetInterface* pWidgetInterface;

	UPROPERTY(VisibleDefaultsOnly)
		TSubclassOf<class ACPlayerIntro> pPlayerClass;
	class ACPlayerIntro* pPlayer;

public:
	UFUNCTION()
		bool SetPlayerAnimation(int32 animationIndex);
	UFUNCTION()
		bool Start_SNSInteraction();
	UFUNCTION()
		bool End_SNSInteraction();
	
	UFUNCTION()
		bool StartDialogue();
	UFUNCTION()
		void EndDialogue(int32 iDialogueSegmentIndex);
};
