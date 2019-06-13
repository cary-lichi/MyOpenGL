#include "MyPlane.h"

MyPlane::MyPlane() {

}

MyPlane::~MyPlane() {

}

void MyPlane::init() {
	//创建Shader
	shader = Shader("MyPlane");

	VO = Utils::createSquareVO();

	textureBg = Texture("resources/textures/bricks2.jpg");

	stbi_set_flip_vertically_on_load(true);

	textureFace = Texture("resources/textures/awesomeface.png");

	shader.use();
	shader.setInt("texture1", 0); // 手动设置
	shader.setInt("texture2", 1); // 或者使用着色器类设置
}

void MyPlane::render() {
	//设置背景色
	glClearColor(0.5f, 0.0f, 0.5f, 1.0f);
	//重新渲染
	glClear(GL_COLOR_BUFFER_BIT);

	glActiveTexture(GL_TEXTURE0);
	textureBg.use();
	glActiveTexture(GL_TEXTURE1);
	textureFace.use();

	shader.use();

	glm::mat4 model = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
	glm::mat4 view = glm::mat4(1.0f);
	glm::mat4 projection = glm::mat4(1.0f);
	model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
	projection = glm::perspective(glm::radians(45.0f), (float)1000 / (float)1000, 0.1f, 100.0f);

	unsigned int modelLoc = glGetUniformLocation(shader.ID, "model");
	unsigned int viewLoc = glGetUniformLocation(shader.ID, "view");
	//将它们传递给着色器(3种不同的方法)
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, &view[0][0]);
	//注意:目前我们设置每个帧的投影矩阵，但是由于投影矩阵很少变化，所以最好只在主循环外设置一次。
	shader.setMat4("projection", projection);

	VO.use();
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

}

void MyPlane::exit() {
	VO.dispose();
}