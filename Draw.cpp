#include "Draw.h"
#include <sstream>
#include <iostream>
#pragma warning(disable : 4996) // disable strcopy (overflow)
#pragma warning(disable : 4244) // disable loss of data conversion

void Draw::SetupDrawing(HDC hDesktop, HWND handle)
{
	Draw::HDC_Desktop = hDesktop;
	Draw::Handle = handle;
	TextCOLOR = RGB(255, 0, 0);
}

void Draw::DrawFilledRect(int x, int y, int w, int h, HBRUSH brushColor)
{
	RECT rect = { x,y,x + w,y + h };
	FillRect(Draw::HDC_Desktop, &rect, brushColor);
}

void Draw::DrawBorderBox(int x, int y, int w, int h, int thickness, HBRUSH brushColor)
{
	DrawFilledRect(x, y, w, thickness, brushColor);
	DrawFilledRect(x, y, thickness, h, brushColor);
	DrawFilledRect((x + w), y, thickness, h, brushColor);
	DrawFilledRect(x, y + h, w + thickness, thickness, brushColor);
}

void Draw::DrawString(int x, int y, COLORREF color, const char* text)
{
	SetTextAlign(Draw::HDC_Desktop, TA_CENTER | TA_NOUPDATECP);
	SetBkColor(Draw::HDC_Desktop, RGB(0, 0, 0));
	SetBkMode(Draw::HDC_Desktop, TRANSPARENT);
	SetTextColor(Draw::HDC_Desktop, color);
	SelectObject(Draw::HDC_Desktop, Draw::Font);
	TextOutA(Draw::HDC_Desktop, x, y, text, strlen(text));
	DeleteObject(Font);
}

void Draw::DrawLine(int startX, int startY, int endX, int endY, COLORREF Pen)
{
	int a, b = 0;
	HPEN hOPen;
	// penstyle, width, color
	HPEN hNPen = CreatePen(PS_SOLID, 2, Pen);
	hOPen = (HPEN)SelectObject(HDC_Desktop, hNPen);
	// starting point of line
	MoveToEx(HDC_Desktop, startX, startY, NULL);
	// ending point of line
	a = LineTo(HDC_Desktop, endX, endY);
	DeleteObject(SelectObject(HDC_Desktop, hOPen));
}

void Draw::DrawESP(int x, int y, float distance, int health, const char* name, HBRUSH hBrush, COLORREF Pen)
{
	int width = 400 / distance;	//18100, 1100

	int height = 1000 / distance;	//36000, 2000

	DrawBorderBox(x - (width / 2), y - height, width, height, 3, hBrush);

	std::stringstream ss;
	ss << std::to_string((int)distance) + " meters"; 

	std::stringstream dd;
	dd << std::to_string(health) + " HP";

	std::stringstream nn;
	nn << name;

	char* distanceInfo = new char[ss.str().size() + 1];
	strcpy(distanceInfo, ss.str().c_str());

	char* healthInfo = new char[dd.str().size() + 3];
	strcpy(healthInfo, dd.str().c_str());

	char* nameInfo = new char[nn.str().size() + 3];
	strcpy(nameInfo, nn.str().c_str());

	DrawString(x, y, Draw::TextCOLOR, nameInfo);
	DrawString(x, y + 15, Draw::TextCOLOR, distanceInfo);
	DrawString(x, y + 30, Draw::TextCOLOR, healthInfo);

	delete[] distanceInfo;
	delete[] healthInfo;
}


DWORD WINAPI Draw::esp(Entities entities, Self self, Mathematics math)
{
	GetWindowRect(FindWindow(NULL, init.winName), &m_Rect);
	//GetWindowRect(FindWindow(NULL, init.winTest), &m_Rect);
	while (true)
	{
		self.GetDynamicInfo();
		entities.GetHeistListInfo(self);
		//entities.GetPlayerListInfo(self);
		std::cout << std::dec<< entities.amount << std::endl;
		for (int i = 0; i < entities.amount; i++)
		{
			if (math.WorldToScreen(entities.list[i].cPedCoords, math.screen, self.matrix, init.width, init.height) && entities.list[i].cPedHealth > 0)
			{
				Draw::DrawESP(math.screen.x, math.screen.y, math.GetDistance3D(self.coords, entities.list[i].cPedCoords), entities.list[i].cPedHealth, "CPed", Draw::hBrushEnemy, Draw::enemyColor);
				Draw::DrawLine(init.width / 2, init.height, math.screen.x, math.screen.y, Draw::enemyColor);
			}
		}
	}
}