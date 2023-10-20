// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CChapterSelectWidgetInterface.generated.h"

/**
 * 
 */
UCLASS()
class THECAT_API UCChapterSelectWidgetInterface : public UUserWidget
{
	GENERATED_BODY()
public:
	virtual void NativeConstruct() override;

public:
	UFUNCTION(BlueprintCallable)
		virtual void Begin();

private:
	UFUNCTION()
	void Private_MoveToIntroChapter();
	UFUNCTION()
	void Private_MoveToChapter1();
	UFUNCTION()
	void Private_MoveToChapter2();
	UFUNCTION()
		void Private_MoveToChapter3();
	UFUNCTION()
		void Private_MoveToEndingChapter();
};
