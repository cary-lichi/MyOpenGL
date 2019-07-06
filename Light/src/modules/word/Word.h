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
	MyShaderVO lightVAO;
	Shader shader;
	Shader lampShader;

	/*-------------����Ĳ���---------------*/
	glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);//���λ��
	glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);//�������
	glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);//���������
	float cameraSpeed = 0.05f;//����ƶ��ٶ�
	double deltaTime = 0.0f; // ��ǰ֡����һ֡��ʱ���
	double lastFrame = 0.0f; // ��һ֡��ʱ��
	float sensitivity = 0.05f;//���������
	double pitch = 0.0f;//���� ������
	double yaw = -90.0f; //���� ƫ����
	bool firstMouse = true;//�״μ�⵽����ƶ�
	//��һ֡���λ��
	double lastX;
	double lastY;
	
	/*------------��Ĳ���--------------------*/
	glm::vec3 objectColor = glm::vec3(1.0f, 0.5f, 0.31f);//������ɫ
	glm::vec3 lightColor = glm::vec3(1.0f, 1.0f, 1.0f);//��Դ��ɫ
	glm::vec3 lightPos = glm::vec3(1.2f, 1.0f, 1.0f);//��Դλ��
	float ambientStrength = 0.1;//��������ǿ��
	float specularStrength = 0.5;//����ǿ��
	int shininess = 32;//�����
	
};

