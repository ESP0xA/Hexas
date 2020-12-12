#include <Windows.h>
#include <vector>
#include <iostream>
#include "Entities.h"
#include "Init.h"


void Entities::GetInfo()
{
	//read 1st cped address;
	ReadProcessMemory(init.procHandle, (LPCVOID)(init.moduleBase + init.of_gangCped), &init.gangCpedEntityListBaseAddress, sizeof(init.gangCpedEntityListBaseAddress), nullptr);

	//list[0].cPedAddreass = init.gangCpedEntityListBaseAddress;
	for (int i = 0; ; i ++)
	{
		Entity ent;
		if (!i) {
			ent.cPedAddreass = init.gangCpedEntityListBaseAddress;
		}
		else {
			QWORD possibleCpedAddress = init.gangCpedEntityListBaseAddress + 0x28; // 5 * 0x8, next cped 
			if (!possibleCpedAddress) {
				amount = i;
				break;  // if not cPed
			}
			ent.cPedAddreass = possibleCpedAddress;
		}
		ReadProcessMemory(init.procHandle, LPCVOID(ent.cPedAddreass + init.of_health), &ent.cPedHealth, sizeof(ent.cPedHealth), nullptr);
		ReadProcessMemory(init.procHandle, LPCVOID(ent.cPedAddreass + init.of_coordX), &ent.cPedCoords.x, sizeof(ent.cPedCoords.x), nullptr);
		ReadProcessMemory(init.procHandle, LPCVOID(ent.cPedAddreass + init.of_coordY), &ent.cPedCoords.y, sizeof(ent.cPedCoords.y), nullptr);
		ReadProcessMemory(init.procHandle, LPCVOID(ent.cPedAddreass + init.of_coordZ), &ent.cPedCoords.z, sizeof(ent.cPedCoords.z), nullptr);
	}
}

void Entities::Print()
{
	std::cout << "=============================" << "\n";
	std::cout << "========= Entities ==========" << "\n";
	std::cout << "=============================" << "\n\n";

	std::cout << std::hex << init.gangCpedEntityListBaseAddress << std::endl;
	/*
	for (int i = 1; i < amount; i++)
	{
		list[i].Print();
	}
	*/
	std::cout << "\n\n";
}