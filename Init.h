#pragma once
#include <Windows.h>

typedef uintptr_t QWORD;


class Init
{

public:
	LPCSTR winName = "Grand Theft Auto V";
	LPCSTR winTest = "new 1 - Notepad++";
	const char* procName = "GTA5.exe";

	int width = 2560;
	int height = 1440;
	// About game system
	DWORD PID = 0;
	HANDLE procHandle = 0;
	QWORD moduleBase = 0x7FF7EC480000;	// "GTA5.exe"
	QWORD moduleSize = 0;



	// Offset of Player and cPed
	QWORD off_localPlayer = 0x1C923C8;				    // off gta5.exe	
	QWORD off_gangCpedList = 0x24F3408;					// off gta.exe
	QWORD off_bogdanSubCpedList = 0x1FA5320;			// off gta.exe
	QWORD off_heistCpedList = 0x24F3408;				// off gta.exe
	QWORD off_globalPlayerList = 0x24EB520;				// players
	QWORD off_viewmatrix = 0x1F8B140;					//
	QWORD off_health = 0x280;							// off entity
	QWORD off_coordX = { 0x90 };						// off entity
	QWORD off_coordY = { 0x94 };						// off entity
	QWORD off_coordZ = { 0x98 };						// off entity
	QWORD off_operetableCoordX = { 0x50 };				// off pInstGtaAddy
	QWORD off_operetableCoordY = { 0x54 };				// off pInstGtaAddy
	QWORD off_operetableCoordZ = { 0x58 };				// off pInstGtaAddy


	void GetPID();

	void GetProcHandle();

	void GetModuleInfo();

	void Print();

	template <class T>
	T Read(LPCVOID address)
	{
		T VALUE;
		//ReadProcessMemory(processHandle, (LPCVOID)(address), &VALUE, sizeof(T), 0);
		return VALUE;
	}
};