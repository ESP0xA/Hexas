#include <windows.h>
#include <iostream>
#include "Self.h"
#include "Init.h"
#include <cstdint>

void Self::GetBasicInfo()
{
	ReadProcessMemory(init.procHandle, (LPCVOID)(init.moduleBase + init.off_localPlayer), &localPlayerAddr, sizeof(localPlayerAddr), nullptr);
	ReadProcessMemory(init.procHandle, (LPCVOID)(localPlayerAddr + 0x30), &pInstGtaAddr, sizeof(pInstGtaAddr), nullptr);
}

void Self::GetDynamicInfo()
{
	ReadProcessMemory(init.procHandle, (PBYTE*)(init.moduleBase + init.off_viewmatrix), &matrix, sizeof(matrix), nullptr);
	ReadProcessMemory(init.procHandle, (LPCVOID)(localPlayerAddr + init.off_health), &health, sizeof(health), nullptr);
	ReadProcessMemory(init.procHandle, (LPCVOID)(localPlayerAddr + init.off_coordX), &coords.x, sizeof(coords.x), nullptr);
	ReadProcessMemory(init.procHandle, (LPCVOID)(localPlayerAddr + init.off_coordY), &coords.y, sizeof(coords.y), nullptr);
	ReadProcessMemory(init.procHandle, (LPCVOID)(localPlayerAddr + init.off_coordZ), &coords.z, sizeof(coords.z), nullptr);
}


void Self::Print()
{
	std::cout << "=============================" << "\n";
	std::cout << "=========== Self ============" << "\n";
	std::cout << "=============================" << "\n\n";
	std::cout << "LocalPlayerAddy: " << std::hex << localPlayerAddr << std::endl;
	std::cout << "Health: " << health << "\r";
	std::cout << "Position: {" << coords.x << ", " << coords.y << ", " << coords.z << "}\r";
	//for (int i = 0; i < 16; i++) std::cout << matrix[i] << " ";
	std::cout << "\n\n";
}
