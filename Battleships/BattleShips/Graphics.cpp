#include "Graphics.h"
#include <iostream>

using namespace std;

void Graphics::initGraphics(void)
{
	cout << GREEN;
	system("CLS");
	//fullscreen
	system("mode 650");
}

void Graphics::drawGrid(void)
{
	cout << "drawing grid";
}


