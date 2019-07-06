#pragma once
#include "../../core/Command.h"

class Triangle1 :
	public Command
{
public:
	Triangle1();
	~Triangle1();
	void init();
	void render();
	void exit();
private:
	/*
	�����������Vertex Array Object��VAO
	���㻺�����Vertex Buffer Object��VBO
	�����������Element Buffer Object��EBO��Index Buffer Object��IBO
	*/
	unsigned int VBO, VAO, EBO;
	int shaderProgram;
	Shader shader;
};

