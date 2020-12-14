#include <iostream>
#include "Init.h"
#include "Player.h"
#include "Entities.h"
#include "Mathematics.h"
#include "Draw.h"

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
	entities.GetListInfo();
	//entities.LoopList();
	

	Mathematics math(init);
	Draw draw(init);
	ShowWindow(FindWindowA("ConsoleWindowClass", NULL), true);
	draw.TargetWnd = FindWindow(0, init.winName);
	draw.HDC_Desktop = GetDC(draw.TargetWnd);
	draw.SetupDrawing(draw.HDC_Desktop, draw.TargetWnd);
	draw.esp(entities, player, math);
	std::cout << "sup";
	return 0;
}

