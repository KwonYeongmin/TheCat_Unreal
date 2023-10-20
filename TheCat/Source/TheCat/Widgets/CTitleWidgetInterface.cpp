#include "CTitleWidgetInterface.h"
#include "MediaPlayer.h"
#include "MediaSource.h"
#include "Components/Image.h"
#include "Components/Button.h"

#include "kismet/GameplayStatics.h"

void UCTitleWidgetInterface::NativeConstruct() 
{
    Super::NativeConstruct();
    
   if (class UButton*  pButtonTitle = Cast<UButton>(GetWidgetFromName(TEXT("ButtonTitle"))))
   {
       pButtonTitle->OnClicked.AddDynamic(this, &UCTitleWidgetInterface::Private_MoveToChapterSelectLevel);
   }
}

void UCTitleWidgetInterface::Begin()
{
   if (false == pMediaPlayer->OpenSource(pMediaSource))
       return;
   
   pMediaPlayer->SetLooping(true);
   UImage* videoImage = Cast<UImage>(GetWidgetFromName("TitleVideoPlayerImage"));
   videoImage->SetVisibility(ESlateVisibility::Visible);
}

void UCTitleWidgetInterface::Private_MoveToChapterSelectLevel()
{
    FName levelName = "ChapterSelectLevel";
    UGameplayStatics::OpenLevel(this, levelName);
}

