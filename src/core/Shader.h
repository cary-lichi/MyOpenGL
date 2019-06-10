#pragma once
#define SHADER_H

#include <glad/glad.h> // 包含glad来获取所有的必须OpenGL头文件
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
	// 构造器读取并构建着色器
	Shader(string shaderName);
	Shader(const GLchar* vertexPath, const GLchar* fragmentPath);
	// 使用/激活程序
	void use();
	// uniform工具函数
	void setBool(const std::string& name, bool value) const;
	void setInt(const std::string& name, int value) const;
	void setFloat(const std::string& name, float value) const;
	void setVector3(const std::string& name, float rValue, float gValue, float bValue) const;
	// 程序ID
	int ID;
private:
	void CreateShader(string vertexPath, string fragmentPath);
};

