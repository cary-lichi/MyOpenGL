#pragma once
#include <iostream>
#include "stb_image.h"
#include <glad/glad.h>

class Texture
{
public:
	Texture();
	Texture(const char* url);
	~Texture();
	unsigned int texture;
	void use();
private:
	int width, height, nrChannels;
};