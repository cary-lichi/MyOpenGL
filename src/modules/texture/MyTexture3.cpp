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

	//����ͼƬ
	unsigned char* data = stbi_load("resources/textures/bricks2.jpg", &width, &height, &nrChannels, 0);
	//��������
	glGenTextures(1, &textureBg);
	glBindTexture(GL_TEXTURE_2D, textureBg);

	// Ϊ��ǰ�󶨵������������û��ơ����˷�ʽ
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

	stbi_set_flip_vertically_on_load(true);

	//����ͼƬ
	data = stbi_load("resources/textures/awesomeface.png", &width, &height, &nrChannels, 0);
	//��������
	glGenTextures(1, &textureFace);
	glBindTexture(GL_TEXTURE_2D, textureFace);

	// Ϊ��ǰ�󶨵������������û��ơ����˷�ʽ
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	if (data) {
		//��������
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else {
		std::cout << "����ʧ��" << std::endl;
	}
	//�ͷ���Դ
	stbi_image_free(data);

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

	//glBindTexture(GL_TEXTURE_2D, texture);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, textureBg);
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, textureFace);

	shader.use();

	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

	float vertices[] = {
		//     ---- λ�� ----       ---- ��ɫ ----     - �������� -
			 0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   2.0f, 2.0f,   // ����
			 0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   2.0f, 0.0f,   // ����
			-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // ����
			-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 2.0f    // ����
	};

	unsigned int indices[] = {
	   0, 1, 3, // first triangle
	   1, 2, 3  // second triangle
	};

	//��������
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
	//��VAO
	glBindVertexArray(VAO);
	//��VBO�󶨵�GL_ARRAY_BUFFER��
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	//��vertices������д�뻺����ڴ�
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	//����OpenGL����ν�����������
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	//������ɫ����
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	//������������
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);

	//����Ϊ����
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	//���
	//glBindBuffer(GL_ARRAY_BUFFER, 0);
	//glBindVertexArray(0);

	
}

void MyTexture3::exit()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
}