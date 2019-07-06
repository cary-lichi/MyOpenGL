#include "MyTexture.h"

MyTexture::MyTexture()
{
}


MyTexture::~MyTexture()
{
}

void MyTexture::init()
{
	//����ͼƬ
	unsigned char* data = stbi_load("../resources/textures/container.jpg", &width, &height, &nrChannels, 0);
	//��������
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	// Ϊ��ǰ�󶨵�����������û��ơ����˷�ʽ
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	if (data) {
		//��������
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else {
		std::cout << "����ʧ��" << std::endl;
	}
	//�ͷ���Դ
	stbi_image_free(data);

	//����Shader
	shader = Shader("MyTexture");

	VO = Utils::createSquareVO();
}

void MyTexture::render()
{
	//���ñ���ɫ
	glClearColor(0.5f, 0.0f, 0.5f, 1.0f);
	//������Ⱦ
	glClear(GL_COLOR_BUFFER_BIT);

	glBindTexture(GL_TEXTURE_2D, texture);

	shader.use();

	VO.use();
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void MyTexture::exit()
{
	VO.dispose();
}
