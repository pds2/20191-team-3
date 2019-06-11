#include "color.h"
#include <iostream>
#include <string>
using namespace std;


std::string Color::redPrint(std::string pinta) {
	return red + pinta + reset;
}
std::string Color::bluePrint(string pinta) {
	return blue + pinta + reset;
}

std::string Color::greenPrint(string pinta) {
	return green + pinta + reset;
}

std::string Color::whitePrint(string pinta) {
	return white + pinta + reset;
}

std::string Color::yellowPrint(string pinta){
	return yellow + pinta + reset;
}

std::string Color::BbluePrint(std::string pinta){
	return Bblue + pinta + reset;
}

