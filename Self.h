#pragma once
#include "Structs.h"
#include "Init.h"

class Self {

private:
	Init init;

public:
	// address
	QWORD localPlayerAddr= 0x0;
	QWORD pInstGtaAddr = 0x0;
	QWORD gangCpedEntsListAddr = 0x0;
	// info
	float health = 0;
	float matrix[16] = {};
	vec2d_f screen = {};
	vec3d_f coords = {};

	Self(Init this_init)
	{
		init = this_init;
	}

	void GetBasicInfo();
	void GetDynamicInfo();
	void Print();
};
