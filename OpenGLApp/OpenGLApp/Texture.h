#pragma once
#include <gl\glew.h>
#include <SOIL\SOIL.h>
#include <GLFW\glfw3.h>
#include <string>

using namespace std;

class Texture
{
public:
	Texture();
	Texture(const char* filePath);
	~Texture();

	void GetSize(int * width, int * height);
	GLuint GetTexture();

private:
	GLuint m_texture;
	int m_width;
	int m_height;
};

