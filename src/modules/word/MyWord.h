#pragma once

#include "../../core/Command.h"

class MyWord :
	public Command
{
public:
	MyWord();
	~MyWord();
	void init();
	void render();
	void exit();
	void processInput(GLFWwindow* window);
private:
	Texture textureBg, textureFace;
	MyShaderVO VO;
	Shader shader;
	glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
	glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
	float cameraSpeed = 0.05f; 
	float deltaTime = 0.0f; // 当前帧与上一帧的时间差
	float lastFrame = 0.0f; // 上一帧的时间
};

