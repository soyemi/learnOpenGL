//#include "Include.h"
//
//using namespace glm;
//
//void key_callback(GLFWwindow * window, int key, int scancode, int action, int mode);
//void mouse_callback(GLFWwindow* window, double xpos, double ypos);
//void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
//
//void do_movement();
//
//const GLuint WIDTH = 800, HEIGHT = 600;
//
//bool keys[1024];
//
//GLfloat deltaTime = 0.0f;
//GLfloat lastFrame = 0.0f;
//
//GLfloat lastX = 400, lastY = 300;
//
//Camera camera;
//
//
//
//int main()
//{
//	std::cout << "Starting GLFW context,OpenGL 3.3" << std::endl;
//
//#pragma region  gl Init window
//	glfwInit();
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
//
//	GLFWwindow *window = glfwCreateWindow(WIDTH, HEIGHT, "OpenGLApp", nullptr, nullptr);
//	glfwMakeContextCurrent(window);
//
//	glfwSetKeyCallback(window, key_callback);
//	glfwSetCursorPosCallback(window, mouse_callback);
//	glfwSetScrollCallback(window, scroll_callback);
//
//	//init glew
//	glewExperimental = GL_TRUE;
//	glewInit();
//
//	int width, height;
//	glfwGetFramebufferSize(window, &width, &height);
//	glViewport(0, 0, width, height);
//
//	glEnable(GL_DEPTH_TEST);
//#pragma endregion
//
//	camera = Camera();
//
//	string sp = "F://git/learnOpenGL/OpenGLApp/Debug/Shader/";
//	Shader::SHADER_PATH = sp;
//
//
//	Shader defaultShader("default.vs","default.fs");
//
//	Shader testShader("color.glsl");
//
//	Texture tex1("F://git/learnOpenGL/OpenGLApp/Debug/texture.png");
//
//#pragma region Draw Data
//
//	glm::vec3 cubePositions[] = {
//		glm::vec3(0.0f,  0.0f,  0.0f),
//		glm::vec3(2.0f,  5.0f, -15.0f),
//	};
//
//	MeshCube cube;
//	
//
//	GLuint VBO, VAO;
//	glGenVertexArrays(1, &VAO);
//	glGenBuffers(1, &VBO);
//
//	glBindVertexArray(VAO);
//
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER,180*8, cube.GetVertices(), GL_STATIC_DRAW);
//
//	//pos
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
//	glEnableVertexAttribArray(0);
//
//	//color
//	//glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3* sizeof(GLfloat)));
//	//glEnableVertexAttribArray(1);
//
//	//uv
//	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid *)(3 * sizeof(GLfloat)));
//	glEnableVertexAttribArray(1);
//
//	glBindVertexArray(0);
//
//#pragma endregion
//	
//	glBindTexture(GL_TEXTURE_2D, tex1.GetTexture());
//
//	glm::mat4 view, projection;
//	view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
//	projection = camera.GetPerspectiveMatrix();
//
//
//	while (!glfwWindowShouldClose(window))
//	{
//		glfwPollEvents();
//
//		GLfloat currentFrame = glfwGetTime();
//		deltaTime = currentFrame - lastFrame;
//		lastFrame = currentFrame;
//
//		do_movement();
//
//		//render command
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//		//draw
//		defaultShader.Use();
//
//
//		glActiveTexture(GL_TEXTURE0);
//		
//		glUniform1i(glGetUniformLocation(defaultShader.Program, "ourTexture"), 0);
//
//		//set matrix
//		GLint modelLoc = glGetUniformLocation(defaultShader.Program, "model");
//		GLint viewLoc = glGetUniformLocation(defaultShader.Program, "view");
//		GLint projectionLoc = glGetUniformLocation(defaultShader.Program, "projection");
//		
//		
//		view = camera.GetViewMatrix();
//
//		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
//		glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));
//
//		glBindVertexArray(VAO);
//		for (GLuint i = 0; i < 2; i++)
//		{
//			glm::mat4 model;
//			model = glm::translate(model, cubePositions[i]);
//			GLfloat angle = 20.0f *i;
//			model = glm::rotate(model, angle, glm::vec3(1.0f, 0.3f, 0.5f));
//			glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//			
//			glDrawArrays(GL_TRIANGLES, 0, 36);
//		}
//		glBindVertexArray(0);
//
//		glfwSwapBuffers(window);
//	}
//
//	glDeleteVertexArrays(1, &VAO);
//	glDeleteBuffers(1, &VBO);
//
//	glfwTerminate();
//	return 0;
//}
//
//void key_callback(GLFWwindow * window, int key, int scancode, int action, int mode)
//{
//	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
//		glfwSetWindowShouldClose(window, GL_TRUE);
//
//	if (action == GLFW_PRESS)
//		keys[key] = true;
//	else if (action == GLFW_RELEASE)
//		keys[key] = false;
//}
//void mouse_callback(GLFWwindow *window, double xpos, double ypos)
//{
//	GLfloat xoffset = xpos - lastX;
//	GLfloat yoffset = ypos - lastY;
//	lastX = xpos;
//	lastY = ypos;
//
//	camera.ProcessMouseMovement(xoffset, yoffset);
//}
//void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
//{
//	camera.ProcessScroll(yoffset);
//}
//
//void do_movement()
//{
//	GLfloat cameraSpeed = 5.0f * deltaTime;
//	if (keys[GLFW_KEY_W])
//		camera.ProcessKeyboard(FORWARD, deltaTime);
//	if (keys[GLFW_KEY_S])
//		camera.ProcessKeyboard(BACKWARD, deltaTime);
//	if (keys[GLFW_KEY_A])
//		camera.ProcessKeyboard(LEFT, deltaTime);
//	if (keys[GLFW_KEY_D])
//		camera.ProcessKeyboard(RIGHT, deltaTime);
//}