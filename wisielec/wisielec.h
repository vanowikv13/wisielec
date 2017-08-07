#ifndef WISIELEC_H
#define WISIELEC_H
#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

class wisielec
{
public:
	wisielec(std::string cat,std::string passwd);
	~wisielec();
	//gmeloop in wisielec obj
	bool gameWork();
	//write hangman
	bool writeHangman(int i);
	//set the category and password
	inline void setStrings(std::string s1, std::string s2);
	//check if letter is in the string
	bool checkLetter(char letter);
	//write Map with password
	void writeMap();
	//return true if win return flase if win
	bool checkWin();
	//function return password is for MENU
	inline std::string retPass() { return password; }
private:
	std::string catergory, password;
	std::vector<std::pair<char,bool>> pass;
	int spaces;
};

#endif // !WISIELEC_H