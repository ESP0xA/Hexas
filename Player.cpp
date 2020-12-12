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

	/*

	ReadProcessMemory(winFunc.processHandle, (LPCVOID)(base + of_team), &team, sizeof(team), nullptr);
	ReadProcessMemory(winFunc.processHandle, (LPCVOID)(base + of_posx_normal), &position_feet.x, sizeof(position_feet.x), nullptr);
	ReadProcessMemory(winFunc.processHandle, (LPCVOID)(base + of_posy_normal), &position_feet.y, sizeof(position_feet.y), nullptr);
	ReadProcessMemory(winFunc.processHandle, (LPCVOID)(base + of_posz_normal), &position_feet.z, sizeof(position_feet.z), nullptr);
	ReadProcessMemory(winFunc.processHandle, (PBYTE*)(of_viewmatrix), &matrix, sizeof(matrix), nullptr);
	*/
}

void Player::Print()
{
	std::cout << "=============================" << "\n";
	std::cout << "========== Player ===========" << "\n";
	std::cout << "=============================" << "\n\n";
	std::cout << "Health: " << health << "\n";
	std::cout << "Position: {" << coords.x << ", " << coords.y << ", " << coords.z << "}\n";

	std::cout << "\n\n";
}
