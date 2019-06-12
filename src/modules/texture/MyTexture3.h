#pragma once
#include "../../core/Command.h"
#include "stb_image.h"

class MyTexture3 :
	public Command
{
public:
	MyTexture3();
	~MyTexture3();
	void init();
	void render();
	void exit();
private:
	int width, height, nrChannels;
	unsigned int textureBg, textureFace;
	unsigned int VBO, VAO, EBO;
	Shader shader;
};

