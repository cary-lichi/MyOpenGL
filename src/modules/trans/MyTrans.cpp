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

	VO = Utils::createSquareVO();

	textureBg = Texture("resources/textures/bricks2.jpg");

	stbi_set_flip_vertically_on_load(true);

	textureFace = Texture("resources/textures/awesomeface.png");

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

	glActiveTexture(GL_TEXTURE0);
	textureBg.use();
	glActiveTexture(GL_TEXTURE1);
	textureFace.use();

	shader.use();
	VO.use();

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

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

	transform = glm::mat4(1.0f); // reset it to identity matrix
	transform = glm::translate(transform, glm::vec3(-0.5f, 0.5f, 0.0f));
	double scaleAmount = sin(glfwGetTime());
	transform = glm::scale(transform, glm::vec3(scaleAmount, scaleAmount, scaleAmount));
	// 这一次，将矩阵值数组的第一个元素作为其内存指针值
	glUniformMatrix4fv(transformLoc, 1, GL_FALSE, &transform[0][0]);

	// 现在用新的变换替换均匀矩阵，再画一次。
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

	transform = glm::mat4(1.0f);
	//旋转
	transform = glm::rotate(transform, (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));
	//位移
	transform = glm::translate(transform, glm::vec3(0.5f, -0.5f, 0.0f));
	//缩放
	transform = glm::scale_slow(transform, glm::vec3(0.5f, 0.5f, 0.5f));

	//得到矩阵的均匀位置并设置矩阵
	glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

}

void MyTrans::exit()
{
	VO.dispose();
}
