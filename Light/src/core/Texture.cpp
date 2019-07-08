#include "Texture.h"

Texture::Texture() {

}
Texture::Texture(string url) {

	string filename = "../resources/" + url;
	//����ͼƬ
	unsigned char* data = stbi_load(filename.c_str(), &width, &height, &nrChannels, 0);
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
		if (nrChannels == 3) {//rgb ������jpgͼ��
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		}
		else if (nrChannels == 4) {//rgba ������pngͼ��
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		}

		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else {
		std::cout << "ͼƬ����" << filename << "������ʧ��" << std::endl;
	}
	//�ͷ���Դ
	stbi_image_free(data);
}
void Texture::use() {
	glBindTexture(GL_TEXTURE_2D, texture);
}

Texture::~Texture() {

}
