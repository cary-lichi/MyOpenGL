#pragma once
#include "../../core/Command.h"


class TriangleTime: 
	public Command
{
public:
	TriangleTime();
	~TriangleTime();
	void init();
	void render();
	void exit();
};

