#include "RenderObject.h"


RenderObject::RenderObject(glm::vec3 pos, glm::vec3 axis, GLfloat angle, glm::vec3 scale)
{
	SetPosition(pos);
	SetRotation(angle, axis);
	SetScale(scale);
	UpdateModelMatrix();
}


RenderObject::~RenderObject()
{
}

void RenderObject::SetPosition(glm::vec3 pos)
{
	m_pos = pos;
}

void RenderObject::SetRotation(GLfloat angle, glm::vec3 axis)
{
	m_axis = axis;
	m_angle = angle;
}

void RenderObject::SetScale(glm::vec3 scale)
{
	m_scale = scale;
}

void RenderObject::UpdateModelMatrix()
{
	m_matrix = glm::mat4();
	glm::translate(m_matrix,m_pos);
	glm::rotate(m_matrix, m_angle, m_axis);
	glm::scale(m_matrix, m_scale);
}

const glm::mat4 RenderObject::GetModelMatrix()
{
	return m_matrix;
}
