#include "AppBoxRender.h"



AppBoxRender::AppBoxRender(const char * title, GLuint width, GLuint height):AppBase(title,width,height)
{
	DebugLog("AppBoxRender");
}


AppBoxRender::~AppBoxRender()
{
	DebugLog("AppBoxRender dector");

	delete m_pCamera;
	delete m_pShaderDefault;
	delete m_pTexture;
}

void AppBoxRender::onInit()
{
	DebugLog("AppBoxRender onInit");
	AppBase::onInit();
	m_pCamera = new Camera(glm::vec3(0.0f,0.0f,-3.0f));
}

void AppBoxRender::loadRes()
{
	DebugLog("AppBoxRender loadRes");
	AppBase::loadRes();
	Shader::SHADER_PATH = "F://git/learnOpenGL/OpenGLApp/Debug/Shader/";
	m_pShaderDefault =new Shader("default.vs", "default.fs");
	m_pTexture = new Texture("F://git/learnOpenGL/OpenGLApp/Debug/texture.png");
	m_pCube = new RenderObject(glm::vec3(0.0f,0.0f,10.0f), glm::vec3(0.0f,1.0f,0.0f),40.0f);

	GLfloat vertices[] = {
		0.5f,-0.5f,0.5f,
		0.5f,-0.5f,-0.5f,
		-0.5f,-0.5f,-0.5f,
		-0.5f,-0.5f, .5f,
		0.5f,0.5f,0.5f,
		0.5f,0.5f,-0.5f,
		-0.5f,0.5f,-0.5f,
		-0.5f,0.5f,0.5f 
	};
	GLuint indices[] = {
		0,2,1,
		0,3,2,
		4,5,6,
		4,6,7,
		0,4,7,
		0,7,3,

		1,5,4,
		1,4,0,
		2,6,5,
		2,5,1,
		3,7,6,
		3,6,2,
	};

	MeshBase * pMeshCube = new MeshBase();
	pMeshCube->SetVertices(vertices, 12);
	pMeshCube->SetIndices(indices, 36);

	m_pCube->pMesh = pMeshCube;

	glGenVertexArrays(1, &m_VAO);
	glGenBuffers(1, &m_VBO);
	glGenBuffers(1, &m_EBO);

	glBindVertexArray(m_VAO);

	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
	glBufferData(GL_ARRAY_BUFFER, m_pCube->pMesh->GetVerticesLen()* 8 , m_pCube->pMesh->GetVertices(), GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,m_pCube->pMesh->GetIndicesLen() * sizeof(GLuint), m_pCube->pMesh->GetIndices(), GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	m_pShaderDefault->Use();

}

void AppBoxRender::update()
{
	doMovement();

	GLint modelLoc = glGetUniformLocation(m_pShaderDefault->Program, "model");
	GLint viewLoc = glGetUniformLocation(m_pShaderDefault->Program, "view");
	GLint projectionLoc = glGetUniformLocation(m_pShaderDefault->Program, "projection");

	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(m_pCamera->GetViewMatrix()));

	glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(m_pCamera->GetPerspectiveMatrix()));

	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(m_pCube->GetModelMatrix()));
}

bool keys[1024];
void AppBoxRender::doMovement()
{
	GLfloat cameraSpeed = 5.0f * m_deltaTime;
	if (keys[GLFW_KEY_W])
		m_pCamera->ProcessKeyboard(FORWARD, m_deltaTime);
	if (keys[GLFW_KEY_S])
		m_pCamera->ProcessKeyboard(BACKWARD, m_deltaTime);
	if (keys[GLFW_KEY_A])
		m_pCamera->ProcessKeyboard(LEFT, m_deltaTime);
	if (keys[GLFW_KEY_D])
		m_pCamera->ProcessKeyboard(RIGHT, m_deltaTime);
}

void AppBoxRender::render()
{

	glBindVertexArray(m_VAO);

	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

	glBindVertexArray(0);
}



void AppBoxRender::onKeyboard(int key, int scancode, int action, int mode)
{
	if (action == GLFW_PRESS)
		keys[key] = true;
	else if (action == GLFW_RELEASE)
		keys[key] = false;
}

GLfloat lastX;
GLfloat lastY;

void AppBoxRender::onMouse(double xpos, double ypos)
{
	GLfloat xoffset = xpos - lastX;
	GLfloat yoffset = ypos - lastY;
	lastX = xpos;
	lastY = ypos;

	m_pCamera->ProcessMouseMovement(xoffset, yoffset);
}

void AppBoxRender::onScroll(double xoffset, double yoffset)
{
}
