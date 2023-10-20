
#include "CChapterSelectWidgetInterface.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"

#include "kismet/GameplayStatics.h"

#include "../Manager/CGameManager.h"
#include "../Manager/CTextDataSubsystemManager.h"

void UCChapterSelectWidgetInterface::Begin()
{
	const UGameInstance* pGameInstance = Cast<UCGameManager>(UGameplayStatics::GetGameInstance(GetWorld()));
	UCTextDataSubsystemManager* pTextDataManager = pGameInstance->GetSubsystem<UCTextDataSubsystemManager>();

	if (nullptr == pTextDataManager)
		return;

	struct FUITextData* pUITextData = pTextDataManager->GetUITextData(0);

	if (nullptr != pUITextData)
	{
		if (UTextBlock* pCh1InfoText = Cast<UTextBlock>(GetWidgetFromName(TEXT("Text_Ch1Info"))))
		{
			pCh1InfoText->SetText(FText::FromString(pUITextData->Text));
		}

		if (UTextBlock* pCh2InfoText = Cast<UTextBlock>(GetWidgetFromName(TEXT("Text_Ch2Info"))))
		{
			pCh2InfoText->SetText(FText::FromString(pUITextData->Text));
		}

		if (UTextBlock* pCh3InfoText = Cast<UTextBlock>(GetWidgetFromName(TEXT("Text_Ch3Info"))))
		{
			pCh3InfoText->SetText(FText::FromString(pUITextData->Text));
		}
	}

}

void UCChapterSelectWidgetInterface::NativeConstruct()
{
	Super::NativeConstruct();

	if (class UButton* pButtonTitle = Cast<UButton>(GetWidgetFromName(TEXT("IntroButton"))))
	{
		pButtonTitle->OnClicked.AddDynamic(this, &UCChapterSelectWidgetInterface::Private_MoveToIntroChapter);
	}

	if (class UButton* pButtonTitle = Cast<UButton>(GetWidgetFromName(TEXT("Chapter1Button"))))
	{
		pButtonTitle->OnClicked.AddDynamic(this, &UCChapterSelectWidgetInterface::Private_MoveToChapter1);
	}

	if (class UButton* pButtonTitle = Cast<UButton>(GetWidgetFromName(TEXT("Chapter2Button"))))
	{
		pButtonTitle->OnClicked.AddDynamic(this, &UCChapterSelectWidgetInterface::Private_MoveToChapter2);
	}

	if (class UButton* pButtonTitle = Cast<UButton>(GetWidgetFromName(TEXT("Chapter3Button"))))
	{
		pButtonTitle->OnClicked.AddDynamic(this, &UCChapterSelectWidgetInterface::Private_MoveToChapter3);
	}

	if (class UButton* pButtonTitle = Cast<UButton>(GetWidgetFromName(TEXT("EndingButton"))))
	{
		pButtonTitle->OnClicked.AddDynamic(this, &UCChapterSelectWidgetInterface::Private_MoveToEndingChapter);
	}
}

void UCChapterSelectWidgetInterface::Private_MoveToIntroChapter()
{
	FName levelName = "ChapterIntroLevel";
	UGameplayStatics::OpenLevel(this, levelName);
}

void UCChapterSelectWidgetInterface::Private_MoveToChapter1()
{
	FName levelName = "Chapter1Level";
	UGameplayStatics::OpenLevel(this, levelName);
}

void UCChapterSelectWidgetInterface::Private_MoveToChapter2()
{
	FName levelName = "Chapter2Level";
	UGameplayStatics::OpenLevel(this, levelName);
}

void UCChapterSelectWidgetInterface::Private_MoveToChapter3()
{
	FName levelName = "Chapter3Level";
	UGameplayStatics::OpenLevel(this, levelName);
}

void UCChapterSelectWidgetInterface::Private_MoveToEndingChapter()
{
	FName levelName = "ChapterEndingLevel";
	UGameplayStatics::OpenLevel(this, levelName);
}
