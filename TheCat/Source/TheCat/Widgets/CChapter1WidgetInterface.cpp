#include "CChapter1WidgetInterface.h"

#include "Components/Image.h"
#include "Components/Button.h"
#include "Components/Overlay.h"
#include "Components/TextBlock.h"
#include "Components/ScrollBox.h"

#include "../Level/CChapter1Level.h"

#include "Animation/WidgetAnimation.h"

#include "Materials/MaterialInstanceConstant.h"
#include "Materials/MaterialInstanceDynamic.h"

void UCChapter1WidgetInterface::SetInitialize(ACChapter1Level* _pChapter1Level)
{
	m_pChapter1Level = _pChapter1Level;

	if (class UOverlay* pWidgetInformation = Cast<UOverlay>(GetWidgetFromName(TEXT("Widget_UIInformation"))))
	{
		pWidgetInformation->SetVisibility(ESlateVisibility::Hidden);
	}

	// 대화 관련 변수 정리
	m_TextColor_Character = FLinearColor(1.f, 0.0f, 0.0f, 1.0f);

	m_ArrayDialogueSegment.Push(FDialogueSegment(18, 18));
	m_ArrayDialogueSegment.Push(FDialogueSegment(19, 23));
	m_ArrayDialogueSegment.Push(FDialogueSegment(24, 26));
	m_ArrayDialogueSegment.Push(FDialogueSegment(27, 28));
	m_ArrayDialogueSegment.Push(FDialogueSegment(29, 31));
	m_ArrayDialogueSegment.Push(FDialogueSegment(32, 32));
	m_ArrayDialogueSegment.Push(FDialogueSegment(33, 33));
	
	m_iDialogueIndex = m_ArrayDialogueSegment[m_iDialogueSegmentIndex].iStartIndex;

	UMaterialInstance* materialInstance1 = LoadObject<UMaterialInstance>(nullptr, TEXT("/Script/Engine.MaterialInstanceConstant'/Game/Materials/Intro/Dialogue/MI_PlayerDialAnimation.MI_PlayerDialAnimation'"));
	m_ArrayDialoguePlayerAnimations.Push(LoadObject<UTexture>(nullptr, TEXT("/Script/Engine.Texture2D'/Game/Images/UI/Dialogue/Intro/Textures/Intro_SHAnim0.Intro_SHAnim0'")));
	m_ArrayDialoguePlayerAnimations.Push(LoadObject<UTexture>(nullptr, TEXT("/Script/Engine.Texture2D'/Game/Images/UI/Dialogue/Intro/Textures/Intro_SHAnim1.Intro_SHAnim1'")));
	m_ArrayDialoguePlayerAnimations.Push(LoadObject<UTexture>(nullptr, TEXT("/Script/Engine.Texture2D'/Game/Images/UI/Dialogue/Chapter1/Texture/Chapter1_SHAnim3.Chapter1_SHAnim3'")));

	if (nullptr != materialInstance1)
	{
		m_pPlayerDialogueMaterialInstance = UMaterialInstanceDynamic::Create(materialInstance1, this);
	}

	UMaterialInstance* materialInstance2 = LoadObject<UMaterialInstance>(nullptr, TEXT("/Script/Engine.MaterialInstanceConstant'/Game/Materials/Intro/Dialogue/MI_CharacterDialAnimation.MI_CharacterDialAnimation'"));
	m_ArrayDialogueCharacterAnimations.Push(LoadObject<UTexture>(nullptr, TEXT("/Script/Engine.Texture2D'/Game/Images/UI/Dialogue/Chapter1/Texture/GoGo_Anim1.GoGo_Anim1'")));
	m_ArrayDialogueCharacterAnimations.Push(LoadObject<UTexture>(nullptr, TEXT("/Script/Engine.Texture2D'/Game/Images/UI/Dialogue/Chapter1/Texture/GoGo_Anim2.GoGo_Anim2'")));
	m_ArrayDialogueCharacterAnimations.Push(LoadObject<UTexture>(nullptr, TEXT("/Script/Engine.Texture2D'/Game/Images/UI/Dialogue/Chapter1/Texture/GoGo_Anim3.GoGo_Anim3'")));
	
	if (nullptr != materialInstance2)
	{
		m_pCharacterDialogueMaterialInstance = UMaterialInstanceDynamic::Create(materialInstance2, this);
	}

	if (UButton* pDialogueButton = Cast<UButton>(GetWidgetFromName(TEXT("Button_DialogueNext"))))
	{
		pDialogueButton->OnClicked.AddDynamic(this, &UCChapter1WidgetInterface::UpdateDialogue);
	}

	// OnEventEndDialogue.AddDynamic(m_pChapter1Level, &ACChapter1Level::EndDialogue);
	  
}

void UCChapter1WidgetInterface::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{

}

bool UCChapter1WidgetInterface::StartDialogue()
{
	return Super::StartDialogue();
}

void UCChapter1WidgetInterface::UpdateDialogue()
{
	Super::UpdateDialogue();
}

bool UCChapter1WidgetInterface::EndDialogue()
{
	return Super::EndDialogue();
}
