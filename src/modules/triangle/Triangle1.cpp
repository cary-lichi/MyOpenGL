#include "Triangle1.h"

Triangle1::Triangle1()
{
}


Triangle1::~Triangle1()
{
}

 void  Triangle1::init() {

	//����Shader
	//shader = Shader("src/shader/Triangle1.vs","src/shader/Triangle1.fs");
	shader = Shader("Triangle1");

	//float vertices[] = {
	//0.5f, 0.5f, 0.0f,    //���Ͻ�
	//0.5f, -0.5f, 0.0f,   //���½�
	//-0.5f, -0.5f, 0.0f,  //���½�
	//-0.5f, 0.5f, 0.0f    //���Ͻ�
	//};

	//unsigned int indices[] = {  //ע��������0��ʼ! 
	//	0, 1, 3,  //��һ��������
	//	1, 2, 3   //�ڶ���������
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

	unsigned int indices[] = { // ע��������0��ʼ! 
		0,1,2,
			0,2,3,
			0,3,4,
			0,4,5,
			0,5,6,
			0,6,1,
	};

	float vertices[] = {
		// λ��               ��ɫ
		 0.5f, -0.5f, 0.0f,  1.0f, 0.5f, 0.0,  //  ����
		-0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // ����
		 0.0f,  0.5f, 0.0f,  0.0f, 0.5f, 1.0f    // ����
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
	//��EBO�󶨵�GL_ELEMENT_ARRAY_BUFFER��
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	//��indices������д�뻺����ڴ�
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	//����OpenGL����ν�����������
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	//���ö�������
	glEnableVertexAttribArray(0);
	//������ɫ����
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	//���ö�������
	glEnableVertexAttribArray(1);

	//����Ϊ����
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	//���
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void Triangle1::render(){
	//���ñ���ɫ
	glClearColor(0.5f, 0.0f, 0.5f, 1.0f);
	//������Ⱦ
	glClear(GL_COLOR_BUFFER_BIT);
	//������� ÿ����ɫ�����ú���Ⱦ���ö���ʹ������������
	shader.use();

	//����uniform��ɫ
	float timeValue = float(glfwGetTime());
	float rValue = sin(timeValue) / 2.0f + 0.5f;
	float gValue = sin(timeValue) / 2.0f - 0.5f;
	float bValue = sin(timeValue) / 4.0f + 0.0f;
	shader.setVector3("myColor", rValue, gValue, bValue);

	//��VAO
	glBindVertexArray(VAO);
	//��ʹ�õ�ǰ�������ɫ������VBO�Ķ������ݣ�ͨ��VAO��Ӱ󶨣�����ͼԪ
	glDrawArrays(GL_TRIANGLES, 0, 3);
	//ʹ�õ�ǰ�󶨵�������������е��������л���
	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
}

void Triangle1::exit() {
	//��������
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
}
