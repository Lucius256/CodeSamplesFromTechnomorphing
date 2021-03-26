// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ProceduralMeshComponent.h"
#include "Geometry_Utilities.h"
#include "PhysicsDetailsArrayComponent.h"
#include "DetailMeshVisualizer.generated.h"


UCLASS(ClassGroup = CyberCraft, editinlinenew, meta = (BlueprintSpawnableComponent))
class TECHNOMORPHING_API UDetailMeshVisualizer : public UProceduralMeshComponent
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UMaterialInstance* visualMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector2D uvScale;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray <FVector> vertexes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray <FVector> norms;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray <int32> tris;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray <FVector2D> UVs;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray <FColor> cols;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray <FProcMeshTangent> tans;

	UFUNCTION(BlueprintCallable)
	void SplineTriangle(const float height, const FVector2D uv0, const bool borders, const bool twoSided, const TArray <FVector>& parameters);

	UFUNCTION(BlueprintCallable)
	void SplineQuad(const float height, const FVector2D uv0, const bool borders, const bool twoSided, const TArray <FVector> & parameters);

	UFUNCTION(BlueprintCallable)
	void InsertSplineQuad(const int32 beginVertexNumber, const int32 endVertexNumber, const int32 beginTrianglesNumber, const int32 endTrianglesNumber, const float height, const FVector2D uv0, const bool borders, const bool twoSided, const TArray <FVector>& parameters, int32& maxVertexNumber, int32& maxTrianglesNumber);

	UFUNCTION(BlueprintCallable)
	void InsertSplineTriangle (const int32 beginVertexNumber, const int32 endVertexNumber, const int32 beginTrianglesNumber, const int32 endTrianglesNumber, const float height, const FVector2D uv0, const bool borders, const bool twoSided, const TArray <FVector>& parameters, int32& maxVertexNumber, int32& maxTrianglesNumber);

	UFUNCTION(BlueprintCallable)
		void RemoveSegment(const int32 beginVertexNumber, const int32 endVertexNumber, const int32 beginTrianglesNumber, const int32 endTrianglesNumber);

	UFUNCTION(BlueprintCallable)
	void AddSplineQuad(const float height, const FVector2D uv0, const bool borders, const bool twoSided, const TArray <FVector>& parameters, int32& maxVertexNumber, int32& maxTrianglesNumber);

	UFUNCTION(BlueprintCallable)
	void AddSplineTriangle(const float height, const FVector2D uv0, const bool borders, const bool twoSided, const TArray <FVector>& parameters, int32& maxVertexNumber, int32& maxTrianglesNumber);

	UFUNCTION(BlueprintCallable)
	void ClearMesh();

	UFUNCTION(BlueprintCallable)
	void BuildMesh();

};
