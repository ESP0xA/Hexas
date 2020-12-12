#pragma once
#include "Structs.h"
#include "Init.h"

class Player {

private:
	Init init;

public:

	char name[20];
	int base;
	int health;
	float matrix[16];
	vec2d_f screen;
	vec3d_f position_head;
	vec3d_f position_feet;
	int team;

	Player(Init this_init)
	{
		init = this_init;
	}

	void GetInfo();
	void Print();
};
