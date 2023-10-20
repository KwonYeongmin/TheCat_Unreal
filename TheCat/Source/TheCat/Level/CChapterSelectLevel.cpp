#include "CChapterSelectLevel.h"
#include "../Utilities/CHelpers.h"
#include "../Widgets/CChapterSelectWidgetInterface.h"


ACChapterSelectLevel::ACChapterSelectLevel()
{
	CHelpers::GetClass<UCChapterSelectWidgetInterface>(&pChapterSelectionWidgetInterfaceClass,
		"/Script/UMGEditor.WidgetBlueprint'/Game/Widget/BP_CChapterSelectWidgetInterface.BP_CChapterSelectWidgetInterface_C'");
}


void ACChapterSelectLevel::BeginPlay()
{
	Super::BeginPlay();

	if (nullptr != GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("ACChapterSelectLevel BeginPlay"));
	}

	pChapterSelectionInterface = CreateWidget<UCChapterSelectWidgetInterface>(GetWorld(), pChapterSelectionWidgetInterfaceClass);
	pChapterSelectionInterface->AddToViewport();
	pChapterSelectionInterface->SetVisibility(ESlateVisibility::Visible);
	pChapterSelectionInterface->Begin();
}
