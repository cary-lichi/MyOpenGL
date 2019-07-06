#pragma once
#include <iostream>
#include "stb_image.h"
#include <glad/glad.h>
#include <string>
using namespace std;

class Texture
{
public:
	Texture();
	//Texture(const char* url);
	Texture(string url);
	~Texture();
	unsigned int texture;
	void use();
private:
	int width, height, nrChannels;
};