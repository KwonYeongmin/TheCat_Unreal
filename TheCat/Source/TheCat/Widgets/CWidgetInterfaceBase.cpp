#include "CWidgetInterfaceBase.h"
#include "Components/Overlay.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"

#include "../Manager/CTextDataSubsystemManager.h"
#include "../Manager/CGameManager.h"

#include "Kismet/GameplayStatics.h"

void UCWidgetInterfaceBase::SetInitialize()
{
	m_bDialogueStart = false;
	m_iDialogueSegmentIndex = 0;
	m_iDialogueIndex = 0;
	m_TextColor_Player = FLinearColor(1.f, 1.f, 1.f, 1.f);
}


bool UCWidgetInterfaceBase::StartDialogue() 
{
	if (false == m_bDialogueStart)
	{
		m_iDialogueIndex = m_ArrayDialogueSegment[m_iDialogueSegmentIndex].iStartIndex;
		m_bDialogueStart = true;
	}
	UpdateDialogue();

	return true;
}

void UCWidgetInterfaceBase::UpdateDialogue()
{
	const UGameInstance* pGameInstance = Cast<UCGameManager>(UGameplayStatics::GetGameInstance(GetWorld()));
	UCTextDataSubsystemManager* pTextDataManager = pGameInstance->GetSubsystem<UCTextDataSubsystemManager>();

	if (nullptr == pTextDataManager)
		return;

	const FDialogueTextData* pTextData = pTextDataManager->GetDialogueTextData(m_iDialogueIndex);

	if (nullptr == pTextData)
		return;

	if (UOverlay* _pDialogueWidget = Cast<UOverlay>(GetWidgetFromName("Widget_Dialogue")))
	{
		_pDialogueWidget->SetVisibility(ESlateVisibility::Visible);
	}
	else
		return;

	UImage* pPlayerImage = Cast<UImage>(GetWidgetFromName("Image_playerAnimation"));
	UImage* pCharacterImage = Cast<UImage>(GetWidgetFromName("Image_CharacterAnimation"));

	if (nullptr == pPlayerImage || nullptr == pCharacterImage)
		return;

	if (nullptr != m_pPlayerDialogueMaterialInstance)
	{
		if (pTextData->SHAnim == 0)
		{
			pPlayerImage->SetVisibility(ESlateVisibility::Hidden);
		}
		else
		{
			m_pPlayerDialogueMaterialInstance->SetTextureParameterValue("TextureName", m_ArrayDialoguePlayerAnimations[pTextData->SHAnim - 1]);
			pPlayerImage->SetBrushFromMaterial(m_pPlayerDialogueMaterialInstance);
			PlayAnimation(m_pAnimationPlayerDialogue);
		}
	}

	// 캐릭터 애니메이션
	if (nullptr != m_pCharacterDialogueMaterialInstance)
	{
		if (pTextData->CatAnim == 0)
		{
			pCharacterImage->SetVisibility(ESlateVisibility::Hidden);
		}
		else
		{
			m_pCharacterDialogueMaterialInstance->SetTextureParameterValue("TextureName", m_ArrayDialogueCharacterAnimations[pTextData->CatAnim - 1]);
			pCharacterImage->SetBrushFromMaterial(m_pCharacterDialogueMaterialInstance);
			PlayAnimation(m_pAnimationCharacterDialogue);
		}
	}

	if (UTextBlock* pDialogueText = Cast<UTextBlock>(GetWidgetFromName("Text_Dialogue")))
	{
		if (pTextData->Name == "Sunhwa")
		{
			pDialogueText->SetColorAndOpacity(m_TextColor_Player);
			pPlayerImage->SetColorAndOpacity(FLinearColor(1.f, 1.f, 1.f, 1.f));
			pCharacterImage->SetColorAndOpacity(FLinearColor(0.7f, 0.7f, 0.7f, 1.0f));
		}
		else
		{
			// 인트로 고양이신 안뜸 ㅜㅜ
			pDialogueText->SetColorAndOpacity(m_TextColor_Character);
			pPlayerImage->SetColorAndOpacity(FLinearColor(0.7f, 0.7f, 0.7f, 1.0f));
			pCharacterImage->SetColorAndOpacity(FLinearColor(1.f, 1.f, 1.f, 1.f));
		}

		pDialogueText->SetText(FText::FromString(pTextData->Content));
	}

	if (m_ArrayDialogueSegment[m_iDialogueSegmentIndex].iEndIndex == m_iDialogueIndex)
	{
		EndDialogue();
	}
	++m_iDialogueIndex;
}

bool UCWidgetInterfaceBase::EndDialogue()
{
	if (UOverlay* _pDialogueWidget = Cast<UOverlay>(GetWidgetFromName("Widget_Dialogue")))
		_pDialogueWidget->SetVisibility(ESlateVisibility::Hidden);

	m_bDialogueStart = false;

	return true;
}