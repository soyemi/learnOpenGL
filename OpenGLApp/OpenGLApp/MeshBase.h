#pragma once
#include "Include.h"

class MeshBase
{
public:
	MeshBase();
	~MeshBase();

	GLfloat * GetVertices();
	GLuint GetVerticesLen();
	GLuint* GetIndices();
	GLuint GetIndicesLen();

	void SetVertices(GLfloat* vert, GLuint len);
	void SetIndices(GLuint* indices, GLuint len);

	static MeshBase* GenCube();
protected:
	GLuint m_vertCount = 0;

	GLfloat * m_vertices;
	GLfloat * m_texcoord;
	GLfloat * m_color;
	GLfloat * m_other;
	GLuint m_vertivesLen = 3;
	GLuint m_texcoordLen = 0;
	GLuint m_colorLen = 0;
	GLuint m_otherLen = 0;

	GLuint *m_indices;
	GLuint m_indicesLen;
	
};