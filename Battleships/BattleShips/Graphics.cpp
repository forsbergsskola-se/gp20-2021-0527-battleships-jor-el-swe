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
		drawRow(letters[i]);
		cout << endl;
	}
}

void Graphics::drawTop() {
	for (int i = 0; i < 10; i++) {
		cout << "   " << i;
	}
}

void Graphics::drawRow(char letter) {
	//TODO make it also print missed shots and hits on ships
	cout << letter;
}


