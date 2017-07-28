#ifndef WISIELEC_H
#define WISIELEC_H
#include <map>
#include <string>

class wisielec
{
public:
	wisielec(std::map<std::string,std::string>);
	~wisielec();
	void gameWork();
	bool writeHangman(int i);
	
};

#endif // !WISIELEC_H