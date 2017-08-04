#ifndef  MENU_H
#define MENU_H

#include <map>
#include <iostream>
#include "wisielec.h"
#include "err.h"
#include <windows.h>
#include <string>
#include <vector>

using Map = std::map<std::string, std::vector<std::string>>;

inline unsigned int controlKey(int indexMin, int indexMax, int setIndexMin, int setIndexMax, int index, int x) {
	if (x == 75) index--;
	else if (x == 77) index++;
	else if (x == 72) index--;
	else if (x == 80) index++;
	if (index > indexMax) index = setIndexMin;
	if (index < indexMin) index = setIndexMax;
	return index;
}

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
	//chose option game like change color itp
	void options();
	//exit the game
	bool exit();
	MENU();
	~MENU();

protected:

	Map words;
	enum class  Theme {DARK,LIGHT};
	wisielec * w;
};

#endif // ! MENU_H