#include "CPlayerIntro.h"
#include "PaperFlipbook.h"
#include "PaperFlipbookComponent.h"

#include "../Utilities/CHelpers.h"
#include "../Level/CChapterIntroLevel.h"

ACPlayerIntro::ACPlayerIntro()
{
	m_iAnimationIndex = 0;

	m_pPaperFlipbookComponent = CHelpers::GetComponent<UPaperFlipbookComponent>(this);
	
	// m_pPaperFlipbookComponent->SetLooping(false);

	CHelpers::GetAsset<UPaperFlipbook>(&m_pSHFlipbookAnimations[0], "/Script/Paper2D.PaperFlipbook'/Game/Images/Intro/Characters/FlipBook/Intro_SH_FB_Idle.Intro_SH_FB_Idle'");
	CHelpers::GetAsset<UPaperFlipbook>(&m_pSHFlipbookAnimations[1], "/Script/Paper2D.PaperFlipbook'/Game/Images/Intro/Characters/FlipBook/Intro_SH_FB_1.Intro_SH_FB_1'");
	CHelpers::GetAsset<UPaperFlipbook>(&m_pSHFlipbookAnimations[2], "/Script/Paper2D.PaperFlipbook'/Game/Images/Intro/Characters/FlipBook/Intro_SH_FB_2.Intro_SH_FB_2'");
	
	SetPlayerAnimation(0);
}

void ACPlayerIntro::SetInitialize(ACChapterIntroLevel* _pIntroLevel)
{
	m_pIntroLevel = _pIntroLevel;
}

void ACPlayerIntro::BeginPlay()
{
	Super::BeginPlay();

	m_pPaperFlipbookComponent->OnFinishedPlaying.AddDynamic(this, &ACPlayerIntro::Private_FinshPlaying);
}

void ACPlayerIntro::Private_FinshPlaying()
{
	if (m_iAnimationIndex <= 0)
		return;

	switch (m_iAnimationIndex) 
	{
	case 1: 
		m_pIntroLevel->Start_SNSInteraction();
		break;
	case 2: 
		m_pIntroLevel->StartDialogue();
		break;
	}
}



bool ACPlayerIntro::SetPlayerAnimation(int32 _iAnimIndex)
{
	if (nullptr == m_pSHFlipbookAnimations[_iAnimIndex])
		return false;
	if (nullptr == m_pPaperFlipbookComponent)
		return false;
	bool res = m_pPaperFlipbookComponent->SetFlipbook(m_pSHFlipbookAnimations[_iAnimIndex]);
	m_iAnimationIndex = _iAnimIndex;
	m_pPaperFlipbookComponent->SetLooping(false);
	m_pPaperFlipbookComponent->Play();
	
	return res;
}
