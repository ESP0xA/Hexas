#pragma once
#include <vector>
#include "Init.h"
#include "Entity.h"
#include "Self.h"

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
	
	void GetHeistListInfo(Self self);
	void GetGangListInfo();
	void GetPlayerListInfo(Self self);
	void LoopList();
	void Print();
};
