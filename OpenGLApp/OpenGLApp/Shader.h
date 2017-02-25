#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

#include <GL\glew.h>

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

