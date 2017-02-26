#include "AppBase.h"

void AppBase::onKeyboardInternal(GLFWwindow * window, int key, int scancode, int action, int mode)
{
	AppBase::m_mainApp->onKeyboard(key, scancode, action, mode);
}
void AppBase::onMouseInternal(GLFWwindow * window, double xpos, double ypos)
{
	AppBase::m_mainApp->onMouse(xpos, ypos);
}
void AppBase::onScrollInternal(GLFWwindow * window, double xoffset, double yoffset)
{
	AppBase::m_mainApp->onScroll(xoffset, yoffset);
}

AppBase* AppBase::m_mainApp;

AppBase::AppBase()
{

}

AppBase::AppBase(const char * title, GLuint width, GLuint height)
{
	AppBase::m_mainApp = this;

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	m_window = glfwCreateWindow(width, height, title, nullptr, nullptr);
	glfwMakeContextCurrent(m_window);

	glfwSetKeyCallback(m_window,&(AppBase::onKeyboardInternal));
	glfwSetCursorPosCallback(m_window,&(AppBase::onMouseInternal));
	glfwSetScrollCallback(m_window, &(AppBase::onScrollInternal));

	glfwGetFramebufferSize(m_window, &m_width, &m_height);
	glViewport(0, 0, m_width, m_height);

	glEnable(GL_DEPTH_TEST);
}


AppBase::~AppBase()
{

}

void AppBase::Run()
{
	onInit();
	loadRes();

	while (!glfwWindowShouldClose(m_window))
	{
		glfwPollEvents();
		GLfloat currentFrame =(GLfloat) glfwGetTime();
		m_deltaTime = currentFrame - m_lastFrame;
		m_lastFrame = currentFrame;

		update();

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		render();

		glfwSwapBuffers(m_window);
	}

	glfwTerminate();
}

void AppBase::onInit()
{
	glewExperimental = GL_TRUE;
	glewInit();

	DebugLog("app base init");
}

void AppBase::onKeyboard(int key, int scancode, int action, int mode)
{
}

void AppBase::onMouse(double xpos, double ypos)
{
}

void AppBase::onScroll(double xoffset, double yoffset)
{

}

void AppBase::loadRes()
{
}

void AppBase::update()
{
}

void AppBase::render()
{
}



