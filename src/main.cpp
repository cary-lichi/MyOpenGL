#include "core/Command.h"
#include "modules/triangle/Triangle.h"
#include "modules/triangle/Triangle1.h"
#include "modules/texture/MyTexture.h"
#include "modules/texture/MyTexture2.h"
#include "modules/texture/MyTexture3.h"
#include "modules/trans/MyTrans.h"

Command* command;
int input=3;
//bool DEBUG = true;
bool DEBUG = false;

void showPptions() {
	std::cout << "���������ѡ��" << std::endl;
	std::cout << "1����ɫ������" << std::endl;
	std::cout << "2��ʱ�������Ա�ɫ������" << std::endl;
	std::cout << "3������" << std::endl;
	std::cout << "4���������" << std::endl;
	std::cout << "5��������ϰ" << std::endl;
	std::cout << "6����ת���ű任" << std::endl;
	std::cout << "0���رճ���" << std::endl;
}
void init() {
	switch (input) {
		case 1:
			command = new Triangle();
			break;
		case 2:
			command = new Triangle1();
			break;
		case 3:
			command = new MyTexture();
			break;
		case 4:
			command = new MyTexture2();
			break;
		case 5:
			command = new MyTexture3();
			break;
		case 6:
			command = new MyTrans();
			break;
	}
	command->init();
}

void render() {
	command->render();
}

void exit() {
	command->exit();
}

//��̬������Ļ��С
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
//����
void processInput(GLFWwindow* window);
int createWindw();
// settings
//��Ļ��С
const unsigned int SCR_WIDTH = 1000;
const unsigned int SCR_HEIGHT = 1000;
bool isClose;

int main()
{
	isClose = true;
	if (DEBUG) {
		createWindw();
		return 0;
	}
	while (isClose) {
		showPptions();
		std::cin >> input;

		if (input > 0) {
			createWindw(); 
		}
		else {
			isClose = false;
		}
	}
	return 0;
}

int createWindw() {

	//��ʼ��GLFW
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//����һ��GLFW����
	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "OpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "����glfw����ʧ��" << std::endl;
		glfwTerminate();
		return -1;
	}
	//��Ⱦ����
	glfwMakeContextCurrent(window);
	//���ڴ�С�ı�ʱִ��framebuffer_size_callback
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "����ʧ��" << std::endl;
		return -1;
	}

	init();

	//������Ⱦ
	while (!glfwWindowShouldClose(window))
	{
		//�������
		processInput(window);

		//��Ⱦ����
		render();

		//������ɫ����
		glfwSwapBuffers(window);
		//����¼�
		glfwPollEvents();
	}
	glfwTerminate();
	exit();
	return 0;
}

void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

void framebuffer_size_callback(GLFWwindow * window, int width, int height)
{
	glViewport(0, 0, width, height);
}



