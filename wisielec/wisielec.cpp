#include "stdafx.h"
#include "wisielec.h"

inline unsigned int controlKey(int indexMin, int indexMax, int setIndexMin, int setIndexMax, int index, int x) {
	if (x == 75) index--;
	else if (x == 77) index++;
	else if (x == 72) index--;
	else if (x == 80) index++;
	if (index > indexMax) index = setIndexMin;
	if (index < indexMin) index = setIndexMax;
	return index;
}


wisielec::wisielec(std::string cat, std::string passwd)
{
	setStrings(cat, passwd);
}


wisielec::~wisielec()
{
	pass.clear();
}

bool wisielec::writeHangman(int i) {

	std::vector<std::string> hang = {
		"               \n"
		"               \n"
		"               \n"
		"               \n"
		"               \n"
		"               \n"
		"               \n",
		"               \n"
		"|              \n"
		"|              \n"
		"|              \n"
		"|              \n"
		"|              \n"
		"|              \n",
		"               \n"
		"|             |\n"
		"|             |\n"
		"|             |\n"
		"|             |\n"
		"|             |\n"
		"|             |\n",
		"_______________\n"
		"|             |\n"
		"|             |\n"
		"|             |\n"
		"|             |\n"
		"|             |\n"
		"|             |\n",
		"_______________\n"
		"|_|           |\n"
		"|             |\n"
		"|             |\n"
		"|             |\n"
		"|             |\n"
		"|             |\n",
		"_______________\n"
		"|_|         |_|\n"
		"|             |\n"
		"|             |\n"
		"|             |\n"
		"|             |\n"
		"|             |\n",
		"_______________\n"
		"|_|    |    |_|\n"
		"|      |      |\n"
		"|             |\n"
		"|             |\n"
		"|             |\n"
		"|             |\n",
		"_______________\n"
		"|_|    |    |_|\n"
		"|      |      |\n"
		"|      O      |\n"
		"|             |\n"
		"|             |\n"
		"|             |\n",
		"_______________\n"
		"|_|    |    |_|\n"
		"|      |      |\n"
		"|      O      |\n"
		"|      |      |\n"
		"|      |      |\n"
		"|             |\n",
		"_______________\n"
		"|_|    |    |_|\n"
		"|      |      |\n"
		"|      O/     |\n"
		"|      |      |\n"
		"|      |      |\n"
		"|             |\n",
		"_______________\n"
		"|_|    |    |_|\n"
		"|      |      |\n"
		"|      O/     |\n"
		"|     /|      |\n"
		"|      |      |\n"
		"|             |\n",
		"_______________\n"
		"|_|    |    |_|\n"
		"|      |      |\n"
		"|      O/     |\n"
		"|     /|      |\n"
		"|      |      |\n"
		"|       |     |\n",
		"_______________\n"
		"|_|    |    |_|\n"
		"|      |      |\n"
		"|      O/     |\n"
		"|     /|      |\n"
		"|      |      |\n"
		"|     | |     |\n"

	};

	std::cout << hang[i].c_str() << std::endl;

	if (i == 12)
		return true;
	return false;
}

bool wisielec::gameWork() {

	int interator = 0;
	char x;
	while (interator < 13) {
		std::cout << "category is : " << catergory << std::endl;
		std::cout << "write your letter " << std::endl;
		std::cin >> x;
		system("cls");
		if (!checkLetter(x)) {
			interator++;
			std::cout << "bad letter" << std::endl;
		}
		else {
			std::cout << "good letter" << std::endl;
		}
		writeMap();
		if (writeHangman(interator))
			return false;
		if (checkWin())
			return true;
		
	}

	return false; //if user lose
}

void wisielec::setStrings(std::string s1, std::string s2) {
	catergory = s1;
	password = s2;
	spaces = 0;
	pass.clear();
	for (int i = 0; i < password.size(); i++) {
		pass.push_back(std::pair<char,bool>(password[i], false));
		if (password[i] == ' ')
			spaces++;
	}
	
}

bool wisielec::checkLetter(char letter) {
	bool pas = false;
	for (auto& x : pass) {
		if (letter == x.first || (letter - 32) == x.first || (letter + 32) == x.first) {
			x.second = true;
			pas = true;
		}
	}
	if (pas)
		return true;
	return false;
}

void wisielec::writeMap() {
	for (auto&x : pass)
		if (x.second == true)
			std::cout << x.first;
		else
			if (x.first == ' ')
				std::cout << "   ";
			else
			std::cout << " _ ";
	std::cout << "\n\n";
}

bool wisielec::checkWin() {
	int bo = 0;
	for (auto& a : pass)
		if (a.second == true)
			bo++;

	bo += spaces;
	if (bo == pass.size())
		return true;
	return false;
}