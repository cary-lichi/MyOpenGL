#pragma once
#include "../../core/Command.h"

class MyTexture :
	public Command
{
public:
	MyTexture();
	~MyTexture();
	void init();
	void render();
	void exit();
private:
	int width, height, nrChannels;
	unsigned int texture;
	MyShaderVO VO;
	Shader shader;
};

