#ifdef WIN32
#define SDL_MAIN_HANDLED
#endif

#ifdef __ANDROID__
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

#include "GameWindow.hpp"

int main(int argc, char* argv[]) {

    //960x720のGameWindowのインスタンスを作って、Run
    GameWindow gw("Touhou-Koumatou", 960, 720);
    gw.Run();
    
    return 0;
}