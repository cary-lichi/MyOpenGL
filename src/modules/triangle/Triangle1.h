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
	顶点数组对象：Vertex Array Object，VAO
	顶点缓冲对象：Vertex Buffer Object，VBO
	索引缓冲对象：Element Buffer Object，EBO或Index Buffer Object，IBO
	*/
	unsigned int VBO, VAO, EBO;
	int shaderProgram;
	Shader shader;
};

