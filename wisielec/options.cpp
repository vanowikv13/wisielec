#include "stdafx.h"
#include "Options.h"

void OPTIONS::setTheme(Theme thm = Theme::LIGHT)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	switch (thm) {
	case Theme::DARK:
		SetConsoleTextAttribute(hConsole, 15);
		break;
	case Theme::LIGHT:
		SetConsoleTextAttribute(hConsole, 44);
		break;
	default:

		break;
	}
}

void OPTIONS::optionsGame() {
	int index;
	while (true) {
		conk({ "1.Change Color","2.Change Size of Font and console window","3.BACK" }, "OPTIONS");
		index = conk.keyOptionWork();
		switch (index) {
		case 0:
			conk({ "Dzienny","Nocny" }, "Set Theme");
			index = conk.keyOptionWork();
			if (index)
				setTheme(Theme::DARK);
			else
				setTheme(Theme::LIGHT);
			break;
		case 1:
			resizeConsole();
			break;
		case 2:
			return;
		default:
			return;
		}
	}
}


void OPTIONS::resizeConsole() {
	conk({ "SMALL","NORMAL","BIG","OWN" }, "Set Console Size and Font size");
	int index = conk.keyOptionWork();
	switch (index) {
	case 0:
		resizeCon(Size::SMALL);
		break;
	case 1:
		resizeCon(Size::NORMAL);
		break;
	case 2:
		resizeCon(Size::BIG);
		break;
	default:
		resizeCon(Size::NORMAL);
		break;

	}
}

void OPTIONS::resize(int x, int y, UINT fontFamily, UINT fontWeight) {
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = x;                   // Width of each character in the font
	cfi.dwFontSize.Y = y;                  // Height
	cfi.FontFamily = fontFamily;
	cfi.FontWeight = fontWeight;
	std::wcscpy(cfi.FaceName, L"Consolas"); // Choose your font
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}

void OPTIONS::resizeCon(Size size = Size::NORMAL) {
	switch (size) {
	case Size::SMALL:
		resize(0, 8, FF_DECORATIVE, FW_NORMAL);
		break;
	case Size::NORMAL:
		resize(0, 16, FF_DECORATIVE, FW_NORMAL);
		break;
	case Size::BIG:
		resize(0, 24, FF_DECORATIVE, FW_NORMAL);
		break;
	default:
		resize(0, 16, FF_DECORATIVE, FW_NORMAL);
		break;

	}


}

