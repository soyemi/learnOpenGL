#pragma once
#include <iostream>
#define GLEW_STATIC
#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include "Shader.h"
#include <SOIL\SOIL.h>
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtc\type_ptr.hpp>
#include "Camera.h"
#include "Texture.h"
#include "MeshBase.h"
#include "RenderObject.h"
#include <string>
#include <fstream>
#include <sstream>

#pragma once
#define DebugLog(x) std::cout<<x<<std::endl;
