#include <iostream>
#include <string>
#include "PlayingField.h"
#include "Utilities.h"

using namespace std;


void PlayingField::init(void)
{
	for (int i = 0; i < sizeof(grid) / sizeof(char); i++) {
		grid[i] = '?';
	}
}

void PlayingField::getRowNumber(int rowNumber, char* row)
{
	for (int i = 0; i < 10; i++) {
		row[i] = grid[i + rowNumber * 10];
	}
}

bool PlayingField::setShipAtPosition(int position, int value)
{
	if(grid[position]!='?')
		return false;

	grid[position] = (char)value + ZERO;
	return true;
}

void PlayingField::markPositionWithCharacter(int position, char c)
{
	grid[position] = c;
}
