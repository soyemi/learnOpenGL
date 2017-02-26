#pragma once
#include "Include.h"

class RenderObject
{
public:
	RenderObject(glm::vec3 pos, glm::vec3 axis, GLfloat angle, glm::vec3 scale = glm::vec3(1.0f, 1.0f, 1.0f));
	~RenderObject();

	void SetPosition(glm::vec3 pos);
	void SetRotation(GLfloat angle, glm::vec3 axis);
	void SetScale(glm::vec3 scale);
	const glm::mat4 GetModelMatrix();
	void UpdateModelMatrix();

	MeshBase * pMesh;

protected:
	glm::vec3 m_pos;
	glm::vec3 m_axis;
	GLfloat m_angle;
	glm::vec3 m_scale;
	glm::mat4 m_matrix;
};

