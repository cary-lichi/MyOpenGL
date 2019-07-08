#include "Texture.h"

Texture::Texture() {

}
Texture::Texture(string url) {

	string filename = "../resources/" + url;
	//加载图片
	unsigned char* data = stbi_load(filename.c_str(), &width, &height, &nrChannels, 0);
	//创建纹理
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	// 为当前绑定的纹理对象设置环绕、过滤方式
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	if (data) {
		//生成纹理
		if (nrChannels == 3) {//rgb 适用于jpg图像
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		}
		else if (nrChannels == 4) {//rgba 适用于png图像
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		}

		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else {
		std::cout << "图片：“" << filename << "”加载失败" << std::endl;
	}
	//释放资源
	stbi_image_free(data);
}
void Texture::use() {
	glBindTexture(GL_TEXTURE_2D, texture);
}

Texture::~Texture() {

}
