#include "color.h"
#include <iostream>
#include <string>
using namespace std;


void Color::redPrint(string pinta) {
	cout << red + pinta + reset << endl;
	return 0;
}
void Color::bluePrint(string pinta) {
	cout << blue + pinta + reset << endl;
	return 0;
}

void Color::greenPrint(string pinta) {
	cout << green + pinta + reset << endl;
	return 0;
}

void Color::whitePrint(string pinta) {
	cout << white + pinta + reset << endl;
	return 0;
}

void Color::yellowPrint(string pinta){
	cout << yellow + pinta + reset << endl;
}