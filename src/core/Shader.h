#pragma once
#define SHADER_H

#include <glad/glad.h> // ����glad����ȡ���еı���OpenGLͷ�ļ�
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
using namespace std;

class Shader
{
public:
	Shader() {};
	~Shader();
	// ��������ȡ��������ɫ��
	Shader(string shaderName);
	Shader(const GLchar* vertexPath, const GLchar* fragmentPath);
	// ʹ��/�������
	void use();
	// uniform���ߺ���
	void setBool(const std::string& name, bool value) const;
	void setInt(const std::string& name, int value) const;
	void setFloat(const std::string& name, float value) const;
	void setVector3(const std::string& name, float rValue, float gValue, float bValue) const;
	// ����ID
	int ID;
private:
	void CreateShader(string vertexPath, string fragmentPath);
};

