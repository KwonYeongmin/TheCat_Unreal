// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CTitleWidgetInterface.generated.h"

/**
 * 
 */
UCLASS()
class THECAT_API UCTitleWidgetInterface : public UUserWidget
{
	GENERATED_BODY()
public:
	virtual void NativeConstruct() override;

public:
	virtual void Begin();

protected:
	UPROPERTY(BlueprintReadWrite)
	class UMediaPlayer*		pMediaPlayer;
	UPROPERTY(BlueprintReadWrite)
	class UMediaSource*		pMediaSource;
	// UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	// class UButton* pButtonTitle;

private:
	UFUNCTION()
	void Private_MoveToChapterSelectLevel();
};
