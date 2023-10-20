#include "CIntroWidgetInterface.h"

#include "Components/Image.h"
#include "Components/Button.h"
#include "Components/Overlay.h"
#include "Components/TextBlock.h"
#include "Components/ScrollBox.h"

#include "Animation/WidgetAnimation.h"

#include "Materials/MaterialInstanceConstant.h"
#include "Materials/MaterialInstanceDynamic.h"

#include "../Manager/CTextDataSubsystemManager.h"
#include "../Manager/CGameManager.h"

#include "Kismet/GameplayStatics.h"

#include "../Player/CPlayerIntro.h"

#include "../Utilities/CHelpers.h"

#include "../Level/CChapterIntroLevel.h"

void UCIntroWidgetInterface::SetInitialize(class ACChapterIntroLevel* _pIntroLevel)
{
	Super::SetInitialize();

	m_pIntroLevel = _pIntroLevel;

	// 라디오 대사 관련 변수 정리
	m_iRadioStartIndex = 1;
	m_iRadioDialCount = m_iRadioStartIndex;
	m_iRadioEndIndex = 3;

	if (UButton* pRadioDialButton = Cast<UButton>(GetWidgetFromName(TEXT("Button_RadioArrow"))))
	{
		pRadioDialButton->OnClicked.AddDynamic(this, &UCIntroWidgetInterface::Private_ClickRadioDialArrowButton);
	}

	if (class UOverlay* pWidgetRadioDialogue = Cast<UOverlay>(GetWidgetFromName(TEXT("Widget_Radio"))))
	{
		pWidgetRadioDialogue->SetVisibility(ESlateVisibility::Visible);
	}
	
	// 대화 관련 변수 정리
	m_TextColor_Character = FLinearColor(1.f, 0.0f, 0.0f, 1.0f);

	m_ArrayDialogueSegment.Push(FDialogueSegment(1, 4));
	m_ArrayDialogueSegment.Push(FDialogueSegment(5, 17));
	m_iDialogueIndex = m_ArrayDialogueSegment[m_iDialogueSegmentIndex].iStartIndex;

	UMaterialInstance* materialInstance1 = LoadObject<UMaterialInstance>(nullptr, TEXT("/Script/Engine.MaterialInstanceConstant'/Game/Materials/Intro/Dialogue/MI_PlayerDialAnimation.MI_PlayerDialAnimation'"));
	m_ArrayDialoguePlayerAnimations.Push(LoadObject<UTexture>(nullptr, TEXT("/Script/Engine.Texture2D'/Game/Images/UI/Dialogue/Intro/Textures/Intro_SHAnim0.Intro_SHAnim0'")));
	m_ArrayDialoguePlayerAnimations.Push(LoadObject<UTexture>(nullptr, TEXT("/Script/Engine.Texture2D'/Game/Images/UI/Dialogue/Intro/Textures/Intro_SHAnim1.Intro_SHAnim1'")));

	if (nullptr != materialInstance1)
	{
		m_pPlayerDialogueMaterialInstance = UMaterialInstanceDynamic::Create(materialInstance1, this);
	}

	UMaterialInstance* materialInstance2 = LoadObject<UMaterialInstance>(nullptr, TEXT("/Script/Engine.MaterialInstanceConstant'/Game/Materials/Intro/Dialogue/MI_CharacterDialAnimation.MI_CharacterDialAnimation'"));
	m_ArrayDialogueCharacterAnimations.Push(LoadObject<UTexture>(nullptr, TEXT("/Script/Engine.Texture2D'/Game/Images/UI/Dialogue/Intro/Textures/catgod_1332.catgod_1332'")));
	if (nullptr != materialInstance2)
	{
		m_pCharacterDialogueMaterialInstance = UMaterialInstanceDynamic::Create(materialInstance2, this);
	}

	if (UButton* pDialogueButton = Cast<UButton>(GetWidgetFromName(TEXT("Button_DialogueNext"))))
	{
		pDialogueButton->OnClicked.AddDynamic(this, &UCIntroWidgetInterface::UpdateDialogue);
	}

	OnEventEndDialogue.AddDynamic(m_pIntroLevel, &ACChapterIntroLevel::EndDialogue);
	
	
	// SNS 인터랙션 관련 변수 정리
	
	EndDelegate.BindDynamic(this, &UCIntroWidgetInterface::Private_EndSNSInteraction);
	m_bIsSNSInteraction = false;
	BindToAnimationFinished(m_pAnimationSNSWindowUI, EndDelegate);


	// 별자리 잇기 인터랙션 관련 변수 정리
	if (UButton* pText_Button = Cast<UButton>(GetWidgetFromName(TEXT("Test_Button"))))
	{
		pText_Button->OnClicked.AddDynamic(this, &UCIntroWidgetInterface::TestEnd_ConstellationInteraction);
	}
	
	// 챕터 시작시 실행되는 함수
	Private_ClickRadioDialArrowButton();
	PlayAnimation(m_pAnimationRadioUI);
}

void UCIntroWidgetInterface::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	Private_UpdateSNSInteraction();
}

bool UCIntroWidgetInterface::Private_UpdateSNSInteraction() 
{
	if (false == m_bIsSNSInteraction)
		return false;

	const class UScrollBox* pScrollTimeline = Cast<UScrollBox>(GetWidgetFromName(TEXT("ScrollBox_Timeline")));

	if (nullptr == pScrollTimeline)
		return false;

	const float timelineOffsetY = pScrollTimeline->GetScrollOffset();

	const UGameInstance* pGameInstance = Cast<UCGameManager>(UGameplayStatics::GetGameInstance(GetWorld()));
	UCTextDataSubsystemManager* pTextDataManager = pGameInstance->GetSubsystem<UCTextDataSubsystemManager>();

	if (nullptr == pTextDataManager)
		return false;

	int32 timelineIndex = -1;
	if (timelineOffsetY >= 80 && timelineOffsetY < 960)
	{
		timelineIndex = 0;
	}
	else if (timelineOffsetY >= 960 && timelineOffsetY < 2000)
	{
		timelineIndex = 1;
	}
	else if (timelineOffsetY >= 2000 && timelineOffsetY < 3040)
	{
		timelineIndex = 2;
	}
	else if (timelineOffsetY >= 3040 && timelineOffsetY < 3360)
	{
		timelineIndex = 3;
	}
	else if (timelineOffsetY >= 3360)
	{
		for (int i = 0; i < 4; ++i)
		{
			FName textString = FName("Text_SNSInteraction" + FString::FromInt(i + 1));
			if (UTextBlock* textBlock = Cast<UTextBlock>(GetWidgetFromName(textString)))
			{
				textBlock->SetVisibility(ESlateVisibility::Hidden);
			}
		}

		PlayAnimation(m_pAnimationSNSWindowUI);
		m_bIsSNSInteraction = false;
		return true;
	}

	if (timelineIndex < 0)
		return false;

	Private_ScrollSNSInteraction(timelineIndex, pTextDataManager->GetUITextData(timelineIndex + 4)->Text);
	return true;
}

bool UCIntroWidgetInterface::Private_ScrollSNSInteraction(int32 _iTimelineIndex, FString text)
{
	FString textString = "Text_SNSInteraction" + FString::FromInt(_iTimelineIndex + 1);
	FName textName = FName(*textString);
	UTextBlock* textBlock = Cast<UTextBlock>(GetWidgetFromName(textName));

	if (nullptr == textBlock)
		return false;
	textBlock->SetText(FText::FromString(text));
	textBlock->SetVisibility(ESlateVisibility::Visible);
	return true;
}

void UCIntroWidgetInterface::Private_EndSNSInteraction()
{
	m_pIntroLevel->End_SNSInteraction();
}

bool UCIntroWidgetInterface::IsSNSInteraction() const
{
	return m_bIsSNSInteraction;
}

bool UCIntroWidgetInterface::StartDialogue()
{
	return Super::StartDialogue();
}


// 자신의 차례일 때, 글자 색 바뀌기, 애니메이션 색 조절
void UCIntroWidgetInterface::UpdateDialogue()
{
	Super::UpdateDialogue();
}

bool UCIntroWidgetInterface::EndDialogue()
{
	bool rt = Super::EndDialogue();
	
	if (0 == m_iDialogueSegmentIndex)
	{
		Start_ConstellationInteraction();
	}
	
	++m_iDialogueSegmentIndex;

	return rt;
}

bool UCIntroWidgetInterface::Start_SNSInteraction()
{
	if (class UOverlay* pWidgetSNSInteractionWindow = Cast<UOverlay>(GetWidgetFromName(TEXT("Widget_SNSInteraction"))))
	{
		pWidgetSNSInteractionWindow->SetVisibility(ESlateVisibility::Visible);
		m_bIsSNSInteraction = true;
		return true;
	}
	return false;
}

bool UCIntroWidgetInterface::Start_ConstellationInteraction()
{
	if (class UOverlay* pWidgetConstellationInteractionWindow = Cast<UOverlay>(GetWidgetFromName(TEXT("Widget_ConstellationInteraction"))))
	{
		pWidgetConstellationInteractionWindow->SetVisibility(ESlateVisibility::Visible);
		// End_ConstellationInteraction();
		return true;
	}
	return false;
}

bool UCIntroWidgetInterface::End_ConstellationInteraction()
{
	if (class UOverlay* pWidgetConstellationInteractionWindow = Cast<UOverlay>(GetWidgetFromName(TEXT("Widget_ConstellationInteraction"))))
	{
		pWidgetConstellationInteractionWindow->SetVisibility(ESlateVisibility::Hidden);
		StartDialogue();
		return true;
	}
	return false;
}

void UCIntroWidgetInterface::TestEnd_ConstellationInteraction()
{
	End_ConstellationInteraction();
}

void UCIntroWidgetInterface::Private_ClickRadioDialArrowButton()
{
	const UGameInstance* pGameInstance = Cast<UCGameManager>(UGameplayStatics::GetGameInstance(GetWorld()));
	UCTextDataSubsystemManager* pTextDataManager = pGameInstance->GetSubsystem<UCTextDataSubsystemManager>();
	
	if (nullptr == pTextDataManager)
		return;

	struct FIllustrateTextData* pIllustreate = pTextDataManager->GetIllustrateTextData(m_iRadioDialCount);
	if (nullptr != pIllustreate)
	{
		if (UTextBlock* pRadioText = Cast<UTextBlock>(GetWidgetFromName(TEXT("Text_RadioDialogue"))))
		{
			pRadioText->SetText(FText::FromString(pIllustreate->Text));
		}
	}

	if (m_iRadioDialCount > m_iRadioEndIndex) 
	{
		if (class UOverlay* pWidgetRadioDialogue = Cast<UOverlay>(GetWidgetFromName(TEXT("Widget_Radio"))))
		{
			pWidgetRadioDialogue->SetVisibility(ESlateVisibility::Hidden);
		}
		m_pIntroLevel->SetPlayerAnimation(1);
	}
	else
	{
		++m_iRadioDialCount;
	}
}
