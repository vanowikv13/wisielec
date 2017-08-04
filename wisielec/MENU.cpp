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

void MENU::gameLoop() {
	int a = 0,x = 0, index = 0; std::vector<std::string> tab = { "1.START","2.OPTIONS","3.EXIT" };
	while (true)
	{

		do {
			system("cls");
			for (auto it = tab.begin(); it < tab.end(); it++, a++) {
				if (index == a)
					std::cout << "+";
				else std::cout << " ";
				std::cout << *it << std::endl;
			}
			x = _getch();
			if (a > 2)
				a = 0;
			index = controlKey(0, 2, 0, 2, index, x);
		} while (x != 13);
		if (x == 13) {
			switch (index) {
			case 0:	
				if (play())

					std::cout << "You WIN!!!!" << std::endl;
				else
					std::cout << "You don't win :(" << std::endl; 
				break;
			case 1:	optionsGame();	break; ///setings
			case 2:
				index = 1;
				do {
					system("cls");
					std::cout << "are want exit the game" << std::endl;
					if (index == 0) {
						std::cout << " + YES" << std::endl;
						std::cout << "   NO" << std::endl;
					}
					else {
						std::cout << "   YES" << std::endl;
						std::cout << " + NO" << std::endl;
					}
					x = _getch();
					index = controlKey(0, 1, 0, 1, index, x);
				} while (x != 13);
				if (index)
					break;
				else std::exit(1);
			}
		}
	}


}

bool MENU::play() {
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

	w = new wisielec(pi.first, pi.second[numb]);
	return w->gameWork();
}

void MENU::optionsGame() {

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

void MENU::options() {

}

bool exit() {
	return false;
}

