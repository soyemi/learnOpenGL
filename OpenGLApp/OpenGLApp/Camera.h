#pragma once
#include <vector>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>

enum Camera_Movement
{
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT
};

const GLfloat YAW = -90.0f;
const GLfloat PITCH = 0.0f;
const GLfloat SPEED = 3.0F;
const GLfloat SENSITIVTY = 0.3F;
const GLfloat ZOOM = 45.0f;

class Camera
{
public:
	glm::vec3 Position;
	glm::vec3 Front;
	glm::vec3 Right;
	glm::vec3 Up;
	glm::vec3 WorldUp;
	GLfloat FOV;

	GLfloat Yaw;
	GLfloat Pitch;
	GLfloat MovementSpeed;
	GLfloat MouseSensitivity;
	GLfloat Zoom;

	Camera(
		glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f),
		glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f),
		glm::vec3 front = glm::vec3(0.0f, 0.0f, -1.0f),
		GLfloat yaw = YAW,
		GLfloat pitch = PITCH
	) :MovementSpeed(SPEED), MouseSensitivity(SENSITIVTY), Zoom(ZOOM),WorldUp()
	{
		this->Position = position;
		this->WorldUp = up;
		this->Pitch = pitch;
		this->Yaw = yaw;
		FOV = 45.0f;
	};
	~Camera();

	glm::mat4 GetViewMatrix();
	glm::mat4 GetPerspectiveMatrix();

	void ProcessKeyboard(Camera_Movement direction, GLfloat deltaTime);
	void ProcessMouseMovement(GLfloat xoffset, GLfloat yoofset, GLboolean constrainPitch = true);
	void ProcessScroll(GLfloat yoffset);

private:
	void updateCameraVectors();



};

