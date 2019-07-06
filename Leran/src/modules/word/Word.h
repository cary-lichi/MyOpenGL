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
	double deltaTime = 0.0f; // ��ǰ֡����һ֡��ʱ���
	double lastFrame = 0.0f; // ��һ֡��ʱ��
	float sensitivity = 0.05f;//���������
	double pitch=0.0f;//���� ������
	double yaw=-90.0f; //���� ƫ����
	bool firstMouse = true;
	//��һ֡���λ��
	double lastX;
	double lastY;
};

