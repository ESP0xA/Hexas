#pragma once
#include "Structs.h"

class Entity {

public:

	//char name[20];
	int cPedAddreass = 0x000000000000;
	float cPedHealth = 0;
	vec3d_f cPedCoords = {};
	//int team;
	Entity() {};
	void Print();
};