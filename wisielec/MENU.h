#ifndef  MENU_H
#define MENU_H

#include <map>
#include <iostream>
#include "wisielec.h"
#include <string>

using Map = std::map<std::string, std::string>;

class MENU
{
public:
	//option on menu
	void gameLoop();
	//start the game
	void play();
	//gameOption
	void optionGame();
	//download from file
	bool downloadFromFileIntoContainter();
	//chose option game like change color itp
	void option();
	//exit the game
	bool exit();
	MENU();
	~MENU();

protected:
	//map for words from file
	Map *words;
	enum class  Theme {DARK,LIGHT};
};

#endif // ! MENU_H