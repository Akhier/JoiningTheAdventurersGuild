#include "libtcod.hpp"
int main() {
    TCODConsole::initRoot(80,50,"Joining The Adventurers Guild",false);
    return MainScreen();
}

int MainScreen() {
    bool done = false;
    while (!done) {
        drawScreen(&mainscreen);
        handleInput(true);
        //MainScreen Logic
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
    }
    return 1;
}

int GameScreen(int seed) {
    bool ingame = true;
    int gameoutput = 0;
    while (ingame) {
        drawScreen(&gamescreen);
        handleInput(false);
        //GameScreen Logic
        int pauseoutput
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
    }
    return gameoutput;
}

int PauseScreen(const /*some map or custom struct*/ &gamescreen) {
    bool paused = true;
    int pauseoutput = 0;
    while (paused) {
        drawScreen(&pausescreen);
        handleInput(true);
        //PauseScreen Logic
        if (quitgame) {
            pauseoutput = -1;
            paused = false;
        }
        if (savegame) {
            pauseoutput = 1;
            paused = false;
        }
    }
    return pauseoutput;
}
