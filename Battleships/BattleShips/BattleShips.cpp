// BattleShips.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>
#include <string>
#include "Graphics.h"
#include "Utilities.h"
using namespace std;

int main()
{
    Graphics::initGraphics();
    Graphics::drawGrid();


    int currentPlayer = 0;
   
    ostringstream oss;
    oss << "Player " << currentPlayer << " enter a coordinate (a0, g4, h7 etc...):";
    string instruction = oss.str();

    int arrayPosition = Utilities::ValidateAndTranslatePosition(instruction);

}

