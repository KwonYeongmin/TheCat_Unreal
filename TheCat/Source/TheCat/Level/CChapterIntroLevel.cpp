#include "CChapterIntroLevel.h"
#include "../Utilities/CHelpers.h"
#include "../Widgets/CIntroWidgetInterface.h"
#include "../Player/CPlayerIntro.h"
#include "../Manager/CGameManager.h"
#include "kismet/GameplayStatics.h"

ACChapterIntroLevel::ACChapterIntroLevel()
{
	CHelpers::GetClass<UCIntroWidgetInterface>(&pTitleWidgetInterfaceClass,
		"/Script/UMGEditor.WidgetBlueprint'/Game/Widget/BP_CIntroWidgetInterface.BP_CIntroWidgetInterface_C'");

	CHelpers::GetClass<ACPlayerIntro>(&pPlayerClass,
		"/Script/Engine.Blueprint'/Game/BP_Character/BP_SH_Intro.BP_SH_Intro_C'");
}

void ACChapterIntroLevel::BeginPlay()
{
	Super::BeginPlay();

	// Wideget Initialize
	pWidgetInterface = CreateWidget<UCIntroWidgetInterface>(GetWorld(), pTitleWidgetInterfaceClass);
	pWidgetInterface->AddToViewport();
	pWidgetInterface->SetVisibility(ESlateVisibility::Visible);
	pWidgetInterface->SetInitialize(this);

	// pPlayer Initialize
	pPlayer = GetWorld()->SpawnActor<ACPlayerIntro>(pPlayerClass, FVector(0,0,0), FRotator(0, 0, 0));
	pPlayer->SetInitialize(this);
}

bool ACChapterIntroLevel::SetPlayerAnimation(int32 animationIndex)
{
	return pPlayer->SetPlayerAnimation(animationIndex);
}

bool ACChapterIntroLevel::Start_SNSInteraction()
{
	return pWidgetInterface->Start_SNSInteraction();
}

bool ACChapterIntroLevel::End_SNSInteraction()
{
	return pPlayer->SetPlayerAnimation(2);
}

bool ACChapterIntroLevel::StartDialogue() 
{
	return pWidgetInterface->StartDialogue();
}

void ACChapterIntroLevel::EndDialogue(int32 iDialogueSegmentIndex)
{
	if (0 == iDialogueSegmentIndex) 
	{
		// 
	}
	else if (1 == iDialogueSegmentIndex) 
	{ 
		// 레벨 이동
	}
}
