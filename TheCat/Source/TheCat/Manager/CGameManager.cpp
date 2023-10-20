#include "CGameManager.h"
#include "kismet/GameplayStatics.h"

#include "../Level/CTitleLevel.h"
#include "../Level/CChapterIntroLevel.h"
#include "../Level/CChapterSelectLevel.h"

UCGameManager::UCGameManager()
{
	m_pLevelManager = nullptr;

	m_pLevelManager = Cast<ACTitleLevel>(m_pLevelManager);
}

ALevelScriptActor* UCGameManager::GetLevelManager()
{
	// FString levelName = UGameplayStatics::GetCurrentLevelName(GetWorld());
	// 
	// if (levelName == "TitleLevel") 
	// { 
	// 	m_pLevelManager = Cast<ACTitleLevel>(m_pLevelManager);
	// }
	// else if (levelName == "ChapterSelectLevel") 
	// {
	// 	m_pLevelManager = Cast<ACChapterSelectLevel>(m_pLevelManager);
	// }
	// else if (levelName == "IntroLevel") 
	// {
	// 	// m_pLevelManager = Cast<ACChapterIntroLevel>(m_pLevelManager);
	// }

	return nullptr;
}
