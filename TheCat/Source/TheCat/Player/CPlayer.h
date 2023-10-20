#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "CPlayer.generated.h"


UCLASS()
class THECAT_API ACPlayer : public APaperCharacter
{
	GENERATED_BODY()
public:
	ACPlayer();
	bool SetInitialize(class ACChapter1Level* _pChapter1Level);
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void Tick(float DeltaSeconds);
protected:
	class ACChapter1Level* m_pChapter1Level;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UPaperFlipbookComponent* m_pPaperFlipbookComponent;
	int32 m_iAnimationIndex;

protected:
	UPROPERTY(EditAnywhere)
	class UPaperFlipbook* m_pSHFlipbookAnimations[2];
	// UPROPERTY(EditAnywhere)
	// class UCharacterMovementComponent* m_pCharacterMovementComponent;

public:
	UFUNCTION(BlueprintCallable)
	bool SetPlayerAnimation(int32 _animIndex);
	UFUNCTION(BlueprintCallable)
	bool StartDialogue();

// private:
// 	void OnMoveHorizontal(float InAix);
// 	void Move(float DeltaTime);
// 
// 	FVector MoveDirection;
// 	float CurrenVelocity;
};
