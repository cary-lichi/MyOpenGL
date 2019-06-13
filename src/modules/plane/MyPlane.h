#pragma once

#include "../../core/Command.h"

class MyPlane :
	public Command
{
public:
	MyPlane();
	~MyPlane();
	void init();
	void render();
	void exit();
private:
	Texture textureBg, textureFace;
	MyShaderVO VO;
	Shader shader;
};

