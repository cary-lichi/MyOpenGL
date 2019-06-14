#pragma once

#include "../../core/Command.h"

class Word :
	public Command
{
public:
	Word();
	~Word();
	void init();
	void render();
	void exit();
	void processInput(GLFWwindow* window);
	void mouseMove(GLFWwindow* window, double xpos, double ypos);
private:
	Texture textureBg, textureFace;
	MyShaderVO VO;
	Shader shader;
	glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
	glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
	float cameraSpeed = 0.05f;
	double deltaTime = 0.0f; // 当前帧与上一帧的时间差
	double lastFrame = 0.0f; // 上一帧的时间
	float sensitivity = 0.05f;//鼠标灵敏度
	double pitch=0.0f;//上下 俯仰角
	double yaw=-90.0f; //左右 偏航角
	bool firstMouse = true;
	//上一帧鼠标位置
	double lastX;
	double lastY;
};

