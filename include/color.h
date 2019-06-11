#pragma once
#ifndef COLOR_H_
#define COLOR_H_
#include <string>

class Color {
private:
	std::string red = "\033[1;31m";
	std::string blue = "\033[1;34m";
	std::string green = "\033[32m";
	std::string white = "\033[1;37m";
	std::string yellow = "\033[1;33m";
	std::string reset = "\033[0m";
	std::string Bblue = "\033[7;34m";
	
public:
	std::string redPrint(std::string pinta);
	std::string bluePrint(std::string pinta);
	std::string greenPrint(std::string pinta);
	std::string whitePrint(std::string pinta);
	std::string yellowPrint(std::string pinta);
	std::string BbluePrint(std::string pinta);

};
#endif // !COLOR_H_

