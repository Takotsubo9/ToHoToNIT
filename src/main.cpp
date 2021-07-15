#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <filesystem>
#include "GameWindow.hpp"
#include "Const/WindowSize.hpp"

int main(int argc, char* argv[]) {

    if(argc != 0){
        //setting current directory
        std::filesystem::path zeroargv = argv[0];
        std::string pathstring;

        if(zeroargv.is_relative()) {
            std::filesystem::path current = std::filesystem::current_path();
            current.concat("/"+zeroargv.string());
            current.make_preferred();
            pathstring = current.parent_path().string();
        } else {
            pathstring = zeroargv.parent_path().string();
        }

        std::filesystem::path currentdir = pathstring;
        std::filesystem::current_path(currentdir);
        std::cout << std::filesystem::current_path().string() << std::endl;
    }

    GameWindow gw("Touhou-Koumatou", WINDOW_WIDTH, WINDOW_HEIGHT);
    gw.Run();
    
    return 0;
}