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

int currentPlayer = 0;
PlayingField player1FieldHidden;
PlayingField player2FieldHidden;
PlayingField player1FieldOpen;
PlayingField player2FieldOpen;

Ship player1Ships[5];
Ship player2Ships[5];

void enterShips(PlayingField& pfieldOpen,PlayingField& pfieldHidden, Ship* ships, int playerId) {
 
    for (int i = 0; i < 5;i++) {
        Graphics::clearScreen();
        playerId == 0 ? Graphics::drawGrid(pfieldOpen, pfieldHidden): Graphics::drawGrid(pfieldHidden, pfieldOpen);
        ostringstream oss;
        cout << "player " << playerId +1<< " enter position for ship number " << i+1 << "(a3,g6,h7...):";
        string instruction = oss.str();
        int arrayPosition = 0;
        do {
            arrayPosition = Utilities::ValidateAndTranslatePosition(instruction);
        } while (!pfieldOpen.setShipAtPosition(arrayPosition, i+1));
            
        ships[i].setPosition(arrayPosition);
    }
    Graphics::clearScreen();
    playerId == 0 ? Graphics::drawGrid(pfieldOpen, pfieldHidden) : Graphics::drawGrid(pfieldHidden, pfieldOpen);
    system("pause");
}

void init() {
    player1FieldHidden.init();
    player2FieldHidden.init();
    player1FieldOpen.init();
    player2FieldOpen.init();
    Graphics::initGraphics();
}

void enterShips() {
    enterShips(player1FieldOpen, player2FieldHidden, player1Ships, currentPlayer);
    currentPlayer++;
    enterShips(player2FieldOpen, player1FieldHidden, player2Ships, currentPlayer);
    currentPlayer = 0;
    Graphics::clearScreen();
}

bool areAllShipsSunk() {

    for (int i = 0; i < 5; i++) {
        bool isSunk = currentPlayer == 0 ? player1Ships[i].getIsSunk() : player2Ships[i].getIsSunk();
        if (!isSunk)
            return false;
    }

    return true;
}

void mainLoop() {
    ostringstream oss;
    bool gameIsAlive = true;

    while (gameIsAlive) {
        if (areAllShipsSunk())
            break;
        oss << "Player " << currentPlayer << " enter a coordinate to hit (a0, g4, h7 etc...):";
        string instruction = oss.str();

        int arrayPosition = Utilities::ValidateAndTranslatePosition(instruction);


    }

    cout << "Player " << currentPlayer << " wins! :)";
    system("pause");

}
int main()
{
    init();
    enterShips();
    mainLoop();
}




