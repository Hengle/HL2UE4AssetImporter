// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/UObjectAnnotation.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "IHL2Runtime.h"

#include "HL2Utils.generated.h"

/**
 * 
 */
UCLASS()
class HL2RUNTIME_API UHL2Utils : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category="HL2")
	static UTexture* TryResolveHL2Texture(const FString& hl2TexturePath, bool& outSuccess);

	UFUNCTION(BlueprintCallable, Category = "HL2")
	static UVMTMaterial* TryResolveHL2Material(const FString& hl2TexturePath, bool& outSuccess);

	UFUNCTION(BlueprintCallable, Category = "HL2")
	static UStaticMesh* TryResolveHL2StaticProp(const FString& hl2ModelPath, bool& outSuccess);

	UFUNCTION(BlueprintCallable, Category = "HL2")
	static USurfaceProp* TryResolveHL2SurfaceProp(const FName& surfaceProp, bool& outSuccess);

	UFUNCTION(BlueprintCallable, Category = "HL2")
	static UMaterial* TryResolveHL2Shader(const FString& hl2ShaderPath, EHL2BlendMode blendMode, bool& outSuccess);

	UFUNCTION(BlueprintCallable, meta=(WorldContext = "worldContextObject"), Category = "HL2")
	static void FindEntitiesByTargetName(UObject* worldContextObject, const FName targetName, TArray<ABaseEntity*>& outEntities);

	UFUNCTION(BlueprintCallable, meta=(WorldContext = "worldContextObject"), Category = "HL2")
	static TArray<ABaseEntity*> GetEntitiesByTargetName(UObject* worldContextObject, const FName targetName);

	UFUNCTION(BlueprintCallable, meta=(WorldContext = "worldContextObject"), Category = "HL2")
	static ABaseEntity* GetEntityByTargetName(UObject* worldContextObject, const FName targetName, bool& outSuccess, bool& outMultiple);
	
};