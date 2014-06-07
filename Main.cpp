#include "libtcod.hpp"
#include "S_Tile.h"
const int WINDOW_WIDTH = 80, WINDOW_HEIGHT = 50;

int getInput(bool menuscheme) {
    TCOD_key_t key = TCODConsole::checkForKeypress();
    if (menuscheme){
        if (key.vk == TCODK_ENTER || key.vk == TCODK_KPENTER) {
            return 0;
        }
        else if (key.vk == TCODK_ESCAPE || TCODK_BACKSPACE) {
            return 1;
        }
        else if (key.vk == TCODK_DOWN || key.vk == TCODK_KP2) {
            return 2;
        }
        else if (key.vk == TCODK_UP || key.vk == TCODK_KP8) {
            return 3;
        }
        else {
            return -1;
        }
    }
    else {
        switch(key.vk) {
            case TCODK_ESCAPE:
                return 0;
                break;
            case TCODK_CHAR:
                switch (key.c) {
                    default:
                        return -1;
                        break;
                }
                break;
            default:
                return -1;
                break;
        }
    }
}

void drawScreen(const Tile screen[][WINDOW_HEIGHT]) {
    TCODConsole::root->clear();
    for (int column = 0; column < WINDOW_HEIGHT; ++column){
        for (int row = 0; row < WINDOW_WIDTH; ++row){
            TCODConsole::root->putCharEx(row, column, screen[row][column].Symbol, screen[row][column].foreColor, screen[row][column].backColor);
        }
    }
    TCODConsole::flush();
}

int PauseScreen(const Tile gamescreen[][WINDOW_HEIGHT]) {
    bool paused = true;
    int pauseoutput = 0;
    while (paused) {
        int inputcode = getInput(true);
        if (quitgame) {
            pauseoutput = -1;
            paused = false;
        }
        if (savegame) {
            pauseoutput = 1;
            paused = false;
        }
        //PauseScreen Logic
        drawScreen(&pausescreen);
    }
    return pauseoutput;
}

int GameScreen(int seed) {
    bool ingame = true;
    int gameoutput = 0;
    while (ingame) {
        int inputcode = getInput(false);
        int pauseoutput;
        if (paused) {
            pauseoutput = PauseScreen(&gamescreen);
        }
        if (pauseoutput == 1) {
            gameoutput = level;
            ingame = false;
        }
        if (gameover || pauseoutput == -1) {
            gameoutput = -1;
            ingame = false;
        }
        //GameScreen Logic
        drawScreen(&gamescreen);
    }
    return gameoutput;
}

int MainScreen() {
    bool done = false;
    while (!done) {
        int inputcode = getInput(true);
        int gameoutput;
        if (gamestart) {
            gameoutput = GameScreen(randseed);
        }
        if (gameload) {
            gameoutput = GameScreen(levelseed);
        }
        if (gameoutput > 0) {
            setLoadSlot(gameoutput);
        }
        if (quit || gameoutput == -1) {
            done = true;
        }
        //MainScreen Logic
        drawScreen(&mainscreen);
    }
    return 1;
}

int main() {
    TCODConsole::initRoot(WINDOW_WIDTH,WINDOW_HEIGHT,"Joining The Adventurers Guild",false);
    return MainScreen();
}
