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
		MessageBox(HWND(), er.msg.c_str(), nullptr, MB_OK);
	}
	catch (...) {
		MessageBox(HWND(), L"Jakis problem", L"no i fajnie", MB_OK);
	}

	gameLoop();
}


MENU::~MENU()
{

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

		case 1:	
			consoleOptions.optionsGame();
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


void MENU::downloadFromFileIntoContainter() noexcept {
	std::fstream file;
	std::string line; std::string cat;
	file.open("wisielec.txt", std::ios::in);
	if (!file.is_open())throw err(L"Wrong download from file");
	while (std::getline(file, line)) {
		if (line.substr(1, 1)[0] == ')')
			words[(cat = line.substr(2, line.size()))] = std::vector<std::string>();
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
