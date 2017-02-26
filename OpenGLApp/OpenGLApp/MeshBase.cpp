#pragma once
#include "Include.h"

MeshBase::MeshBase()
{
}


MeshBase::~MeshBase()
{
	delete[] m_vertices;
	delete[] m_texcoord;
	delete[] m_color;
	delete[] m_other;
	delete[] m_indices;
}

GLfloat * MeshBase::GetVertices()
{
	return m_vertices;
}

GLuint MeshBase::GetVerticesLen()
{
	return m_vertivesLen;
}

GLuint * MeshBase::GetIndices()
{
	return m_indices;
}

GLuint MeshBase::GetIndicesLen()
{
	return m_indicesLen;
}

void MeshBase::SetVertices(GLfloat * vert, GLuint len)
{
	m_vertices = vert;
	m_vertivesLen = len;
}

void MeshBase::SetIndices(GLuint * indices, GLuint len)
{
	m_indices = indices;
	m_indicesLen = len;
}

MeshBase * MeshBase::GenCube()
{
	return nullptr;
}
