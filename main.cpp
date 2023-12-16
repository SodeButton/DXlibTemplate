#include "Game.hpp"
#include "dxlib/DxLib.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    Game game;
    if (game.Initialize()) {
        game.RunLoop();
    }

    game.Shutdown();
    return 0;
}
