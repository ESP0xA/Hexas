#pragma once
#include <Windows.h>

typedef uintptr_t QWORD;


class Init
{

public:
	LPCSTR winName = "Grand Theft Auto V";
	const char* procName = "GTA5.exe";
	// About game system
	DWORD PID = 0;
	HANDLE procHandle = 0;
	QWORD moduleBase = 0x7FF60A8F0000;	// "GTA5.exe"
	QWORD moduleSize = 0;

	// BaseAddress
	QWORD playerBaseAddress = 0x0;
	QWORD pInstGtaBaseAddress = 0x0;
	QWORD gangCpedEntityListBaseAddress = 0x0;

	// Offset of Player and cPed
	QWORD of_playerBaseAddress = 0x1C76E78;				// off gta5.exe	
	QWORD of_health = 0x280;							// off player
	QWORD of_name = { 0x225 };							// ?
	QWORD of_coordX = { 0x90 };							// off player
	QWORD of_coordY = { 0x94 };							// off player
	QWORD of_coordZ = { 0x98 };							// off player
	QWORD of_OperetableCoordX = { 0x50 };				// off pInstGtaBaseAddress
	QWORD of_OperetableCoordY = { 0x54 };				// off pInstGtaBaseAddress
	QWORD of_OperetableCoordZ = { 0x58 };				// off pInstGtaBaseAddress
	QWORD of_gangCped = 0x24D6108;						// off gta.exe
	QWORD of_ang_left_right = { 0x40 };					// ?
	QWORD of_ang_up_down = { 0x44 };					// ?
	QWORD of_team = 0x32C;								// ?
	//QWORD of_viewmatrix = 0x501AE8;						// ?
	QWORD of_viewmatrix = 0x7FF60C85E250;
	QWORD of_posx_normal = 0x34;						// ?
	QWORD of_posy_normal = 0x38;						// ?
	QWORD of_posz_normal = 0x3C;						// ?

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