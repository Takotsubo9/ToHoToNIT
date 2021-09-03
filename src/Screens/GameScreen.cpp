#include "GameScreen.hpp"
#include "../GameWindow.hpp"
#include "../Const/WindowSize.hpp"
#include <SDL2/SDL.h>
#include <cmath>

ScreenID GameScreen::Render(GameWindow *game_window) {

    if (game_window->getIsButtonPressed(Buttons::Pause)) {
        if(!this->paused) {
            this->paused = true;
        } else {
            return ScreenID::Title;
        }
    }

    return ScreenID::Game;
}