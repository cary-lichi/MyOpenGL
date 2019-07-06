
#include "modules/triangle/Triangle.h"
#include "modules/triangle/Triangle1.h"
#include "modules/texture/MyTexture.h"
#include "modules/texture/MyTexture2.h"
#include "modules/texture/MyTexture3.h"
#include "modules/trans/MyTrans.h"
#include "modules/cube/MyCube.h"
#include "modules/plane/MyPlane.h"
#include "modules/word/Word.h"

void showPptions() {
	std::cout << "请输入你的选项" << std::endl;
	std::cout << "1：彩色三角形" << std::endl;
	std::cout << "2：时间上线性变色三角形" << std::endl;
	std::cout << "3：纹理" << std::endl;
	std::cout << "4：纹理叠加" << std::endl;
	std::cout << "5：纹理练习" << std::endl;
	std::cout << "6：旋转缩放变换" << std::endl;
	std::cout << "7：平面" << std::endl;
	std::cout << "8：正方体" << std::endl;
	std::cout << "9：3D世界" << std::endl;
	std::cout << "0：关闭程序" << std::endl;
}

GLFWwindow* window;

//当前命令
Command* command;

int input = 3;
//bool DEBUG = true;
bool DEBUG = false;

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
		case 7:
			command = new MyPlane();
			break;
		case 8:
			command = new MyCube();
			break;
		case 9:
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

//动态设置屏幕大小
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
//输入
void processInput(GLFWwindow* window);
//鼠标
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

	//初始化GLFW
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//创建一个GLFW窗口
	window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "OpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "创建glfw窗口失败" << std::endl;
		glfwTerminate();
		return -1;
	}
	//渲染窗口
	glfwMakeContextCurrent(window);
	//窗口大小改变时执行framebuffer_size_callback
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	//鼠标输入
	glfwSetCursorPosCallback(window, mouseMove);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "加载失败" << std::endl;
		return -1;
	}

	init();

	//持续渲染
	while (!glfwWindowShouldClose(window))
	{
		//检测输入
		processInput(window);

		//渲染内容
		render();

		//交换颜色缓冲
		glfwSwapBuffers(window);
		//检测事件
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



