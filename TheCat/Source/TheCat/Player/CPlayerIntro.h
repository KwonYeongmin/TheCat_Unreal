// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "CPlayerIntro.generated.h"

UCLASS()
class THECAT_API ACPlayerIntro : public APaperCharacter
{
	GENERATED_BODY()
public:

public:
	ACPlayerIntro();
	void SetInitialize(class ACChapterIntroLevel* _pIntroLevel);
protected:
	void BeginPlay();
protected:
	UPROPERTY(EditAnywhere)
		class UPaperFlipbook* m_pSHFlipbookAnimations[3];

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
		class UPaperFlipbookComponent* m_pPaperFlipbookComponent;

public:
	UFUNCTION(BlueprintCallable)
	bool SetPlayerAnimation(int32 _animIndex);

private:
	UFUNCTION(Category = "CallBack")
		void Private_FinshPlaying();
	UPROPERTY()
		int32 m_iAnimationIndex;
	UPROPERTY()
	class ACChapterIntroLevel* m_pIntroLevel;
};
