// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CEndingWidgetInterface.generated.h"

/**
 * 
 */
UCLASS()
class THECAT_API UCEndingWidgetInterface : public UUserWidget
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
		virtual void Begin();

protected:
	UPROPERTY(BlueprintReadWrite)
		class UMediaPlayer* pMediaPlayer;
	UPROPERTY(BlueprintReadWrite)
		class UMediaSource* pMediaSource;
};
