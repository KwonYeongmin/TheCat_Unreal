// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "CGameManager.generated.h"

/**
 * 
 */
UCLASS()
class THECAT_API UCGameManager : public UGameInstance
{
	GENERATED_BODY()
	
public:
	UCGameManager();
	UFUNCTION()
	ALevelScriptActor* GetLevelManager();

private:
	UPROPERTY()
		ALevelScriptActor* m_pLevelManager;
};
