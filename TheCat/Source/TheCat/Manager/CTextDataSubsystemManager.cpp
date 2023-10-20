#include "CTextDataSubsystemManager.h"

UCTextDataSubsystemManager::UCTextDataSubsystemManager()
{
	m_pDialogueTextData = nullptr;
	m_pIllustrateTextData = nullptr;
	m_pUITextData = nullptr;

	FString dialogueTextData = TEXT("/Script/Engine.DataTable'/Game/Resources/csv/DialogueText_verKor.DialogueText_verKor'");
	static ConstructorHelpers::FObjectFinder<UDataTable> DT_DIALOGUE(*dialogueTextData);
	if (DT_DIALOGUE.Succeeded())
	{
		m_pDialogueTextData = DT_DIALOGUE.Object;
	}

	FString illustrateTextData = TEXT("/Script/Engine.DataTable'/Game/Resources/csv/IllustText_verKor.IllustText_verKor'");
	static ConstructorHelpers::FObjectFinder<UDataTable> DT_ILLUSTRATE(*illustrateTextData);
	if (DT_ILLUSTRATE.Succeeded())
	{
		m_pIllustrateTextData = DT_ILLUSTRATE.Object;
	}

	FString uiTextData = TEXT("/Script/Engine.DataTable'/Game/Resources/csv/UIText_verKor.UIText_verKor'");
	static ConstructorHelpers::FObjectFinder<UDataTable> DT_UITEXTDATA(*uiTextData);
	if (DT_UITEXTDATA.Succeeded())
	{
		m_pUITextData = DT_UITEXTDATA.Object;
	}
}

struct FUITextData* UCTextDataSubsystemManager::GetUITextData(int32 index) const
{
	return m_pUITextData->FindRow<FUITextData>(*FString::FromInt(index), TEXT(""));
}

struct FDialogueTextData* UCTextDataSubsystemManager::GetDialogueTextData(int32 index) const
{
	return m_pDialogueTextData->FindRow<FDialogueTextData>(*FString::FromInt(index), TEXT(""));
}

struct FIllustrateTextData* UCTextDataSubsystemManager::GetIllustrateTextData(int32 index) const
{
	return m_pIllustrateTextData->FindRow<FIllustrateTextData>(*FString::FromInt(index), TEXT(""));
}
