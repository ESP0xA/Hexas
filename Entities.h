#pragma once
#include <vector>
#include "Init.h"
#include "Entity.h"

const int N = 100;
class Entities {

private:
	Init init;

public:
	int amount = 0;
	std::vector<Entity> list = {};
	Entities(Init this_init)
	{
		init = this_init;
		//GetEntityAmount(); // Need to init with knowing how many entities there are.
	}
	
	void GetInfo();
	void Print();
};
