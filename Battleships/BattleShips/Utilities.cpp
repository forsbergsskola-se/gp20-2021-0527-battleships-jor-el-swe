#include "Utilities.h"
#include <iostream>

using namespace std;

int Utilities::ValidateAndTranslatePosition(string message)
{
    int arrayPosition = 0;
    bool successfulInput = false;
    while (!successfulInput) {
        cout << message;
        string playerPosition;
        cin >> playerPosition;
        
        if (playerPosition.length() != 2)
            continue;

        const auto validLetters = std::string("abcdefghij");

        if (! (validLetters.find(playerPosition[ROW]) < validLetters.length()))
            continue;

        const auto validNumbers = std::string("0123456789");

        if (!(validNumbers.find(playerPosition[COLUMN]) < validLetters.length()))
            continue;

        successfulInput = true;

        arrayPosition += (playerPosition[ROW] - LOWER_CASE_A)*10;
        arrayPosition += playerPosition[COLUMN] - ZERO;
        
    }
    return arrayPosition;
}
