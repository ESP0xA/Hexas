#include "Init.h"
#include <iostream>
#include <Psapi.h>


void Init::GetPID() {
	HWND windowHandle = FindWindowA(nullptr, winName);
	GetWindowThreadProcessId(windowHandle, &PID);
}

void Init::GetProcHandle() {
	procHandle = OpenProcess(PROCESS_VM_READ | PROCESS_VM_WRITE, false, PID);
}

// useless
void Init::GetModuleInfo()
{
	//moduleBase = (QWORD)GetModuleBaseAddress(PID, L"GTA5.exe");

	MODULEINFO modInfo = { 0 };
	HMODULE hModule = GetModuleHandleA(procName);
	if (hModule == 0) {
		std::cout << "error" << std::endl;
		return;
	}
	GetModuleInformation(GetCurrentProcess(), hModule, &modInfo, sizeof(MODULEINFO));
	moduleBase = (DWORD)modInfo.lpBaseOfDll;
	moduleSize = (DWORD)modInfo.SizeOfImage;
}


void Init::Print()
{
	std::cout << "=======================================" << std::endl;
	std::cout << "================= HEXAS ===============" << std::endl;
	std::cout << "=======================================" << std::endl;

	std::cout << "PID: " << PID << std::endl;;
	std::cout << "Handle: " << procHandle << std::endl;
	std::cout << "ModuleBase: " << std::hex << moduleBase << std::endl;
}