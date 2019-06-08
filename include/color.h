#pragma once
#ifndef COLOR_H_
#define COLOR_H_
#include <string>

class Color {
private:
	string red = "\033[1;31m";
	string bue = "\033[1;34m";
	string green = "\033[1;32m";
	string white = "\033[1;37m";
	string yellow = "\033[1;33m";
	string reset = "\033[0m";
	
public:
	void redPrint(string pinta);
	void bluePrint(string pinta);
	void greenPrint(string pinta);
	void whitePrint(string pinta);
	void yellowPrint(string pinta);

};
#endif // !COLOR_H_

