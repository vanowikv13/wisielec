#pragma once
#ifndef OPTIONS_H
#define OPTIONS_H
#include <iostream>
#include <windows.h>
#include <vector>
#include "CONTROLKey.h"


class OPTIONS {
public:
	enum class  Theme { DARK, LIGHT };
	enum class Size { SMALL, NORMAL, BIG};
	static void setTheme(Theme thm);
	static void resizeCon(Size size);
	static void resize(int x, int y, UINT fontFamily, UINT fontWeight);
	void optionsGame();
	void resizeConsole();
	CONTROLKey conk;
};



#endif // ! OPTIONS_H