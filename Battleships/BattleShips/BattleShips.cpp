// BattleShips.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>
#include <string>
#include "Graphics.h"
#include "Utilities.h"
#include "PlayingField.h"
#include "Ship.h"

using namespace std;

void enterShips(PlayingField& pfieldOpen,PlayingField& pfieldHidden, Ship* ships, int playerId) {
 
    for (int i = 0; i < 5;i++) {
        
        ostringstream oss;
        cout << "player " << playerId +1<< " enter position for ship number " << i+1 << "(a3,g6,h7...):";
        string instruction = oss.str();
        int arrayPosition = 0;
        do {
            arrayPosition = Utilities::ValidateAndTranslatePosition(instruction);
        } while (!pfieldOpen.setShipAtPosition(arrayPosition, i+1));
            
        ships[i].setPosition(arrayPosition);
        Graphics::drawGrid(pfieldOpen, pfieldHidden);
    }

}

int main()
{
    int currentPlayer = 0;
    PlayingField player1FieldHidden;
    PlayingField player2FieldHidden;
    PlayingField player1FieldOpen;
    PlayingField player2FieldOpen;

    Ship player1Ships[5];
    Ship player2Ships[5];


    player1FieldHidden.init();
    player2FieldHidden.init();
    player1FieldOpen.init();
    player2FieldOpen.init();
    Graphics::initGraphics();
    Graphics::drawGrid(player1FieldHidden, player2FieldHidden);

    enterShips(player1FieldOpen, player2FieldHidden, player1Ships, currentPlayer);
    currentPlayer++;
    enterShips(player2FieldOpen, player1FieldHidden, player2Ships, currentPlayer);
    currentPlayer = 0;

    ostringstream oss;
    oss << "Player " << currentPlayer << " enter a coordinate (a0, g4, h7 etc...):";
    string instruction = oss.str();

    int arrayPosition = Utilities::ValidateAndTranslatePosition(instruction);

}




