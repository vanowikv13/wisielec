#pragma once
#ifndef  MENU_H
#define MENU_H
#include <map>
#include <iostream>
#include <string>
#include <vector>
#include "CONTROLKey.h"
#include "wisielec.h"
#include "err.h"
#include "options.h"

using Map = std::map<std::string, std::vector<std::string>>;
using PSS = std::pair<std::string, std::string>;


class MENU
{
public:
	//option on menu
	void gameLoop();
	//start the game
	bool play();
	//download from file
	void downloadFromFileIntoContainter() noexcept;
	MENU();
	~MENU();

protected:
	Map words;
	wisielec * w;
	CONTROLKey conk;
	//resize console window
	static void MENU::resize(int x, int y, UINT fontFamily, UINT fontWeight);
	//return password
	PSS random();
	OPTIONS consoleOptions;
};

#endif // ! MENU_H