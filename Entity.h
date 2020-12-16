#pragma once
#include "Structs.h"

class Entity {

public:

	//char name[20];
	int cPedAddr = 0x000000000000;
	float cPedHealth = 0;
	vec3d_f cPedCoords = {};
	Entity() {};
	void Print();
};