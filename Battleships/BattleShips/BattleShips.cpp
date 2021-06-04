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
    Graphics::waitForKey();
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
        bool isSunk = currentPlayer == 0 ? player2Ships[i].getIsSunk() : player1Ships[i].getIsSunk();
        if (!isSunk)
            return false;
    }

    return true;
}

bool checkForHitOnShip(int position, int& shipNumber) {
    for (int i = 0; i < 5; i++) {
        Ship testShip = currentPlayer == 0 ? player2Ships[i] : player1Ships[i];
        if (testShip.getPosition() == position) {
            shipNumber = i;
            return true;
        }
    }
    return false;
}

void sinkShip(int shipNumber) {
    currentPlayer == 0 ? player2Ships[shipNumber].sinkShip() : player1Ships[shipNumber].sinkShip(); 
}

void mainLoop() {

    bool gameIsAlive = true;

    while (gameIsAlive) {       
        Graphics::clearScreen();
        Graphics::drawGrid(player1FieldHidden, player2FieldHidden);

        ostringstream oss;
        oss << "Player " << currentPlayer +1 << " enter a coordinate to hit (a0, g4, h7 etc...):";
        string instruction = oss.str();

        int position = Utilities::ValidateAndTranslatePosition(instruction);
        int shipNumber = 0;
        if (checkForHitOnShip(position, shipNumber)) {
            cout << "you hit a ship!"<<endl;
            Graphics::waitForKey();
            sinkShip(shipNumber);
            currentPlayer == 0 ? player2FieldHidden.markPositionWithCharacter(position, char(shipNumber+ZERO)) : player1FieldHidden.markPositionWithCharacter(position, char(shipNumber + ZERO));
        }
        else {
            cout << "miss!" << endl;
            currentPlayer == 0 ? player2FieldHidden.markPositionWithCharacter(position, '*') : player1FieldHidden.markPositionWithCharacter(position, '*');
            Graphics::waitForKey();
        }
        if (areAllShipsSunk())
            break;
        currentPlayer++;
        currentPlayer &= 1;
    }

    cout << "Player " << currentPlayer +1 << " wins! :)";
    Graphics::waitForKey();

}
int main()
{
    init();
    enterShips();
    mainLoop();
}




