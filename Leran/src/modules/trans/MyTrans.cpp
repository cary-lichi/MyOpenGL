#include "MyTrans.h"

MyTrans::MyTrans()
{
}


MyTrans::~MyTrans()
{
}

void MyTrans::init()
{

	//����Shader
	shader = Shader("MyTrans");

	VO = Utils::createSquareVO();

	textureBg = Texture("resources/textures/bricks2.jpg");

	stbi_set_flip_vertically_on_load(true);

	textureFace = Texture("resources/textures/awesomeface.png");

	shader.use();
	shader.setInt("texture1", 0); // �ֶ�����
	shader.setInt("texture2", 1); // ����ʹ����ɫ��������
}

void MyTrans::render()
{
	//���ñ���ɫ
	glClearColor(0.5f, 0.0f, 0.5f, 1.0f);
	//������Ⱦ
	glClear(GL_COLOR_BUFFER_BIT);

	glActiveTexture(GL_TEXTURE0);
	textureBg.use();
	glActiveTexture(GL_TEXTURE1);
	textureFace.use();

	shader.use();
	VO.use();

	// ���� ��λ����
	glm::mat4 transform = glm::mat4(1.0f); 
	//λ��
	//transform = glm::translate(transform, glm::vec3(0.5f, -0.5f, 0.0f));
	//��ת
	transform = glm::rotate(transform, (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));
	//����
	transform = glm::scale_slow(transform, glm::vec3(0.5f, 0.5f, 0.5f));

	//�õ�����ľ���λ�ò����þ���
	unsigned int transformLoc = glGetUniformLocation(shader.ID, "transform");
	glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

	transform = glm::mat4(1.0f); // reset it to identity matrix
	transform = glm::translate(transform, glm::vec3(-0.5f, 0.5f, 0.0f));
	double scaleAmount = sin(glfwGetTime());
	transform = glm::scale(transform, glm::vec3(scaleAmount, scaleAmount, scaleAmount));
	// ��һ�Σ�������ֵ����ĵ�һ��Ԫ����Ϊ���ڴ�ָ��ֵ
	glUniformMatrix4fv(transformLoc, 1, GL_FALSE, &transform[0][0]);

	// �������µı任�滻���Ⱦ����ٻ�һ�Ρ�
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

	transform = glm::mat4(1.0f);
	//��ת
	transform = glm::rotate(transform, (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));
	//λ��
	transform = glm::translate(transform, glm::vec3(0.5f, -0.5f, 0.0f));
	//����
	transform = glm::scale_slow(transform, glm::vec3(0.5f, 0.5f, 0.5f));

	//�õ�����ľ���λ�ò����þ���
	glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

}

void MyTrans::exit()
{
	VO.dispose();
}
