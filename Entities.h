#pragma once
#include <vector>
#include "Init.h"
#include "Entity.h"


class Entities {

private:
	Init init;

public:
	int amount;
	std::vector<Entity> list{ amount };

	void GetEntityAmount();

	Entities(Init this_init)
	{
		init = this_init;
		GetEntityAmount(); // Need to init with knowing how many entities there are.
	}

	void GetInfo();
	void Print();
};
