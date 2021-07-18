#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include "GameWindow.hpp"
#include "Const/WindowSize.hpp"

int main() {

    GameWindow gw("Touhou-Koumatou", WINDOW_WIDTH, WINDOW_HEIGHT);
    gw.Run();
    
    return 0;
}