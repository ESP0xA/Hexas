#pragma once
#include "Structs.h"
#include "Init.h"

class Player {

private:
	Init init;

public:
	char name[20];
	float health;
	float matrix[16];
	vec2d_f screen;
	vec3d_f coords;
	int team;

	Player(Init this_init)
	{
		init = this_init;
	}

	void GetInfo();
	void Print();
};
