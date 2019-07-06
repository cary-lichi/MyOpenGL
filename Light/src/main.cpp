

#include "modules/word/Word.h"

void showPptions() {
	std::cout << "���������ѡ��" << std::endl;
	std::cout << "1������" << std::endl;
	std::cout << "0���˳�" << std::endl;

}

GLFWwindow* window;

//��ǰ����
Command* command;

int input = 3;
//bool DEBUG = true;
bool DEBUG = false;

void init() {
	switch (input) {
		case 1:
			command = new Word();
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
//���
void mouseMove(GLFWwindow* window, double xpos, double ypos);
int createWindw();

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
	window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "OpenGL", NULL, NULL);
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
	//�������
	glfwSetCursorPosCallback(window, mouseMove);
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
	command->processInput(window);
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

void mouseMove(GLFWwindow* window, double xpos, double ypos) {
	command->mouseMove(window,  xpos,  ypos);
}

void framebuffer_size_callback(GLFWwindow * window, int width, int height)
{
	glViewport(0, 0, width, height);
}


