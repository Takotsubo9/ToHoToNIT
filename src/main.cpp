#ifdef WIN32
#define SDL_MAIN_HANDLED
#endif

#include <string>
#if defined(__ANDROID__) && !defined(__TERMUX__)
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

#include "GameWindow.hpp"

int main(int argc, char* argv[]) {

    try {
        //960x720のGameWindowのインスタンスを作って、Run
        GameWindow gw("Touhou-Koumatou", 960, 720);
        gw.Run();
    } catch (std::exception& e) {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Touhou-Koumatou", (std::string("An error has occurred.\n") + std::string(e.what())).c_str(), NULL);
    }
    
    return 0;
}