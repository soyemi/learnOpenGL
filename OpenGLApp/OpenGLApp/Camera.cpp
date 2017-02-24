#include "Camera.h"

Camera::~Camera()
{
}

glm::mat4 Camera::GetViewMatrix()
{
	return glm::lookAt(this->Position, this->Position + this->Front, this->WorldUp);
}

void Camera::ProcessKeyboard(Camera_Movement direction, GLfloat deltaTime)
{
	GLfloat velocity = this->MovementSpeed * deltaTime;
	if (direction == FORWARD)
	{
		this->Position += this->Front * velocity;
	}
	if (direction == BACKWARD)
	{
		this->Position -= this->Front * velocity;
	}
	if (direction == LEFT)
	{
		this->Position -= this->Right * velocity;
	}
	if (direction == RIGHT)
	{
		this->Position += this->Right* velocity;
	}
}

void Camera::ProcessMouseMovement(GLfloat xoffset, GLfloat yoffset, GLboolean constrainPitch)
{
	xoffset *= this->MouseSensitivity;
	yoffset *= this->MouseSensitivity;

	this->Yaw += xoffset;
	this->Pitch -= yoffset;

	if (constrainPitch)
	{
		if (this->Pitch > 89.0f)
			this->Pitch = 89.0f;
		if (this->Pitch < -89.0f)
			this->Pitch = -89.0f;
	}

	this->updateCameraVectors();
}

void Camera::ProcessScroll(GLfloat yoffset)
{
}

void Camera::updateCameraVectors()
{
	glm::vec3 front;
	front.x = cos(glm::radians(this->Yaw)) * cos(glm::radians(this->Pitch));
	front.y = sin(glm::radians(this->Pitch));
	front.z = sin(glm::radians(this->Yaw))*cos(glm::radians(this->Pitch));

	this->Front = glm::normalize(front);

	this->Right = glm::normalize(glm::cross(this->Front, this->WorldUp));
	this->Up = glm::normalize(glm::cross(this->Right, this->Front));
}
