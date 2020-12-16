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
	//QWORD of_cPed = init.of_lobbyCped;
	DWORD offset_of_ents = 0x28;
	for (int i = 0; i < 64; i++, of_cPed += offset_of_ents) {
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

void Entities::GetPlayerListInfo(Player player)
{
	/*
	* a: temp cped address
	* h: temp cped health
	* x, y, z: temp cped coords
	 */
	list = {}; // init list
	QWORD a = 0x000000000000;
	QWORD of_cPed = init.of_player;
	DWORD offset_of_ents = 0xc0;
	for (int i = 0; i < 40; i++, of_cPed += offset_of_ents) {
		Entity ent;
		float h = 0;
		float x, y, z = 0;
		ReadProcessMemory(init.procHandle, (LPCVOID)(init.moduleBase + of_cPed), &a, sizeof(a), nullptr);
		//if (a) addrList.push_back(a);
		if (a) { // address not 0
			ReadProcessMemory(init.procHandle, LPCVOID(a + init.of_health), &h, sizeof(h), nullptr);
			if (h != h || h < 1 || h > 1000 || h == 150 || h == 175) {
				continue;
			}
			else {	 // good player
				// exclude self
				//player.GetInfo();
				//if (player.health - h > -1 && player.health - h < 1) continue;

				ReadProcessMemory(init.procHandle, LPCVOID(a + init.of_coordX), &x, sizeof(x), nullptr);
				ReadProcessMemory(init.procHandle, LPCVOID(a + init.of_coordY), &y, sizeof(y), nullptr);
				ReadProcessMemory(init.procHandle, LPCVOID(a + init.of_coordZ), &z, sizeof(z), nullptr);
				
				//if (x < -10000 || x > 10000 || y < -10000 || y > 10000 || z < -10000 || z > 10000) {
				//	continue;
				//}

				// exclude self
				if ((player.coords.x - x > -2 && player.coords.x - x < 2) && (player.coords.y - y > -2 && player.coords.y - y < 2) && (player.coords.z - z > -2 && player.coords.z - z < 2)) {
					continue;
				}
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
		std::cout << i << "cPed Health: " << list[i].cPedHealth << "| Coords: {" << list[i].cPedCoords.x << ", " << list[i].cPedCoords.y << ", " << list[i].cPedCoords.z << "}" << "\n";
		//std::cout << addrList[i] << " " << std::endl;
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