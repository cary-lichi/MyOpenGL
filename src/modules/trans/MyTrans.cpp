#include "MyTrans.h"

MyTrans::MyTrans()
{
}


MyTrans::~MyTrans()
{
}

void MyTrans::init()
{

	//创建Shader
	shader = Shader("MyTrans");

	//加载图片
	unsigned char* data = stbi_load("resources/textures/container.jpg", &width, &height, &nrChannels, 0);
	//创建纹理
	glGenTextures(1, &textureBg);
	glBindTexture(GL_TEXTURE_2D, textureBg);

	// 为当前绑定的纹理对象设置环绕、过滤方式
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	if (data) {
		//生成纹理
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else {
		std::cout << "加载失败" << std::endl;
	}
	//释放资源
	stbi_image_free(data);

	stbi_set_flip_vertically_on_load(true);

	//加载图片
	data = stbi_load("resources/textures/awesomeface.png", &width, &height, &nrChannels, 0);
	//创建纹理
	glGenTextures(1, &textureFace);
	glBindTexture(GL_TEXTURE_2D, textureFace);

	// 为当前绑定的纹理对象设置环绕、过滤方式
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	if (data) {
		//生成纹理
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else {
		std::cout << "加载失败" << std::endl;
	}
	//释放资源
	stbi_image_free(data);

	shader.use();
	shader.setInt("texture1", 0); // 手动设置
	shader.setInt("texture2", 1); // 或者使用着色器类设置
}

void MyTrans::render()
{
	//设置背景色
	glClearColor(0.5f, 0.0f, 0.5f, 1.0f);
	//重新渲染
	glClear(GL_COLOR_BUFFER_BIT);

	//glBindTexture(GL_TEXTURE_2D, texture);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, textureBg);
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, textureFace);

	// 创建 单位矩阵
	glm::mat4 transform = glm::mat4(1.0f); 
	//位移
	//transform = glm::translate(transform, glm::vec3(0.5f, -0.5f, 0.0f));
	//旋转
	transform = glm::rotate(transform, (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));
	//缩放
	transform = glm::scale_slow(transform, glm::vec3(0.5f, 0.5f, 0.5f));

	//得到矩阵的均匀位置并设置矩阵
	unsigned int transformLoc = glGetUniformLocation(shader.ID, "transform");
	glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));

	shader.use();

	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

	float vertices[] = {
		//     ---- 位置 ----       ---- 颜色 ----     - 纹理坐标 -
			 0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // 右上
			 0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // 右下
			-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // 左下
			-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // 左上
	};

	unsigned int indices[] = {
	   0, 1, 3, // first triangle
	   1, 2, 3  // second triangle
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
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	//告诉OpenGL该如何解析顶点数据
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	//解析颜色数据
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	//解析纹理数据
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);

	//设置为线条
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	//解绑
	//glBindBuffer(GL_ARRAY_BUFFER, 0);
	//glBindVertexArray(0);


}

void MyTrans::exit()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
}
