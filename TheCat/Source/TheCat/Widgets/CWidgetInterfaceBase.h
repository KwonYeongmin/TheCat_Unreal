// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CWidgetInterfaceBase.generated.h"

USTRUCT()
struct FDialogueSegment
{
	GENERATED_BODY()
	FDialogueSegment() :iStartIndex(-1), iEndIndex(-1) {  }
	FDialogueSegment(int32 _iStartIndex, int32 _iEndIndex) :iStartIndex(_iStartIndex), iEndIndex(_iEndIndex) {  }
	int32 iStartIndex;
	int32 iEndIndex;
};

UCLASS()
class THECAT_API UCWidgetInterfaceBase : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION()
	virtual bool StartDialogue();
protected:
	UFUNCTION()
	void SetInitialize();


protected:
	UPROPERTY(BlueprintReadWrite)
	class UWidgetAnimation* m_pAnimationPlayerDialogue;
	UPROPERTY(BlueprintReadWrite)
	class UWidgetAnimation* m_pAnimationCharacterDialogue;
	UPROPERTY(BlueprintReadWrite)
	class UWidgetAnimation* m_pAnimationObjectDialogue;

	UPROPERTY()
	TArray<FDialogueSegment> m_ArrayDialogueSegment;

	// 대화창 MaterialInstance
	UPROPERTY(EditAnywhere)
	UMaterialInstanceDynamic* m_pPlayerDialogueMaterialInstance;
	// 대화창 MaterialInstance의 매개변수로 들어갈 Texture
	UPROPERTY(EditAnywhere)
	TArray<UTexture*> m_ArrayDialoguePlayerAnimations;
	

	UPROPERTY(EditAnywhere)
	UMaterialInstanceDynamic* m_pCharacterDialogueMaterialInstance;
	UPROPERTY(EditAnywhere)
	TArray<UTexture*> m_ArrayDialogueCharacterAnimations;

	bool m_bDialogueStart;

	int32 m_iDialogueSegmentIndex;
	int32 m_iDialogueIndex;

	FLinearColor m_TextColor_Player;
	FLinearColor m_TextColor_Character;

protected:
	UFUNCTION()
	virtual bool EndDialogue();
	UFUNCTION()
	virtual void UpdateDialogue();
};
