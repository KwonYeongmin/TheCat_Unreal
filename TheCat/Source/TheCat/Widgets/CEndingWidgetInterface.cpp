#include "CEndingWidgetInterface.h"
#include "MediaPlayer.h"
#include "MediaSource.h"
#include "Components/Image.h"

void UCEndingWidgetInterface::Begin() 
{
     if (false == pMediaPlayer->OpenSource(pMediaSource))
         return;
 
     pMediaPlayer->SetLooping(true);
     UImage* videoImage = Cast<UImage>(GetWidgetFromName("EndingVideoPlayerImage"));
     videoImage->SetVisibility(ESlateVisibility::Visible);
}