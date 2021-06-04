// BattleShips.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>
#include <string>
#include "Graphics.h"
#include "Utilities.h"
#include "PlayingField.h"

using namespace std;

int main()
{
    int currentPlayer = 0;
    PlayingField player1Field;
    PlayingField player2Field;


    player1Field.init();
    player2Field.init();
    Graphics::initGraphics();
    Graphics::drawGrid(player1Field, player2Field);



    ostringstream oss;
    oss << "Player " << currentPlayer << " enter a coordinate (a0, g4, h7 etc...):";
    string instruction = oss.str();

    int arrayPosition = Utilities::ValidateAndTranslatePosition(instruction);

}

