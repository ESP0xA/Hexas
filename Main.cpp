#include <iostream>
#include "Init.h"
#include "Player.h"

Init init;
int main()
{
	init.GetPID();
	init.GetProcHandle();
	init.GenerateBaseAddress();
	init.Print();

	Player player(init);
	player.GetInfo();
	player.Print();
	/*

	Entities entities(init);
	entities.GetInfo();
	entities.Print();


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

