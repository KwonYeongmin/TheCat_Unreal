#include "CEndingLevel.h"
#include "../Utilities/CHelpers.h"
#include "../Widgets/CEndingWidgetInterface.h"

ACEndingLevel::ACEndingLevel()
{
	CHelpers::GetClass<UCEndingWidgetInterface>(&pEndingWidgetInterfaceClass,
		"/Script/UMGEditor.WidgetBlueprint'/Game/Widget/BP_CEndingWidgetInterface.BP_CEndingWidgetInterface_C'");
}

void ACEndingLevel::BeginPlay()
{
	Super::BeginPlay();
	
	pEndingWidgetInterface = CreateWidget<UCEndingWidgetInterface>(GetWorld(), pEndingWidgetInterfaceClass);
	pEndingWidgetInterface->AddToViewport();
	pEndingWidgetInterface->SetVisibility(ESlateVisibility::Visible);
	pEndingWidgetInterface->Begin();
}