#include <iostream>
#include "Init.h"
#include "Self.h"
#include "Entities.h"
#include "Mathematics.h"
#include "Draw.h"

Init init;
int main()
{
	// initialize
	init.GetPID();
	init.GetProcHandle();
	init.Print();

	// get self info
	Self self(init);
	self.GetBasicInfo();
	self.GetDynamicInfo();
	self.Print();
	
	// get entities info
	Entities entities(init);
	entities.GetHeistListInfo(self);
	//entities.GetPlayerListInfo(self);
	entities.LoopList();
	
	Mathematics math(init);
	Draw draw(init);
	ShowWindow(FindWindowA("ConsoleWindowClass", NULL), true);
	draw.TargetWnd = FindWindow(0, init.winName);
	//draw.TargetWnd = FindWindow(0, init.winTest);
	draw.HDC_Desktop = GetDC(draw.TargetWnd);
	draw.SetupDrawing(draw.HDC_Desktop, draw.TargetWnd);
	draw.esp(entities, self, math);
	std::cout << "Exited";
	return 0;
}

