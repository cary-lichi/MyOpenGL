#include "MyShaderVO.h"


MyShaderVO::MyShaderVO(const float * vertices, const unsigned long long vsize) {
	isUseEBO = false;
	createVAO();
	createVBO(vertices, vsize);
}
MyShaderVO::MyShaderVO(const float* vertices, const unsigned long long vsize, const unsigned int* indices, const unsigned long long isize) {
	isUseEBO = true;
	createVAO();
	createVBO(vertices, vsize);
	createEBO(indices, isize);
}

void MyShaderVO::createVAO() {
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
}

void MyShaderVO::createVBO(const float * vertices, const unsigned long long vsize) {
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, vsize, vertices, GL_STATIC_DRAW);
}

void MyShaderVO::createEBO(const unsigned int * indices, const unsigned long long isize) {

	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, isize, indices, GL_STATIC_DRAW);
}

void MyShaderVO::use() {
	glBindVertexArray(VAO);
}

void MyShaderVO::dispose() {
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
}


MyShaderVO::~MyShaderVO() {
}