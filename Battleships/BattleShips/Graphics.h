#pragma once
#include "PlayingField.h"
constexpr auto GREEN = "\033[32m";

class Graphics
{
public:
	static void drawGrid(PlayingField, PlayingField);
	static void initGraphics(void);

private: 
	static void drawTop(void);
	static void drawRow(char, char*,char*);
};

