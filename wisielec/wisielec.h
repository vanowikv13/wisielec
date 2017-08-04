#ifndef WISIELEC_H
#define WISIELEC_H
#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <unordered_map>
#include <fstream>

//for control the game by key
inline unsigned int controlKey(int indexMin, int indexMax, int setIndexMin, int setIndexMax, int index, int x);

class wisielec
{
public:
	wisielec(std::string cat,std::string passwd);
	~wisielec();
	bool gameWork();
	bool writeHangman(int i);
	inline void setStrings(std::string s1, std::string s2);
	bool checkLetter(char letter);
	void writeMap();
	bool checkWin();
private:
	std::string catergory, password;
	std::vector<std::pair<char,bool>> pass;
	int spaces;
};

#endif // !WISIELEC_H