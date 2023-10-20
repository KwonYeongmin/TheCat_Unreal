#include "CChapterLevelBase.h"
#include "../Widgets/CWidgetInterfaceBase.h"

ACChapterLevelBase::ACChapterLevelBase()
{
}

void ACChapterLevelBase::BeginPlay()
{
}

bool ACChapterLevelBase::StartDialogue()
{
	return true;
	//return pWidgetInterface->StartDialogue();
}
