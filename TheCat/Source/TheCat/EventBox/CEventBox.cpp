#include "CEventBox.h"

#include "Kismet/GameplayStatics.h"

#include "Components/SceneComponent.h"
#include "Components/BoxComponent.h"
#include "Components/TextRenderComponent.h"

#include "../Utilities/CHelpers.h"
#include "../Player/CPlayer.h"

#include "../Manager/CGameManager.h"
#include "../Level/CChapter1Level.h"
#include "../Level/CChapterIntroLevel.h"
#include "../Level/CChapterLevelBase.h"

ACEventBox::ACEventBox() 
{
	CHelpers::CreateComponent<USceneComponent>(this, &Scene, "Scene");
	CHelpers::CreateComponent<UBoxComponent>(this, &Box, "Box", Scene);
	CHelpers::CreateComponent<UTextRenderComponent>(this, &Text, "Text", Scene);
	
	Box->SetRelativeScale3D(FVector(3));
	Box->bHiddenInGame = false;

	// if (UCGameManager* pGameManager = Cast<UCGameManager>(UGameplayStatics::GetGameInstance(GetWorld())))
	// {
	// 	FString levelName = UGameplayStatics::GetCurrentLevelName(GetWorld());
	// 
	// 	if (levelName == "IntroLevel")
	// 	{
	// 		m_pLevelManager = Cast<ACChapterIntroLevel>(m_pLevelManager);
	// 	}
	// 	else if (levelName == "Chapter1Level")
	// 	{
	// 		// m_pLevelManager = Cast<ACChapter1Level>(m_pLevelManager);
	// 	}
	// }
}

void ACEventBox::BeginPlay()
{
	Super::BeginPlay();

	// OnActorBeginOverlap.AddDynamic(this, &ACEventBox::ActorBeginOverlap);
	// OnActorEndOverlap.AddDynamic(this, &ACEventBox::ActorEndOverlap);
}

void ACEventBox::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) 
{
	class ACPlayer* player = Cast<ACPlayer>(OtherActor);
	
	// if (nullptr != player) 
	// {
	// 	if (UCGameManager* pGameManager = Cast<UCGameManager>(UGameplayStatics::GetGameInstance(GetWorld()))) 
	// 	{
	// 		ACChapter1Level* pChapter = Cast<ACChapter1Level>(pGameManager->GetLevelManager()); //CChapterLevelBase
	// 		pChapter->StartDialogue();
	// 	}
	// }
}

void ACEventBox::OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) 
{

}


//void ACEventBox::ActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
//{
//	// ACPlayer* Player = Cast<ACPlayer>(OtherActor);
//	// if (Type == ETriggerType::GameEnterBooth) return;
//	// 
//	// UGameplayStatics::PlaySound2D(this, Sound_In);
//	// if (Player)
//	// {
//	// 	switch (Type)
//	// 	{
//	// 	case ETriggerType::ArcadeBooth:
//	// 	{
//	// 		if (!bExit)Player->OnArcadeMode();
//	// 		bExit = true;
//	// 	}break;
//	// 	case ETriggerType::ShootingBooth:
//	// 	{
//	// 		if (!bExit)Player->OnShootGameMode();
//	// 		bExit = true;
//	// 	}break;
//	// 	/*
//	// 	case ETriggerType::JumpingBooth:
//	// 	{
//	// 		if (!bExit)	UGameplayStatics::OpenLevel(OtherActor, ToLelvelName);//Player->OnJumpGameMode();
//	// 		bExit = true;
//	// 	}break;*/
//	// 	}
//	// }
//}
//
//
//
//void ACEventBox::ActorEndOverlap(AActor* OverlappedActor, AActor* OtherActor)
//{
//	// bExit = false;
//	// if (Sound_Out != NULL)
//	// 	UGameplayStatics::PlaySound2D(this, Sound_Out);
//}