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
	const string letters = "abcdefghij";
	drawTop();
	drawTop();
	cout << endl;

	for (int i = 0; i < letters.length()+1; i++) {
		cout << letters[i] << endl;
	}
}

void Graphics::drawTop() {
	for (int i = 1; i < 11; i++) {
		cout << "   " << i << "   ";
	}
}


