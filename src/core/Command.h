#pragma once

#include "include.h"

class Command
{
public:
	Command() {
		
	};
	~Command() {};
	virtual void init() {};
	virtual	void render() {};
	virtual void exit() {};
};

 