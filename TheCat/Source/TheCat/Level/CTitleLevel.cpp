#include "CTitleLevel.h"
#include "../Utilities/CHelpers.h"
#include "../Widgets/CTitleWidgetInterface.h"

ACTitleLevel::ACTitleLevel()
{
	CHelpers::GetClass<UCTitleWidgetInterface>(&pTitleWidgetInterfaceClass,
		"/Script/Engine.Blueprint'/Game/Widget/BP_CTitleWidgetInterface.BP_CTitleWidgetInterface_C'");
}

void ACTitleLevel::BeginPlay()
{
	Super::BeginPlay();

	pTitleWidgetInterface = CreateWidget<UCTitleWidgetInterface>(GetWorld(), pTitleWidgetInterfaceClass);
	pTitleWidgetInterface->AddToViewport();
	pTitleWidgetInterface->SetVisibility(ESlateVisibility::Visible);
	pTitleWidgetInterface->Begin();
}
