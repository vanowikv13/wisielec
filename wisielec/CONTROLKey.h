#pragma once
#ifndef CONTROLKey_H
#define CONTORLKek_H
#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include "err.h"

class CONTROLKey {
public:

	inline CONTROLKey(std::vector<std::string> options,std::string mes="") {
		initialization(options, mes);
	}

	inline CONTROLKey() {
		initialization(std::vector<std::string>());
	}
	inline CONTROLKey(std::initializer_list<std::string> inilist, std::string mes = "") {
		std::vector<std::string> vec(inilist);
		initialization(vec, mes);
	}

	inline void operator()(std::initializer_list<std::string> inilist,std::string mes = "") {
		std::vector<std::string> vec(inilist);
		initialization(vec,mes);
	}

	inline void operator()(std::vector<std::string> vec, std::string mes = "") {
		initialization(vec, mes);
	}

	inline void setMessage(std::string mes) {
		message = mes;
	}

	int keyOptionWork() {
		index = 0, x = 0; a = 0;
		do {
			system("cls");
			writeMess();

			for (a = 0; a <= max;a++) {
				if (a == index)
					std::cout << " + ";
				else std::cout << "   ";
				std::cout << words[a] << std::endl;
			}
			x = _getch();
			controlKey(x);
		} while (x != 13);
		if (index <= max)
			return index;
		else
			throw err(L"To big index");
	}

	inline void setStartIndex(int StartIndex) {
		this->startIndex = StartIndex;
	}

	void controlKey(int x) {
		if (x == 75 || x == 72)
			index--;
		else if (x == 77 || x == 80)
			index++;

		if (index > max)
			index = min;
		else if (index < min)
			index = max;
	}

	inline void writeMess() {
		if (message.size() > 0)
			std::cout << message << std::endl;
	}
	void initialization(std::vector<std::string> &options, std::string mes = "") {
		words = options;
		message = mes;
		index = 0; x = 0;  a = 0;
		min = 0; max = options.size() - 1;
		startIndex = 0;
	}

	~CONTROLKey() {}

protected:
	std::vector<std::string> words;
	int index, min, max, x ,a , startIndex;
	std::string message;
};

#endif // !CONTROLKey_H