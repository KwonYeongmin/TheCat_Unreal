// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Engine/DataTable.h"
#include "CTextDataSubsystemManager.generated.h"

// Key,Chapter,Dial,Index,Name,Content,SHAnim,CatAnim
USTRUCT(BlueprintType)
struct FDialogueTextData : public FTableRowBase
{
	GENERATED_BODY()
public:
	FDialogueTextData() : Chapter(-2), Dial(-1), Index(-1), Name(""), Content(""), SHAnim(-1), CatAnim(-1) { }
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	int32 Chapter;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	int32 Dial;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	int32 Index;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	FString Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	FString Content;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	int32 SHAnim;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	int32 CatAnim;
};

USTRUCT(BlueprintType)
struct FUITextData : public FTableRowBase
{
	GENERATED_BODY()
public:
	FUITextData() : Chapter(-2), Index(-1), Text("") { }
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 Chapter;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 Index;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		FString Text;
};

USTRUCT(BlueprintType)
struct FIllustrateTextData : public FTableRowBase
{
	GENERATED_BODY()
public:
	FIllustrateTextData() : Chapter(-2), Index(-1), Name(""), Text("") { }
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 Chapter;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 Index;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		FString Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		FString Text;
};

UCLASS()
class THECAT_API UCTextDataSubsystemManager : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	UCTextDataSubsystemManager();
	struct FIllustrateTextData* GetIllustrateTextData(int32 index) const;
	struct FUITextData* GetUITextData(int32 index) const;
	struct FDialogueTextData* GetDialogueTextData(int32 index) const;

private:
	UPROPERTY()
		class UDataTable* m_pIllustrateTextData;
	UPROPERTY()
		class UDataTable* m_pUITextData;
		UPROPERTY()
		class UDataTable* m_pDialogueTextData;
};
