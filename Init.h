#pragma once
#include <Windows.h>

//typedef uint64_t QWORD;

class Init
{

public:
	LPCSTR winName = "Grand Theft Auto V";
	const char* procName = "GTA5.exe";
	// About game system
	DWORD PID = 0;
	HANDLE procHandle = 0;
	DWORD moduleBase = 0;//0x7FF601D90000;	// "GTA5.exe"
	DWORD moduleSize = 0;

	// BaseAddress
	DWORD playerBaseAddress = 0x0;
	DWORD pInstGtaBaseAddress = 0x0;
	DWORD gangCpedEntityListBaseAddress = 0x0;

	// Offset of Player and cPed
	DWORD of_playerBaseAddress = 0x1C76E78;				// off gta5.exe	
	DWORD of_health = 0x280;							// off player
	DWORD of_name = { 0x225 };							// ?
	DWORD of_coordX = { 0x90 };							// off player
	DWORD of_coordY = { 0x94 };							// off player
	DWORD of_coordZ = { 0x98 };							// off player
	DWORD of_OperetableCoordX = { 0x50 };				// off pInstGtaBaseAddress
	DWORD of_OperetableCoordY = { 0x54 };				// off pInstGtaBaseAddress
	DWORD of_OperetableCoordZ = { 0x58 };				// off pInstGtaBaseAddress
	DWORD of_gangCped = 0x24D6108;						// off gta.exe
	DWORD of_ang_left_right = { 0x40 };					// ?
	DWORD of_ang_up_down = { 0x44 };					// ?
	DWORD of_team = 0x32C;								// ?
	DWORD of_viewmatrix = 0x501AE8;						// ?
	DWORD of_posx_normal = 0x34;						// ?
	DWORD of_posy_normal = 0x38;						// ?
	DWORD of_posz_normal = 0x3C;						// ?

	void GetPID();

	void GetProcHandle();

	void GetModuleInfo();

	void GenerateBaseAddress();

	void Print();

	template <class T>
	T Read(LPCVOID address)
	{
		T VALUE;
		//ReadProcessMemory(processHandle, (LPCVOID)(address), &VALUE, sizeof(T), 0);
		return VALUE;
	}
};