#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "stb_image.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

//�Զ���
#include "MyShaderVO.h"
#include "Shader.h"
#include "Texture.h"
#include "../utils/Utils.h"

// settings
//��Ļ��С
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

class Command
{
public:
	Command() {
		
	};
	~Command() {};
	virtual void init() {};
	virtual	void render() {};
	virtual void exit() {};
};

 