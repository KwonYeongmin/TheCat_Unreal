// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CTextTableBase.generated.h"


UCLASS()
class THECAT_API ACTextTableBase : public AActor
{
	GENERATED_BODY()
	
public:	
	ACTextTableBase();

protected:
	virtual void BeginPlay() override;
};
