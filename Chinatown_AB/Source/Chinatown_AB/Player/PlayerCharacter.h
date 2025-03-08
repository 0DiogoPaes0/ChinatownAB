// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "PlayerCharacter.generated.h"

class UInputMappingContext;
class UInputAction;


UCLASS()
class CHINATOWN_AB_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

	

protected:
	//Input Mapping context and Actions
	UPROPERTY(EditAnywhere, Category = "Input")
	UInputMappingContext* PlayerCharacterContext;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* LookAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* JumpAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* SprintAction;



public:
	// Sets default values for this character's properties
	APlayerCharacter();
	virtual void Jump() override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	//Movement, Jump, sprinting, crouching values
	void LookInput(const FInputActionValue& Value);
	void MoveInput(const FInputActionValue& Value);

	void StartSprint();
	void EndSprint();

	UPROPERTY(EditAnywhere, Category = "Movement")
	float WalkSpeed;
	UPROPERTY(EditAnywhere, Category = "Movement")
	float SprintSpeed;

	bool IsSprinting;

	void UpdateStamina();

	//Stamina Variables
	bool HasStamina;

	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category = "Stamina")
	float MaxStamina;
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category = "Stamina")
	float CurrentStamina;
	UPROPERTY(EditAnywhere, Category = "Stamina")
	float StaminaDrainAmount;
	UPROPERTY(EditAnywhere, Category = "Stamina")
	float StaminaRefillAmount;
	UPROPERTY(EditAnywhere, Category = "Stamina")
	float MaxStaminaRefillDelay;

	float CurrentStaminaRefillDelay;

};
