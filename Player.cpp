#include <windows.h>
#include <iostream>
#include "Player.h"
#include "Init.h"
#include <cstdint>

void Player::GetInfo()
{
	ReadProcessMemory(init.procHandle, (PBYTE*)(init.moduleBase + init.of_viewmatrix), &matrix, sizeof(matrix), nullptr);
	ReadProcessMemory(init.procHandle, (LPCVOID)(init.playerBaseAddress + init.of_health), &health, sizeof(health), nullptr);
	ReadProcessMemory(init.procHandle, (LPCVOID)(init.playerBaseAddress + init.of_coordX), &coords.x, sizeof(coords.x), nullptr);
	ReadProcessMemory(init.procHandle, (LPCVOID)(init.playerBaseAddress + init.of_coordY), &coords.y, sizeof(coords.y), nullptr);
	ReadProcessMemory(init.procHandle, (LPCVOID)(init.playerBaseAddress + init.of_coordZ), &coords.z, sizeof(coords.z), nullptr);
}

void Player::Print()
{
	//std::cout << "=============================" << "\n";
	//std::cout << "========== Player ===========" << "\n";
	//std::cout << "=============================" << "\n\n";
	std::cout << "Health: " << health << "\r";
	std::cout << "Position: {" << coords.x << ", " << coords.y << ", " << coords.z << "}\r";
	for (int i = 0; i < 16; i++) std::cout << matrix[i] << " ";
	std::cout << "\n\n";
}
