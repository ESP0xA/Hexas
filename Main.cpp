#include <iostream>
#include "Init.h"
#include "Player.h"
#include "Entities.h"

Init init;
int main()
{
	// initialize
	init.GetPID();
	init.GetProcHandle();
	init.GenerateBaseAddress();
	init.Print();

	// get player info
	Player player(init);
	player.GetInfo();
	player.Print();
	
	// get entities info
	Entities entities(init);
	while (1) {
		entities.GetListInfo();
		entities.LoopList();
		Sleep(200);
	}
	
	for (;;) {
		
		Sleep(1000);
	}
	//entities.Print();

	/*
	Mathematics math(win);

	Draw draw(win);

	ShowWindow(FindWindowA("ConsoleWindowClass", NULL), true);
	draw.TargetWnd = FindWindow(0, "AssaultCube");
	draw.HDC_Desktop = GetDC(draw.TargetWnd);
	draw.SetupDrawing(draw.HDC_Desktop, draw.TargetWnd);

	draw.esp(entities, player, math);

	std::cout << "sup";
	*/
	return 0;
}

