#include "Graphics.h"
#include "PlayingField.h"
#include <iostream>

using namespace std;

void Graphics::initGraphics(void)
{
	cout << GREEN;
	system("CLS");
	//fullscreen
	system("mode 650");
}

void Graphics::drawGrid(PlayingField p1,PlayingField p2)
{
	const string letters = "abcdefghij";
	cout << " ";
	drawTop();
	drawTop();
	cout << endl;

	char row1[10], row2[10];
	for (int i = 0; i < letters.length(); i++) {
		p1.getRowNumber(i, row1);
		p2.getRowNumber(i, row2);

		drawRow(letters[i], row1, row2);
		cout << endl;
	}
}

void Graphics::drawTop() {
	for (int i = 0; i < 10; i++) {
		cout << "   " << i;
	}
}

void Graphics::drawRow(char letter, char* r1, char* r2) {
	//TODO make it also print missed shots and hits on ships
	cout << letter;

	for (int i = 0; i < 10; i++) {
		cout << "   " << r1[i];
	}

	for (int i = 0; i < 10; i++) {
		cout << "   " << r2[i];
	}
}


