#pragma once
#include <iostream>
#include "PlayingField.h"
constexpr auto GREEN = "\033[32m";
using namespace std;

class Graphics
{
public:
	static void drawGrid(PlayingField, PlayingField);
	static void initGraphics(void);
	static void clearScreen(void) {
		system("CLS");
	}

	static void waitForKey(void) {
		system("pause");
	}

private: 
	static void drawTop(void);
	static void drawRow(char, char*,char*);
};

