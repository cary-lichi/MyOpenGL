#include "Triangle.h"

Triangle::Triangle()
{

}


Triangle::~Triangle()
{
	
}

void Triangle::init() {
	 
	 //����������ɫ��
	 int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	 //д��Դ��
	 glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	 //����Դ��
	 glCompileShader(vertexShader);
	 int success;
	 char infoLog[512];
	 glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	 //����Ƿ����ɹ�
	 if (!success)
	 {
		 glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		 std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	 }
	 //Ƭ����ɫ��
	 int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	 glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	 glCompileShader(fragmentShader);
	 glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	 if (!success)
	 {
		 glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		 std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
	 }
	 //��������
	 shaderProgram = glCreateProgram();
	 //��������ɫ�����������
	 glAttachShader(shaderProgram, vertexShader);
	 glAttachShader(shaderProgram, fragmentShader);
	 //����
	 glLinkProgram(shaderProgram);
	 //����Ƿ����ӳɹ�
	 glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	 if (!success) {
		 glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		 std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	 }
	 //ɾ��������ɫȥ��Ƭ����ɫ��
	 glDeleteShader(vertexShader);
	 glDeleteShader(fragmentShader);

	 //float vertices[] = {
	 //0.5f, 0.5f, 0.0f,   // ���Ͻ�
	 //0.5f, -0.5f, 0.0f,  // ���½�
	 //-0.5f, -0.5f, 0.0f, // ���½�
	 //-0.5f, 0.5f, 0.0f   // ���Ͻ�
	 //};

	 //unsigned int indices[] = { // ע��������0��ʼ! 
	 //	0, 1, 3, // ��һ��������
	 //	1, 2, 3  // �ڶ���������
	 //};

	 //float vertices[] = {
	 //0.0f, 0.0f, 0.0f,
	 //-0.25f, 0.25f, 0.0f,   
	 //0.25f, 0.25f, 0.0f,  
	 //0.25f, -0.25f, 0.0f, 
	 //0.0f, -0.5f, 0.0f, 
	 //-0.5f, -0.5f, 0.0f,
	 //-0.5f, -0.0f, 0.0f,
	 //};

	 unsigned int indices[] = { // ע��������0��ʼ! 
		 0,1,2,
		 //	0,2,3,
		 //	0,3,4,
		 //	0,4,5,
		 //	0,5,6,
		 //	0,6,1,
	 };

	 float vertices[] = {
		 // λ��              // ��ɫ
		  0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // ����
		 -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // ����
		  0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f    // ����
	 };

	 /*
	 �����������Vertex Array Object��VAO
	 ���㻺�����Vertex Buffer Object��VBO
	 �����������Element Buffer Object��EBO��Index Buffer Object��IBO
	 */
	 
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

void Triangle::render() {

	//������� ÿ����ɫ�����ú���Ⱦ���ö���ʹ������������
	glUseProgram(shaderProgram);
	//���ñ���ɫ
	glClearColor(0.5f, 0.0f, 0.5f, 1.0f);
	//������Ⱦ
	glClear(GL_COLOR_BUFFER_BIT);

	// ����uniform��ɫ
	/*float timeValue = glfwGetTime();
	float rValue = sin(timeValue) / 2.0f + 0.5f;
	float gValue = sin(timeValue) /2.0f - 0.5f;
	float bValue = sin(timeValue) / 4.0f + 0.0f;
	int vertexColorLocation = glGetUniformLocation(shaderProgram, "myColor");
	glUniform4f(vertexColorLocation, rValue, gValue, bValue, 1.0f);*/

	//��VAO
	glBindVertexArray(VAO);
	//��ʹ�õ�ǰ�������ɫ������VBO�Ķ������ݣ�ͨ��VAO��Ӱ󶨣�����ͼԪ
	glDrawArrays(GL_TRIANGLES, 0, 3);
	//ʹ�õ�ǰ�󶨵�������������е��������л���
	//glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
}

void Triangle::exit() {
	//��������
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
}


