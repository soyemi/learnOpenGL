#pragma once
#include "Include.h"

class AppBase
{
public:
	AppBase();
	AppBase(const char* title,GLuint width,GLuint height);
	virtual ~AppBase();

	void Run();

protected:
	virtual void onInit();
	virtual void onKeyboard(int key, int scancode, int action, int mode);
	virtual void onMouse(double xpos, double ypos);
	virtual void onScroll(double xoffset, double yoffset);

	virtual void loadRes();
	virtual void update();
	virtual void render();

	GLfloat m_deltaTime = 0.0f;
	GLfloat m_lastFrame = 0.0f;

	int m_width;
	int m_height;

	GLFWwindow *m_window;
	static AppBase * m_mainApp;
private:
	static void onKeyboardInternal(GLFWwindow * window, int key, int scancode, int action, int mode);
	static void onMouseInternal(GLFWwindow *window, double xpos, double ypos);
	static void onScrollInternal(GLFWwindow* window, double xoffset, double yoffset);

	
};

