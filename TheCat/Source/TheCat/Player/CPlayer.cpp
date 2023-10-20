#include "CPlayer.h"
#include "../Level/CChapter1Level.h"
#include "../Utilities/CHelpers.h"

#include "PaperFlipbook.h"
#include "PaperFlipbookComponent.h"

#include "GameFramework/CharacterMovementComponent.h"

ACPlayer::ACPlayer()
{
	m_iAnimationIndex = 0;

	m_pPaperFlipbookComponent = CHelpers::GetComponent<UPaperFlipbookComponent>(this);

	// CHelpers::GetAsset<UPaperFlipbook>(&m_pSHFlipbookAnimations[0], "/Script/Paper2D.PaperFlipbook'/Game/Images/Player/Flipbooks/Player_Idle_Flipbook.Player_Idle_Flipbook'");
	// CHelpers::GetAsset<UPaperFlipbook>(&m_pSHFlipbookAnimations[1], "/Script/Paper2D.PaperFlipbook'/Game/Images/Player/Flipbooks/Player_Walk_Flipbook.Player_Walk_Flipbook'");
	
	// m_pCharacterMovementComponent = CHelpers::GetComponent<UCharacterMovementComponent>(this);

	SetPlayerAnimation(0);

//	CurrenVelocity = 5.0f;

	// m_pPaperFlipbookComponent->Play();
	// m_pPaperFlipbookComponent->SetLooping(true);
}

bool ACPlayer::SetInitialize(ACChapter1Level* _pChapter1Level)
{
	m_pChapter1Level = _pChapter1Level;
	return false;
}

void ACPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent);
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// PlayerInputComponent->BindAxis("MoveRight", this, &ACPlayer::OnMoveHorizontal);
}

void ACPlayer::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	// Move(DeltaSeconds);
}

// void ACPlayer::OnMoveHorizontal(float InAxis)
// {
// 	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
// 	Direction.Z = 0.0f;
// 	Direction.Normalize();
// 	MoveDirection += Direction * FMath::Clamp(InAxis, -1.0f, 1.0f);
// }
// 
// void ACPlayer::Move(float DeltaTime)
// {
// 	if (MoveDirection.IsZero()) 
// 	{
// 		return;
// 	}
// 	MoveDirection.Normalize();
// 	AddMovementInput(MoveDirection, CurrenVelocity * DeltaTime);
// 	MoveDirection.Set(0.0f, 0.0f, 0.0f);
// 
// 	float vectorLength = m_pCharacterMovementComponent->GetVelocityForRVOConsideration().Length();
// 	if (vectorLength > 0) 
// 	{
// 		m_pPaperFlipbookComponent->SetFlipbook(m_pSHFlipbookAnimations[1]);
// 	}
// 	else 
// 	{
// 		m_pPaperFlipbookComponent->SetFlipbook(m_pSHFlipbookAnimations[0]);
// 	}
// 
// }

bool ACPlayer::SetPlayerAnimation(int32 _animIndex)
{
	if (nullptr == m_pSHFlipbookAnimations[_animIndex])
		return false;
	if (nullptr == m_pPaperFlipbookComponent)
		return false;
	bool res = m_pPaperFlipbookComponent->SetFlipbook(m_pSHFlipbookAnimations[_animIndex]);
	m_iAnimationIndex = _animIndex;
	m_pPaperFlipbookComponent->SetLooping(false);
	m_pPaperFlipbookComponent->Play();
	return true;
}

bool ACPlayer::StartDialogue()
{
	return m_pChapter1Level->StartDialogue();
}
