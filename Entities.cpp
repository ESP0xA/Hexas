#include <Windows.h>
#include <vector>
#include <iostream>
#include "Entities.h"
#include "Init.h"


void Entities::GetListInfo()
{
	/*
	* a: temp cped address
	* h: temp cped health
	* x, y, z: temp cped coords
	 */
	list = {}; // init list
	QWORD a = 0x000000000000;
	QWORD of_cPed = init.of_gangCped;
	for (int i = 0; i < 64; i++, of_cPed += 0x28) {
		Entity ent;
		float h = 0;
		float x, y, z = 0;
		ReadProcessMemory(init.procHandle, (LPCVOID)(init.moduleBase + of_cPed), &a, sizeof(a), nullptr);
		if (a) { // address not 0
			ReadProcessMemory(init.procHandle, LPCVOID(a + init.of_health), &h, sizeof(h), nullptr);
			if (!h) {
				continue;// health is 0
			}
			else {	 // good cped
				ReadProcessMemory(init.procHandle, LPCVOID(a + init.of_coordX), &x, sizeof(x), nullptr);
				ReadProcessMemory(init.procHandle, LPCVOID(a + init.of_coordY), &y, sizeof(y), nullptr);
				ReadProcessMemory(init.procHandle, LPCVOID(a + init.of_coordZ), &z, sizeof(z), nullptr);
				ent.cPedAddreass = a;
				ent.cPedHealth = h;
				ent.cPedCoords.x = x, ent.cPedCoords.y = y, ent.cPedCoords.z = z;
				list.push_back(ent);
			}
		}
	}
	amount = list.size();
}

void Entities::LoopList() {
	for (int i = 0; i < amount; i ++) {
		std::cout << i << "cPed Health: " << list[i].cPedHealth << "| Coords: {" << list[i].cPedCoords.x << ", " << list[i].cPedCoords.y << ", " << list[i].cPedCoords.z << "}" << "\r";
	}
	std::cout << "\n\n";
}

void Entities::Print()
{
	std::cout << "=============================" << "\n";
	std::cout << "========= Entities ==========" << "\n";
	std::cout << "=============================" << "\n\n";

	/*
	for (int i = 1; i < amount; i++)
	{
		list[i].Print();
	}
	*/
	std::cout << "\n\n";
}