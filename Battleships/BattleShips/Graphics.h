#pragma once
constexpr auto GREEN = "\033[32m";

class Graphics
{
public:
	static void drawGrid(void);
	static void initGraphics(void);

private: 
	static void drawTop(void);
	static void drawRow(char letter);
};

