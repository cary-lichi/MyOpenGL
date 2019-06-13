#pragma once
#include "../../core/Command.h"
#include "stb_image.h"

class MyTexture2 :
	public Command
{
public:
	MyTexture2();
	~MyTexture2();
	void init();
	void render();
	void exit();
private:
	int width, height, nrChannels;
	Texture textureBg, textureFace;
	MyShaderVO VO;
	Shader shader;
};

