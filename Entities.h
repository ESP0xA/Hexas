#pragma once
#include <vector>
#include "Init.h"
#include "Entity.h"
#include "Player.h"

const int N = 100;
class Entities {

private:
	Init init;

public:
	std::vector<QWORD> addrList = {};
	std::vector<Entity> list = {};
	int amount = 0;
	Entities(Init this_init)
	{
		init = this_init;
		//GetEntityAmount(); // Need to init with knowing how many entities there are.
	}
	
	void GetListInfo();
	void GetPlayerListInfo(Player player);
	void LoopList();
	//vec3d_f GetSelfInfo(Player player);
	void Print();
};
