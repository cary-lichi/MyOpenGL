#pragma once
#include "../../core/Command.h"
#include "stb_image.h"

class MyTrans :
	public Command
{
public:
	MyTrans();
	~MyTrans();
	void init();
	void render();
	void exit();
private:
	int width, height, nrChannels;
	Texture textureBg, textureFace;
	MyShaderVO VO;
	Shader shader;
};

