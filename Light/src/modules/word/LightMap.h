#pragma once

#include "../../core/Command.h";
#include "../../core/Material.h";
#include "../../core/Light.h";

class LightMap :
	public Command
{
public:
	LightMap();
	~LightMap();
	void init();
	void render();
	void exit();
	void processInput(GLFWwindow* window);
	void mouseMove(GLFWwindow* window, double xpos, double ypos);
private:
	Texture textureDiffuse, textureSpecular, textureEmission;
	MyShaderVO VO;
	MyShaderVO lightVAO;
	Shader shader;
	Shader lampShader;

	/*-------------相机的参数---------------*/
	glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);//相机位置
	glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);//相机方向
	glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);//相机上向量
	float cameraSpeed = 0.05f;//相机移动速度
	double deltaTime = 0.0f; // 当前帧与上一帧的时间差
	double lastFrame = 0.0f; // 上一帧的时间
	float sensitivity = 0.05f;//鼠标灵敏度
	double pitch = 0.0f;//上下 俯仰角
	double yaw = -90.0f; //左右 偏航角
	bool firstMouse = true;//首次检测到鼠标移动
	//上一帧鼠标位置
	double lastX;
	double lastY;

	/*------------光的参数--------------------*/
	//glm::vec3 lightColor = glm::vec3(1.0f, 1.0f, 1.0f);//光源颜色
	//glm::vec3 lightPos = glm::vec3(1.2f, 1.0f, 1.0f);//光源位置

	//glm::vec3 objectColor = glm::vec3(1.0f, 0.5f, 0.31f);//物体颜色
	//float ambientStrength = 0.1;//环境光照强度
	//float specularStrength = 0.5;//镜面强度
	//int shininess = 32;//反光度

	///----------------黏土色块-----------------///
	//Material material = Material(
	//	glm::vec3(1.0f, 0.5f, 0.31f),//环境光
	//	glm::vec3(1.0f, 0.5f, 0.31f),//漫反射
	//	glm::vec3(0.5f, 0.5f, 0.5f),//镜面光
	//	32.0f//反光度
	//);

	//Light light = Light(
	//	glm::vec3(0.2f, 0.2f, 0.2f),//环境光
	//	glm::vec3(0.5f, 0.5f, 0.5f),//漫反射
	//	glm::vec3(1.0f, 1.0f, 1.0f),//镜面光
	//	glm::vec3(1.2f, 1.0f, 1.0f)//光源位置
	//);

	///----------------青色塑料的箱子-----------------///
	Material material = Material(
		glm::vec3(0.0f, 0.1f, 0.06f),//环境光
		glm::vec3(0.0f, 0.50980392f, 0.50980392f),//漫反射
		glm::vec3(0.50196078f, 0.50196078f, 0.50196078f),//镜面光
		32.0f//反光度
	);

	Light light = Light(
		glm::vec3(1.0f, 1.0f, 1.0f),//环境光
		glm::vec3(1.0f, 1.0f, 1.0f),//漫反射
		glm::vec3(1.0f, 1.0f, 1.0f),//镜面光
		glm::vec3(1.0f, 1.0f, 1.0f)//光源位置
	);
};

