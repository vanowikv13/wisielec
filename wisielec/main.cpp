// wisielec.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MENU.h"


int main(){
	MENU::resizeCon(MENU::Size::NORMAL);
	MENU::setTheme(MENU::Theme::DARK);
	MENU m;
    return 0;
}

