// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CWidgetInterfaceBase.h"
#include "CChapter1WidgetInterface.generated.h"
/**
 * 
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegate_EndDialogue_Chapter1, int32, DialogueSegmentIndex);
UCLASS()
class THECAT_API UCChapter1WidgetInterface : public UCWidgetInterfaceBase
{
	GENERATED_BODY()
public:
	virtual void SetInitialize(class ACChapter1Level* _pChapter1Level);
protected:
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime);
protected:
	UPROPERTY()
	class ACChapter1Level* m_pChapter1Level;

public:
	FDelegate_EndDialogue_Chapter1 OnEventEndDialogue;

public:
	virtual bool StartDialogue() override;

protected:
	virtual void UpdateDialogue() override;
	virtual bool EndDialogue() override;
	/*
	Widget_UIInformation
	*/
	
};
