#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "stb_image.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

//×Ô¶¨Òå
#include "MyShaderVO.h"
#include "Shader.h"
#include "Texture.h"
#include "../utils/Utils.h"

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

 