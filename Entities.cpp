#include <Windows.h>
#include <vector>
#include <iostream>
#include "Entities.h"
#include "Init.h"


void Entities::GetInfo()
{
	//read 1st cped address;
	QWORD cPedAddr = 0x000000000000;
	QWORD of_cPed = init.of_gangCped;
	for (int i = 0; i < 30; i++, of_cPed += 0x28) {
		Entity ent;
		ReadProcessMemory(init.procHandle, (LPCVOID)(init.moduleBase + of_cPed), &cPedAddr, sizeof(cPedAddr), nullptr);
		if (cPedAddr) { // address not 0
			ReadProcessMemory(init.procHandle, LPCVOID(cPedAddr + init.of_health), &ent.cPedHealth, sizeof(ent.cPedHealth), nullptr);
			if (!ent.cPedHealth) // health is 0
				continue;
			else // good cped
				addrList.push_back(cPedAddr);
		}
		// judge if health > 0
		/*
		if (!ent.cPedHealth) {
			nextCPedAddr += 0x28;
			break;
		}
		else {
			ReadProcessMemory(init.procHandle, LPCVOID(ent.cPedAddreass + init.of_coordX), &ent.cPedCoords.x, sizeof(ent.cPedCoords.x), nullptr);
			ReadProcessMemory(init.procHandle, LPCVOID(ent.cPedAddreass + init.of_coordY), &ent.cPedCoords.y, sizeof(ent.cPedCoords.y), nullptr);
			ReadProcessMemory(init.procHandle, LPCVOID(ent.cPedAddreass + init.of_coordZ), &ent.cPedCoords.z, sizeof(ent.cPedCoords.z), nullptr);
			list.push_back(ent);
			nextCPedAddr += 0x28;
		}
		*/
	}
	//amount = list.size();
	amount = addrList.size();
}

void Entities::LoopList() {
	/*
	for (int i = 0; i < amount; i ++) {
		std::cout << "cPed Address: " << std::hex << list[i].cPedAddreass << std::endl;
		std::cout << "cPed Health: " << list[i].cPedHealth << std::endl;
		std::cout << "cPed Coords: {" << list[i].cPedCoords.x << ", " << list[i].cPedCoords.y << ", " << list[i].cPedCoords.z << "}" << std::endl;
	}
	*/
	for (int i = 0; i < amount; i++) {
		std::cout << "cPed Address: " << std::hex << addrList[i] << "\n";
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