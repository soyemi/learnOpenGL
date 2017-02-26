#pragma once
#include "AppBase.h"

class AppBoxRender :public AppBase
{
public:
	AppBoxRender(const char * title, GLuint width, GLuint height);
	~AppBoxRender();

	void onInit();
	void loadRes();
	void update();
	void render();

protected:
	void onKeyboard(int key, int scancode, int action, int mode);
	void onMouse(double xpos, double ypos);
	void onScroll(double xoffset, double yoffset);
	void doMovement();

private:
	Camera *m_pCamera;
	Shader *m_pShaderDefault;
	Texture *m_pTexture;

	RenderObject *m_pCube;

	GLuint m_VAO, m_VBO,m_EBO;
};

