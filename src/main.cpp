#ifdef WIN32
#define SDL_MAIN_HANDLED
#endif

#ifdef __ANDROID__
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

#include "GameWindow.hpp"
#include "Const/WindowSize.hpp"

int main(int argc, char* argv[]) {

    GameWindow gw("Touhou-Koumatou", WINDOW_WIDTH, WINDOW_HEIGHT);
    gw.Run();
    
    return 0;
}