#pragma once
#include "include.h"

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