// Fill out your copyright notice in the Description page of Project Settings.


#include "DetailMeshVisualizer.h"
#include "Geometry_Utilities.h"
#include "DrawDebugHelpers.h"

void UDetailMeshVisualizer::AddSplineTriangle (const float height, const FVector2D uv0, const bool borders, const bool twoSided, const TArray <FVector>& parameters, int32& maxVertexNumber, int32& maxTrianglesNumber) {
	TArray <FVector> vertices;
	TArray <FVector> normals;
	TArray <int32> triangles;
	TArray <FVector2D> uvs;
	TArray <FProcMeshTangent> tangents;
	TArray <FColor> vertexColors;

	Geometry_Utilities::MakeSplineTriangle(uvScale, height, uv0, borders, twoSided, parameters, vertices, triangles, normals, vertexColors, uvs, tangents);
	int32 maxVertex = vertexes.Num();
	vertexes += vertices;
	norms += normals;
	//tris.Reserve()
	for (int32 triangleNumber = 0; triangleNumber < triangles.Num(); triangleNumber++) {
		tris.Add(triangles[triangleNumber] + maxVertex);
	}

	//tris += triangles;
	UVs += uvs;
	cols += vertexColors;
	tans += tangents;

	maxVertexNumber = vertexes.Num();
	maxTrianglesNumber = tris.Num();

	//this->CreateMeshSection(0, vertexes, tris, norms, UVs, cols, tans, false);
	//this->SetMaterial(0, visualMaterial);

}

void UDetailMeshVisualizer::AddSplineQuad(const float height, const FVector2D uv0, const bool borders, const bool twoSided, const TArray <FVector>& parameters, int32& maxVertexNumber, int32& maxTrianglesNumber) {

	


	TArray <FVector> vertices;
	TArray <FVector> normals;
	TArray <int32> triangles;
	TArray <FVector2D> uvs;
	TArray <FProcMeshTangent> tangents;
	TArray <FColor> vertexColors;
	

	Geometry_Utilities::MakeSplineQuad(uvScale, height, uv0, borders, twoSided, parameters, vertices, triangles, normals, vertexColors, uvs, tangents);
	int32 maxVertex = vertexes.Num();
	vertexes += vertices;
	norms += normals;
	//tris.Reserve()
	for (int32 triangleNumber = 0; triangleNumber < triangles.Num(); triangleNumber++) {
		tris.Add(triangles[triangleNumber] + maxVertex);
	}

	//tris += triangles;
	UVs += uvs;
	cols += vertexColors;
	tans += tangents;

	maxVertexNumber = vertexes.Num();
	maxTrianglesNumber = tris.Num();

}

void UDetailMeshVisualizer::InsertSplineTriangle (const int32 beginVertexNumber, const int32 endVertexNumber, const int32 beginTrianglesNumber, const int32 endTrianglesNumber, const float height, const FVector2D uv0, const bool borders, const bool twoSided, const TArray <FVector>& parameters, int32& maxVertexNumber, int32& maxTrianglesNumber) {
	TArray <FVector> vertices;
	TArray <FVector> normals;
	TArray <int32> triangles;
	TArray <FVector2D> uvs;
	TArray <FProcMeshTangent> tangents;
	TArray <FColor> vertexColors;
	Geometry_Utilities::MakeSplineTriangle(uvScale, height, uv0, borders, twoSided, parameters, vertices, triangles, normals, vertexColors, uvs, tangents);
	if (vertices.Num() != endVertexNumber - beginVertexNumber) {
		int32 delta = endVertexNumber - beginVertexNumber - vertices.Num();

		vertexes.RemoveAt (beginVertexNumber, endVertexNumber - beginVertexNumber);
		norms.RemoveAt (beginVertexNumber, endVertexNumber - beginVertexNumber);
		UVs.RemoveAt (beginVertexNumber, endVertexNumber - beginVertexNumber);
		cols.RemoveAt (beginVertexNumber, endVertexNumber - beginVertexNumber);
		tans.RemoveAt (beginVertexNumber, endVertexNumber - beginVertexNumber);

		tris.RemoveAt (beginTrianglesNumber, beginTrianglesNumber - endTrianglesNumber);

		vertexes.Insert (vertices, beginVertexNumber);
		norms.Insert (normals, beginVertexNumber);
		UVs.Insert (uvs, beginVertexNumber);
		cols.Insert (vertexColors, beginVertexNumber);
		tans.Insert (tangents, beginVertexNumber);

		tris.Insert (triangles, beginTrianglesNumber);
		for (int32 triangle_number = beginTrianglesNumber + triangles.Num(); triangle_number < tris.Num(); triangle_number++) {
			tris[triangle_number] += delta;
		}
	}
	else {
		int32 vertice_number = 0;
		for (int32 vertex_number = beginVertexNumber; vertex_number < endVertexNumber; vertex_number++) {
			vertexes [vertex_number] = vertices     [vertice_number];
			norms    [vertex_number] = normals      [vertice_number];
			UVs      [vertex_number] = uvs          [vertice_number];
			cols     [vertex_number] = vertexColors [vertice_number];
			tans     [vertex_number] = tangents     [vertice_number];
		}
	}
	
	maxVertexNumber = beginVertexNumber + vertices.Num();
	maxTrianglesNumber = beginTrianglesNumber + triangles.Num();


}

void UDetailMeshVisualizer::InsertSplineQuad (const int32 beginVertexNumber, const int32 endVertexNumber, const int32 beginTrianglesNumber, const int32 endTrianglesNumber, const float height, const FVector2D uv0, const bool borders, const bool twoSided, const TArray <FVector>& parameters, int32& maxVertexNumber, int32& maxTrianglesNumber){
	TArray <FVector> vertices;
	TArray <FVector> normals;
	TArray <int32> triangles;
	TArray <FVector2D> uvs;
	TArray <FProcMeshTangent> tangents;
	TArray <FColor> vertexColors;
	Geometry_Utilities::MakeSplineQuad(uvScale, height, uv0, borders, twoSided, parameters, vertices, triangles, normals, vertexColors, uvs, tangents);
//InsertSplineQuad(const float height, const FVector2D uv0, const bool borders, const bool twoSided, const TArray <FVector>& parameters) {
	if (vertices.Num() != endVertexNumber - beginVertexNumber) {
		int32 delta = endVertexNumber - beginVertexNumber - vertices.Num();
		vertexes.RemoveAt(beginVertexNumber, endVertexNumber - beginVertexNumber);
		norms.RemoveAt(beginVertexNumber, endVertexNumber - beginVertexNumber);
		UVs.RemoveAt(beginVertexNumber, endVertexNumber - beginVertexNumber);
		cols.RemoveAt(beginVertexNumber, endVertexNumber - beginVertexNumber);
		tans.RemoveAt(beginVertexNumber, endVertexNumber - beginVertexNumber);

		tris.RemoveAt(beginTrianglesNumber, beginTrianglesNumber - endTrianglesNumber);

		vertexes.Insert(vertices, beginVertexNumber);
		norms.Insert(normals, beginVertexNumber);
		UVs.Insert(uvs, beginVertexNumber);
		cols.Insert(vertexColors, beginVertexNumber);
		tans.Insert(tangents, beginVertexNumber);

		tris.Insert(triangles, beginTrianglesNumber);

		for (int32 triangle_number = beginTrianglesNumber + triangles.Num(); triangle_number < tris.Num(); triangle_number++) {
			tris[triangle_number] += delta;
		}

	}
	else {
		int32 vertice_number = 0;
		for (int32 vertex_number = beginVertexNumber; vertex_number < endVertexNumber; vertex_number++) {
			vertexes[vertex_number] = vertices[vertice_number];
			norms[vertex_number] = normals[vertice_number];
			UVs[vertex_number] = uvs[vertice_number];
			cols[vertex_number] = vertexColors[vertice_number];
			tans[vertex_number] = tangents[vertice_number];
		}
	}

	maxVertexNumber = beginVertexNumber + vertices.Num();
	maxTrianglesNumber = beginTrianglesNumber + triangles.Num();

}

void UDetailMeshVisualizer::RemoveSegment (const int32 beginVertexNumber, const int32 endVertexNumber, const int32 beginTrianglesNumber, const int32 endTrianglesNumber) {
	vertexes.RemoveAt (beginVertexNumber, endVertexNumber);
	norms.RemoveAt (beginVertexNumber, endVertexNumber);
	UVs.RemoveAt (beginVertexNumber, endVertexNumber);
	cols.RemoveAt (beginVertexNumber, endVertexNumber);
	tans.RemoveAt (beginVertexNumber, endVertexNumber);

	tris.RemoveAt (beginTrianglesNumber, endTrianglesNumber);
}



void UDetailMeshVisualizer::SplineTriangle(const float height, const FVector2D uv0, const bool borders, const bool twoSided, const TArray <FVector>& parameters) {

	TArray <FVector> vertices;
	TArray <FVector> normals;
	TArray <int32> triangles;
	TArray <FVector2D> uvs;
	TArray <FProcMeshTangent> tangents;
	TArray <FColor> vertexColors;

	Geometry_Utilities::MakeSplineTriangle (uvScale, height, uv0, borders, twoSided, parameters, vertices, triangles, normals, vertexColors, uvs, tangents);

	this->CreateMeshSection(0, vertices, triangles, normals, uvs, vertexColors, tangents, false);
	this->SetMaterial(0, visualMaterial);

}


void UDetailMeshVisualizer::SplineQuad(const float height, const FVector2D uv0, const bool borders, const bool twoSided, const TArray <FVector>& parameters) {
	TArray <FVector> vertices;
	TArray <FVector> normals;
	TArray <int32> triangles;
	TArray <FVector2D> uvs;
	TArray <FProcMeshTangent> tangents;
	TArray <FColor> vertexColors;

	Geometry_Utilities::MakeSplineQuad (uvScale, height, uv0, borders, twoSided, parameters, vertices, triangles, normals, vertexColors, uvs, tangents);

	this->CreateMeshSection(0, vertices, triangles, normals, uvs, vertexColors, tangents, false);
	this->SetMaterial(0, visualMaterial);

}

void UDetailMeshVisualizer::ClearMesh() {
	
	vertexes.Empty();
	norms.Empty();
	tris.Empty();
	UVs.Empty();
	cols.Empty();
	tans.Empty();
}

void UDetailMeshVisualizer::BuildMesh() {
	this->ClearMeshSection(0);
	this->CreateMeshSection(0, vertexes, tris, norms, UVs, cols, tans, false);
	this->SetMaterial(0, visualMaterial);
}