#pragma once
#include "AppBase.h"

using namespace std;

class Shader
{
	
public:

	GLuint Program;
	Shader(const char* vertexPath, const char* fragmentPath);
	Shader(string shaderPath);
	void Use();
	~Shader();
public:
	static string SHADER_PATH;

};

