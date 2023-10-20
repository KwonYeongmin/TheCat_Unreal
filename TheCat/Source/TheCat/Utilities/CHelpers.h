#pragma once
#include "CoreMinimal.h"
#include "UObject/ConstructorHelpers.h"

class THECAT_API CHelpers
{
public:
	/*
	template<typename T> static bool GetBluePrintVariable(T** outObject, FString VariableName)
	{
		// ������ �̸����� �˻��Ͽ� UProperty �� �����´�.
		UProperty* Prop = GetClass()->FindPropertyByName(*VariableName);

		// ���� Ŭ������ ������ �´��� ��
		if (Prop->GetClass() == UObjectProperty::StaticClass())
		{
			UObjectProperty* objectProp = Cast<UObjectProperty>(Prop);

			if (objectProp->PropertyClass = T::StaticClass()) 
			{
				UObject* obj = objectProp->GetObjectPropertyValue_InContainer(this);
				T* variable = Cast<T>(obj);
				if (IsValid(variable))
				{
					return true;
				}
			}

			// if (objectProp->PropertyClass == ���ϴº����� Ŭ��������::StaticClass())
			// ���� ����
			// if (objectProp->PropertyClass == UWidgetAnimation::StaticClass())
			// {
			// 	UObject* obj = objectProp->GetObjectPropertyValue_InContainer(this);
			// 
			// 	UWidgetAnimation* WidgetAnim = Cast<UWidgetAnimation>(obj);
			// 	if (IsValid(WidgetAnim))
			// 	{
			// 		// ���� ��
			// 	}
			// }
		}

		return false;
	}*/


// https://developstudy.tistory.com/46
	/*    Object Asset�� �޽��ϴ�.
*    ������ Ÿ�ӿ��� �۵��մϴ�.
*    RETURN_POINTER : ���� ������
*    CLASS_TYPE : ���� ������Ʈ�� Ŭ����
*    PATH : ��� (TEXT�� ������ �ʽ��ϴ�.)*/
#define GetObjectAsset(RETURN_POINTER, CLASS_TYPE, PATH)\
static ConstructorHelpers::FObjectFinder<CLASS_TYPE> __##RETURN_POINTER(TEXT(PATH));\
if (__##RETURN_POINTER.Succeeded()) {\
    RETURN_POINTER = __##RETURN_POINTER.Object;\
}\
else RETURN_POINTER = nullptr;\
CHECK(RETURN_POINTER)


/*    Class Asset�� �޽��ϴ�.
*    ������ Ÿ�ӿ��� �۵��մϴ�.
*    RETURN_POINTER : ���� ������
*    CLASS_TYPE : ���� Ŭ���� Ÿ��
*    PATH : ��� (TEXT�� ������ �ʽ��ϴ�.)*/

#define GetClassAsset(RETURN_POINTER, CLASS_TYPE, PATH)\
static ConstructorHelpers::FClassFinder<CLASS_TYPE> __##RETURN_POINTER(TEXT(PATH));\
if (__##RETURN_POINTER.Succeeded()) {\
    RETURN_POINTER = __##RETURN_POINTER.Class;\
}\
else RETURN_POINTER = nullptr;\
CHECK(RETURN_POINTER)
	/*
	* 
	// �����ڿ����� ���
	GetClassAsset(CS_PsychicForce, UCameraShake, "/Game/Blueprint/CameraShake/Esper/CS_01_PsychicForce.CS_01_PsychicForce_C");
	*/

	template<typename T> static void GetAsset(T** outObject, FString inPath)
	{
		ConstructorHelpers::FObjectFinder<T> asset(*inPath);
		verifyf(asset.Succeeded(), L"asset.Succeeded()");
		*outObject = asset.Object;
	}

	template<typename T> static void GetAssetDynamic(T** outObject, FString inPath)
	{
		T* obj = Cast<T>(StaticLoadObject(T::StaticClass(), NULL, *inPath));
		verifyf(!!obj, L"!!asset");
		*outObject = obj;
	}

	template<typename T> static void CreateComponent(AActor* inActor, T** inComponent
		, FName inName, USceneComponent* inParent = NULL)
	{
		*inComponent = inActor->CreateDefaultSubobject<T>(inName);
		if (!!inParent)
		{
			(*inComponent)->SetupAttachment(inParent);
			return;
		}
		inActor->SetRootComponent(*inComponent);
	}

	template<typename T> static void CreateActorComponent(AActor* inActor, T** inComponent, FName inName)
	{
		*inComponent = inActor->CreateDefaultSubobject<T>(inName);
	}

	template<typename T> static void GetClass(TSubclassOf<T>* outClass, FString InPath)
	{
		ConstructorHelpers::FClassFinder<T> asset(*InPath);
		verifyf(asset.Succeeded(), L"(asset.Succeeded()");
		*outClass = asset.Class;
	}

	template<typename T> static void FindActor(class UWorld* InWorld, TArray<T*>& OutActors)
	{
		OutActors.Empty();

		TArray<AActor*> actors;
		UGameplayStatics::GetAllActorsOfClass(InWorld, T::StaticClass(), actors);

		for (AActor* actor : actors)
			OutActors.Add(Cast<T>(actor));
	}

	template<typename T> static T* GetComponent(AActor* InActor)
	{
		return Cast<T>(InActor->GetComponentByClass(T::StaticClass()));
	}

};