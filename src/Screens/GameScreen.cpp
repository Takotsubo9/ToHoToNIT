#include "GameScreen.hpp"
#include "../GameWindow.hpp"
#include "../Const/WindowSize.hpp"
#include <SDL2/SDL.h>
#include <cmath>

ScreenID GameScreen::Render(GameWindow *game_window) {

    if (!this->paused) {
        this->stage->Draw(game_window);
    }

    SDL_Rect frame_rect = {0,0,960,720};
    game_window->DrawImage(ImageID::game_frame, &frame_rect, &frame_rect);

    if (game_window->getIsButtonPressed(Buttons::Pause)) {
        if(!this->paused) {
            this->paused = true;
        } else {
            return ScreenID::Title;
        }
    }

    return ScreenID::Game;
}