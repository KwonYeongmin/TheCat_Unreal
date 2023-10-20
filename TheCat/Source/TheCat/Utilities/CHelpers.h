#pragma once
#include "CoreMinimal.h"
#include "UObject/ConstructorHelpers.h"

class THECAT_API CHelpers
{
public:
	/*
	template<typename T> static bool GetBluePrintVariable(T** outObject, FString VariableName)
	{
		// 변수의 이름으로 검색하여 UProperty 를 가져온다.
		UProperty* Prop = GetClass()->FindPropertyByName(*VariableName);

		// 현재 클래스의 변수가 맞는지 비교
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

			// if (objectProp->PropertyClass == 원하는변수의 클래스형태::StaticClass())
			// 예제 시작
			// if (objectProp->PropertyClass == UWidgetAnimation::StaticClass())
			// {
			// 	UObject* obj = objectProp->GetObjectPropertyValue_InContainer(this);
			// 
			// 	UWidgetAnimation* WidgetAnim = Cast<UWidgetAnimation>(obj);
			// 	if (IsValid(WidgetAnim))
			// 	{
			// 		// 예제 끝
			// 	}
			// }
		}

		return false;
	}*/


// https://developstudy.tistory.com/46
	/*    Object Asset을 받습니다.
*    생성자 타임에만 작동합니다.
*    RETURN_POINTER : 받을 포인터
*    CLASS_TYPE : 받을 오브젝트의 클래스
*    PATH : 경로 (TEXT를 붙이지 않습니다.)*/
#define GetObjectAsset(RETURN_POINTER, CLASS_TYPE, PATH)\
static ConstructorHelpers::FObjectFinder<CLASS_TYPE> __##RETURN_POINTER(TEXT(PATH));\
if (__##RETURN_POINTER.Succeeded()) {\
    RETURN_POINTER = __##RETURN_POINTER.Object;\
}\
else RETURN_POINTER = nullptr;\
CHECK(RETURN_POINTER)


/*    Class Asset을 받습니다.
*    생성자 타임에만 작동합니다.
*    RETURN_POINTER : 받을 포인터
*    CLASS_TYPE : 받을 클래스 타입
*    PATH : 경로 (TEXT를 붙이지 않습니다.)*/

#define GetClassAsset(RETURN_POINTER, CLASS_TYPE, PATH)\
static ConstructorHelpers::FClassFinder<CLASS_TYPE> __##RETURN_POINTER(TEXT(PATH));\
if (__##RETURN_POINTER.Succeeded()) {\
    RETURN_POINTER = __##RETURN_POINTER.Class;\
}\
else RETURN_POINTER = nullptr;\
CHECK(RETURN_POINTER)
	/*
	* 
	// 생성자에서만 사용
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