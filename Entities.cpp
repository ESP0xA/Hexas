#include <Windows.h>
#include <vector>
#include <iostream>
#include "Entities.h"
#include "Init.h"


void Entities::GetHeistListInfo(Self self)
{
	/*
	* a: temp cped address
	* h: temp cped health
	* x, y, z: temp cped coords
	*/
	list = {}; // init list
	QWORD a = 0x000000000000;
	QWORD off_cPed = init.off_heistCpedList;
	DWORD offsetOfEachCPed = 0x28;  //0x10(bogdan)
	for (int i = 0; i < 175; i++, off_cPed += offsetOfEachCPed) {
		Entity ent;
		float h = 0;
		float x, y, z = 0;
		ReadProcessMemory(init.procHandle, (LPCVOID)(init.moduleBase + off_cPed), &a, sizeof(a), nullptr);
		if (a) { // address not 0
			ReadProcessMemory(init.procHandle, LPCVOID(a + init.off_health), &h, sizeof(h), nullptr);
			if (h != h || !h) {
				continue;// health 
			}
			else {	 // good cped
				ReadProcessMemory(init.procHandle, LPCVOID(a + init.off_coordX), &x, sizeof(x), nullptr);
				ReadProcessMemory(init.procHandle, LPCVOID(a + init.off_coordY), &y, sizeof(y), nullptr);
				ReadProcessMemory(init.procHandle, LPCVOID(a + init.off_coordZ), &z, sizeof(z), nullptr);
				// exlude self
				self.GetDynamicInfo();
				if ((self.coords.x - x > -0.005 && self.coords.x - x < 0.005) && (self.coords.y - y > -0.005 && self.coords.y - y < 0.005) && (self.coords.z - z > -0.005 && self.coords.z - z < 0.005)) {
					continue;
				}
				ent.cPedAddr = a;
				ent.cPedHealth = h;
				ent.cPedCoords.x = x, ent.cPedCoords.y = y, ent.cPedCoords.z = z;
				list.push_back(ent);
			}
		}
	}
	amount = list.size();
}

void Entities::GetGangListInfo()
{
	/*
	* a: temp cped address
	* h: temp cped health
	* x, y, z: temp cped coords
	*/
	list = {}; // init list
	QWORD a = 0x000000000000;
	QWORD off_cPed = init.off_gangCpedList;
	DWORD offsetOfEachCPed = 0x28;
	for (int i = 0; i < 64; i++, off_cPed += offsetOfEachCPed) {
		Entity ent;
		float h = 0;
		float x, y, z = 0;
		ReadProcessMemory(init.procHandle, (LPCVOID)(init.moduleBase + off_cPed), &a, sizeof(a), nullptr);
		if (a) { // address not 0
			ReadProcessMemory(init.procHandle, LPCVOID(a + init.off_health), &h, sizeof(h), nullptr);
			if (h != h || h < 1 || h > 1000) {
				continue;// health 
			}
			else {	 // good cped
				ReadProcessMemory(init.procHandle, LPCVOID(a + init.off_coordX), &x, sizeof(x), nullptr);
				ReadProcessMemory(init.procHandle, LPCVOID(a + init.off_coordY), &y, sizeof(y), nullptr);
				ReadProcessMemory(init.procHandle, LPCVOID(a + init.off_coordZ), &z, sizeof(z), nullptr);
				ent.cPedAddr = a;
				ent.cPedHealth = h;
				ent.cPedCoords.x = x, ent.cPedCoords.y = y, ent.cPedCoords.z = z;
				list.push_back(ent);
			}
		}
	}
	amount = list.size();
}

void Entities::GetPlayerListInfo(Self self)
{
	/*
	* a: temp cped address
	* h: temp cped health
	* x, y, z: temp cped coords
	 */
	list = {}; // init list
	QWORD a = 0x000000000000;
	QWORD offCPed = init.off_globalPlayerList;
	DWORD offsetOfEachCPed = 0xc0;
	for (int i = 0; i < 64; i++, offCPed += offsetOfEachCPed) {
		Entity ent;
		float h = 0;
		float x, y, z = 0;
		ReadProcessMemory(init.procHandle, (LPCVOID)(init.moduleBase + offCPed), &a, sizeof(a), nullptr);
		//if (a) addrList.push_back(a);
		if (a) { // address not 0
			ReadProcessMemory(init.procHandle, LPCVOID(a + init.off_health), &h, sizeof(h), nullptr);
			if (h != h || h < 1 || h > 1000 || h == 150 || h == 175) {
				continue;
			}
			else {	 // good player
				// exclude self
				//player.GetInfo();
				//if (player.health - h > -1 && player.health - h < 1) continue;

				ReadProcessMemory(init.procHandle, LPCVOID(a + init.off_coordX), &x, sizeof(x), nullptr);
				ReadProcessMemory(init.procHandle, LPCVOID(a + init.off_coordY), &y, sizeof(y), nullptr);
				ReadProcessMemory(init.procHandle, LPCVOID(a + init.off_coordZ), &z, sizeof(z), nullptr);
				
				//if (x < -10000 || x > 10000 || y < -10000 || y > 10000 || z < -10000 || z > 10000) {
				//	continue;
				//}

				// exclude self
				self.GetDynamicInfo();
				if ((self.coords.x - x > -2 && self.coords.x - x < 2) && (self.coords.y - y > -2 && self.coords.y - y < 2) && (self.coords.z - z > -2 && self.coords.z - z < 2)) {
					continue;
				}
				ent.cPedAddr = a;
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