#pragma once
#include "include.h"
class MyShaderVO
{
public:
	MyShaderVO() {};
	~MyShaderVO();
	MyShaderVO(const float * vertices, const unsigned long long vsize);
	MyShaderVO(const float * vertices, const unsigned long long vsize, const unsigned int * indices, const unsigned long long isize);
	unsigned int VBO, VAO, EBO;
	void use();
	void dispose();
private:
	bool isUseEBO;
	void createVAO();
	void createVBO(const float * vertices, const unsigned long long vsize);
	void createEBO(const unsigned int * indices, const unsigned long long isize);

};

