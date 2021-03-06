#include "C_Screens.h"

C_Screens::getGameScreen(char (&screen)[80][40]) {
    for (int column = 0; column < 40; ++column) {
        for (int row = 0; row < 80; ++row) {
            screen[row][column] = _gamescreen[column][row];
        }
    }
}

C_Screens::getStartScreen(char (&screen)[80][40]) {
    for (int column = 0; column < 40; ++column) {
        for (int row = 0; row < 80; ++row) {
            screen[row][column] = _startscreen[column][row];
        }
    }
}
