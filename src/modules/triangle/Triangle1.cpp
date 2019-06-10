#include "Triangle1.h"

Triangle1::Triangle1()
{
}


Triangle1::~Triangle1()
{
}

 void  Triangle1::init() {

	//创建Shader
	//shader = Shader("src/shader/Triangle1.vs","src/shader/Triangle1.fs");
	shader = Shader("Triangle1");

	//float vertices[] = {
	//0.5f, 0.5f, 0.0f,    //右上角
	//0.5f, -0.5f, 0.0f,   //右下角
	//-0.5f, -0.5f, 0.0f,  //左下角
	//-0.5f, 0.5f, 0.0f    //左上角
	//};

	//unsigned int indices[] = {  //注意索引从0开始! 
	//	0, 1, 3,  //第一个三角形
	//	1, 2, 3   //第二个三角形
	//};

	/*float vertices[] = {
	0.0f, 0.0f, 0.0f,
	-0.25f, 0.25f, 0.0f,   
	0.25f, 0.25f, 0.0f,  
	0.25f, -0.25f, 0.0f, 
	0.0f, -0.5f, 0.0f, 
	-0.5f, -0.5f, 0.0f,
	-0.5f, -0.0f, 0.0f,
	};*/

	unsigned int indices[] = { // 注意索引从0开始! 
		0,1,2,
			0,2,3,
			0,3,4,
			0,4,5,
			0,5,6,
			0,6,1,
	};

	float vertices[] = {
		// 位置               颜色
		 0.5f, -0.5f, 0.0f,  1.0f, 0.5f, 0.0,  //  右下
		-0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // 左下
		 0.0f,  0.5f, 0.0f,  0.0f, 0.5f, 1.0f    // 顶部
	};

	//创建对象
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
	//绑定VAO
	glBindVertexArray(VAO);
	//把VBO绑定到GL_ARRAY_BUFFER上
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	//把vertices的数据写入缓冲的内存
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	//把EBO绑定到GL_ELEMENT_ARRAY_BUFFER上
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	//把indices的数据写入缓冲的内存
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	//告诉OpenGL该如何解析顶点数据
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	//启用顶点属性
	glEnableVertexAttribArray(0);
	//解析颜色数据
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	//启用顶点属性
	glEnableVertexAttribArray(1);

	//设置为线条
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	//解绑
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void Triangle1::render(){
	//设置背景色
	glClearColor(0.5f, 0.0f, 0.5f, 1.0f);
	//重新渲染
	glClear(GL_COLOR_BUFFER_BIT);
	//激活程序 每个着色器调用和渲染调用都会使用这个程序对象
	shader.use();

	//更新uniform颜色
	float timeValue = float(glfwGetTime());
	float rValue = sin(timeValue) / 2.0f + 0.5f;
	float gValue = sin(timeValue) / 2.0f - 0.5f;
	float bValue = sin(timeValue) / 4.0f + 0.0f;
	shader.setVector3("myColor", rValue, gValue, bValue);

	//绑定VAO
	glBindVertexArray(VAO);
	//它使用当前激活的着色器，和VBO的顶点数据（通过VAO间接绑定）绘制图元
	glDrawArrays(GL_TRIANGLES, 0, 3);
	//使用当前绑定的索引缓冲对象中的索引进行绘制
	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
}

void Triangle1::exit() {
	//销毁数据
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
}
