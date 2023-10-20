// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CWidgetInterfaceBase.h"
#include "Blueprint/UserWidget.h"
#include "CIntroWidgetInterface.generated.h"


 DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegate_EndDialogue_Intro, int32, DialogueSegmentIndex);
UCLASS()
class THECAT_API UCIntroWidgetInterface : public UCWidgetInterfaceBase
{
	GENERATED_BODY()
public:
		virtual void SetInitialize(class ACChapterIntroLevel* _pIntroLevel);
protected:
		virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime);
protected:

	UPROPERTY()
		class ACChapterIntroLevel* m_pIntroLevel;

public:
	bool IsSNSInteraction() const;
	FDelegate_EndDialogue_Intro OnEventEndDialogue;

protected:
	UPROPERTY(BlueprintReadWrite)
	class UWidgetAnimation* m_pAnimationRadioUI;
	UPROPERTY(BlueprintReadWrite)
	class UWidgetAnimation* m_pAnimationSNSWindowUI;

private:
	int32 m_iRadioStartIndex;
	int32 m_iRadioEndIndex;
	int32 m_iRadioDialCount;

	bool m_bIsSNSInteraction;

public:
	virtual bool StartDialogue() override;
	
	UFUNCTION()
	bool Start_SNSInteraction();
	UFUNCTION()
	bool Start_ConstellationInteraction();
	UFUNCTION()
	bool End_ConstellationInteraction();
	
	
private:
	UFUNCTION()
	void Private_ClickRadioDialArrowButton();
	//
	//FWidgetAnimationDynamicEvent StartDelegate;
	FWidgetAnimationDynamicEvent EndDelegate;
	UFUNCTION()
	bool Private_UpdateSNSInteraction();
	UFUNCTION()
	bool Private_ScrollSNSInteraction(int32 _iTimelineIndex, FString text);
	UFUNCTION()
	void Private_EndSNSInteraction();
	
	// 대화 관련 변수
protected:
	virtual void UpdateDialogue() override;
	virtual bool EndDialogue() override;
	UFUNCTION()
	void TestEnd_ConstellationInteraction();
	// UPROPERTY(EditAnywhere)
	// UMaterialInstanceDynamic* m_pObjectDialogueMaterialInstance;
	// UPROPERTY(EditAnywhere)
	// UTexture* m_ArrayDialogueObjectAnimations[2];
};
