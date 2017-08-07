#include "stdafx.h"
#include "MENU.h"
#include <iomanip>
#include <random>
#include <conio.h>

MENU::MENU()
{
	try {
		downloadFromFileIntoContainter();
	}
	catch (err er) {
		MessageBox(HWND(),er.msg.c_str(),nullptr,MB_OK);
	}
	catch (...) {
		MessageBox(HWND(), L"Jakis problem", L"no i fajnie", MB_OK);
	}

	gameLoop();
}


MENU::~MENU()
{

}

void MENU::setTheme(Theme thm = Theme::LIGHT)
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

void MENU::gameLoop() {
	int index = 0;
	while (true)
	{
		conk({ "1.START","2.OPTIONS","3.EXIT" }, "WELLCOME IN AMAZING GAME");
		index = conk.keyOptionWork();
		switch (index) {
		case 0:
			if (play())
				std::cout << "You WIN!!!!" << std::endl;
			else {
				std::cout << "You don't win :(" << std::endl;
				std::cout << "The answer was : " << w->retPass() << std::endl;
			}
			std::cout << "pers any kind of key to continue ... " << std::endl;
			_getch();
			break;

		case 1:	optionsGame();
			optionsGame();
			break;

		case 2:
			conk({ "YES","NO" }, "Are you want exit the SO MUCH AMAZING GAME REALLY ?");
			index = conk.keyOptionWork();
			if (index)
				break;
			else std::exit(1);
		}
		
	}


}

bool MENU::play() {
	PSS pss = random();
	w = new wisielec(pss.first, pss.second);
	return w->gameWork(); //game stared
}

void MENU::optionsGame() {
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

void MENU::downloadFromFileIntoContainter() noexcept {
	std::fstream file;
	std::string line; std::string cat;
	file.open("wisielec.txt", std::ios::in);
	if (!file.is_open())throw;
	while (std::getline(file, line)) {
		if (line.substr(1, 1)[0] == ')')
			words[(cat = line.substr(2,line.size()))] = std::vector<std::string>();
		else
			words[cat].push_back(line);
	}
}


PSS MENU::random() {
	std::random_device rand;
	std::default_random_engine el(rand());
	std::uniform_int_distribution<int> uniform_dist(0, words.size() - 1);
	int cat = uniform_dist(el);
	int i = 0;
	std::pair<std::string, std::vector<std::string>> pi;
	for (auto&x : words) {
		if (i == cat)
			pi = x;
		i++;
	}
	std::uniform_int_distribution<int> unidist(0, pi.second.size());
	int numb = unidist(el);
	return PSS(pi.first, pi.second[numb]);
}

void MENU::resizeConsole() {
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
	case 3:
		resizeCon(Size::OWN);
		break;
	default:
		resizeCon(Size::NORMAL);
		break;
	
	}
}

void MENU::resizeCon(Size size = Size::NORMAL) {
	switch (size) {
	case Size::SMALL:
		resize(0,8,FF_DECORATIVE,FW_NORMAL);
		break;
	case Size::NORMAL:
		resize(0, 16, FF_DECORATIVE, FW_NORMAL);
		break;
	case Size::BIG:
		resize(0, 24, FF_DECORATIVE, FW_NORMAL);
		break;
	case Size::OWN:
		resize(0, 24, FF_DECORATIVE, FW_NORMAL);
		break;
	default:
		resize(0, 24, FF_DECORATIVE, FW_NORMAL);
		break;

	}


}

void MENU::resize(int x,int y,UINT fontFamily,UINT fontWeight) {
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