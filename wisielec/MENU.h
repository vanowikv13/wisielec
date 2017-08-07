#pragma once
#ifndef  MENU_H
#define MENU_H
#include <map>
#include <iostream>
#include <windows.h>
#include <string>
#include <vector>
#include "CONTROLKey.h"
#include "wisielec.h"
#include "err.h"

using Map = std::map<std::string, std::vector<std::string>>;
using PSS = std::pair<std::string, std::string>;

class MENU
{
public:
	//option on menu
	void gameLoop();
	//start the game
	bool play();
	//gameOption
	void optionsGame();
	//download from file
	void downloadFromFileIntoContainter() noexcept;
	//
	void resizeConsole();

	MENU();
	~MENU();

protected:
	Map words;
	wisielec * w;
	CONTROLKey<std::string> conk;

	//resize console window
	static void MENU::resize(int x, int y, UINT fontFamily, UINT fontWeight);
	//return password
	PSS random();

public:
	enum class  Theme { DARK, LIGHT };
	enum class Size{SMALL,NORMAL,BIG,OWN};
	static void setTheme(Theme thm);
	static void resizeCon(Size size);
};

#endif // ! MENU_Ha