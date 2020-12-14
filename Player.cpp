#include <windows.h>
#include <iostream>
#include "Player.h"
#include "Init.h"
#include <cstdint>

void Player::GetInfo()
{
	ReadProcessMemory(init.procHandle, (LPCVOID)(init.playerBaseAddress + init.of_health), &health, sizeof(health), nullptr);
	ReadProcessMemory(init.procHandle, (LPCVOID)(init.playerBaseAddress + init.of_coordX), &coords.x, sizeof(coords.x), nullptr);
	ReadProcessMemory(init.procHandle, (LPCVOID)(init.playerBaseAddress + init.of_coordY), &coords.y, sizeof(coords.y), nullptr);
	ReadProcessMemory(init.procHandle, (LPCVOID)(init.playerBaseAddress + init.of_coordZ), &coords.z, sizeof(coords.z), nullptr);
	ReadProcessMemory(init.procHandle, (PBYTE*)(init.of_viewmatrix), &matrix, sizeof(matrix), nullptr);
}

void Player::Print()
{
	std::cout << "=============================" << "\n";
	std::cout << "========== Player ===========" << "\n";
	std::cout << "=============================" << "\n\n";
	std::cout << "Health: " << health << "\n";
	std::cout << "Position: {" << coords.x << ", " << coords.y << ", " << coords.z << "}\n";
	for (int i = 0; i < 16; i++) std::cout << matrix[i] << " ";
	std::cout << "\n\n";
}
