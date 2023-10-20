#include "CChapter1Level.h"
#include "../Utilities/CHelpers.h"
#include"../Player/CPlayer.h"
#include "../Widgets/CChapter1WidgetInterface.h"

/*
*/


ACChapter1Level::ACChapter1Level()
{
	CHelpers::GetClass<UCChapter1WidgetInterface>(&pWidgetInterfaceClass,
		"/Script/UMGEditor.WidgetBlueprint'/Game/Widget/BP_CChapter1WidgetInterface.BP_CChapter1WidgetInterface_C'");


	CHelpers::GetClass<ACPlayer>(&pPlayerClass,
		"/Script/Engine.Blueprint'/Game/BP/BP_SH.BP_SH_C'");

	
}

void ACChapter1Level::BeginPlay()
{
	Super::BeginPlay();

	// Wideget Initialize
	pWidgetInterface = CreateWidget<UCChapter1WidgetInterface>(GetWorld(), pWidgetInterfaceClass);

	if (nullptr != pWidgetInterface)
	{
		pWidgetInterface->AddToViewport();
		pWidgetInterface->SetVisibility(ESlateVisibility::Hidden);
		pWidgetInterface->SetInitialize(this);
	}


	pPlayer = GetWorld()->SpawnActor<ACPlayer>(pPlayerClass, FVector(0, 0, -70.f), FRotator(0, 0, 0));
	if (nullptr != pPlayer)
	{
		pPlayer->SetInitialize(this);
	}
}

bool ACChapter1Level::SetPlayerAnimation(int32 animationIndex)
{
	return false;
}

bool ACChapter1Level::StartDialogue()
{
	return pWidgetInterface->StartDialogue();
}
