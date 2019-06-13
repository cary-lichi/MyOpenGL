#pragma once

#include "../../core/Command.h"

class MyCube :
	public Command
{
public:
	MyCube();
	~MyCube();
	void init();
	void render();
	void exit();
private:
	Texture textureBg, textureFace;
	MyShaderVO VO;
	Shader shader;
};

