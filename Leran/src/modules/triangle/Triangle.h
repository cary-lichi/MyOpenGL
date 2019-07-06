#pragma once
#include "../../core/Command.h"

class Triangle :
	public Command

{
public:
	Triangle();
	~Triangle();
	void init();
	void render();
	void exit();
private:
	unsigned int VBO, VAO, EBO;
	int shaderProgram;
	//顶点着色器源码
	const char* vertexShaderSource = "#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"layout (location = 1) in vec3 aColor;\n"
		"out vec4 myColor;\n"
		"void main()\n"
		"{\n"
		"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
		"   myColor = vec4(aColor,1.0f);\n"
		"}\0";
	//片段着色器源码
	const char* fragmentShaderSource = "#version 330 core\n"
		"out vec4 FragColor;\n"
		"in vec4 myColor;\n"
		"void main()\n"
		"{\n"
		"   FragColor = myColor;\n"
		"}\n\0";
};

