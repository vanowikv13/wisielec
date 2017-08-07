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
	MENU();
	~MENU();

protected:
	Map words;
	wisielec * w;
	CONTROLKey conk;

public:
	enum class  Theme { DARK, LIGHT };
	static void setTheme(Theme thm);
};

#endif // ! MENU_Ha