#include "MyTexture3.h"

MyTexture3::MyTexture3()
{
}


MyTexture3::~MyTexture3()
{
}

void MyTexture3::init()
{

	//����Shader
	shader = Shader("MyTexture3");

	const float vertices[] = {
		//     ---- λ�� ----       ---- ��ɫ ----     - �������� -
			 0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   2.0f, 2.0f,   // ����
			 0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   2.0f, 0.0f,   // ����
			-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // ����
			-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 2.0f    // ����
	};

	const unsigned int indices[] = {
	   0, 1, 3, // first triangle
	   1, 2, 3  // second triangle
	};

	VO = MyShaderVO(vertices, sizeof(vertices), indices, sizeof(indices));

	//����OpenGL����ν�����������
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	//������ɫ����
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	//������������
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);

	textureBg = Texture("resources/textures/bricks2.jpg");

	stbi_set_flip_vertically_on_load(true);

	textureFace = Texture("resources/textures/awesomeface.png");

	shader.use();
	shader.setInt("texture1", 0); // �ֶ�����
	shader.setInt("texture2", 1); // ����ʹ����ɫ��������
}

void MyTexture3::render()
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
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void MyTexture3::exit()
{
	VO.dispose();
}
