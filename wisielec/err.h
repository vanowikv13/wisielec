#pragma once
#include <iostream>

class err : public std::runtime_error
{
public:
	err(const std::wstring &msg) : runtime_error("Critical Error!"), msg(msg) {}
	const std::wstring msg;
};