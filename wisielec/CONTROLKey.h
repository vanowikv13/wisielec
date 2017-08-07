#pragma once
#ifndef CONTROLKey_H
#define CONTORLKek_H
#include <iostream>
#include <vector>
#include <string>
#include <conio.h>

template<typename T>
class CONTROLKey {
public:

	CONTROLKey(std::vector<T> options,std::string mes="") {
		initialization(&options, mes);
	}

	CONTROLKey() {
		initialization();
	}
	CONTROLKey(std::initializer_list<T> inilist, std::string mes = "") {
		std::vector<T> vec(inilist);
		initialization(&vec, mes);
	}

	void operator()(std::initializer_list<T> inilist,std::string mes = "") {
		std::vector<T> vec(inilist);
		initialization(&vec,mes);
	}

	void operator()(std::vector<T> vec, std::string mes = "") {
		initialization(&vec, mes);
	}

	void setMessage(std::string mes) {
		message = mes;
	}

	int keyOptionWork() {
		index = 0, x = 0; a = 0;
		do {
			system("cls");
			writeMess();

			for (a = 0; a <= words.size() -1;a++) {
				if (a == index)
					std::cout << " + ";
				else std::cout << "   ";
				std::cout << words[a] << std::endl;
			}
			x = _getch();
			controlKey(x);
		} while (x != 13);

		return index;
	}

	void setStartIndex(int StartIndex) {
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

	void writeMess() {
		if (message.size() > 0)
			std::cout << message << std::endl;
	}
	void initialization(std::vector<T> *options = nullptr, std::string mes = "") {
		words = *options;
		message = mes;
		index = 0; x = 0;  a = 0;
		min = 0; max = options->size() - 1;
		startIndex = 0;
	}

	~CONTROLKey() {}

protected:
	std::vector<T> words;
	int index, min, max, x ,a , startIndex;
	std::string message;
};

#endif // !CONTROLKey_H