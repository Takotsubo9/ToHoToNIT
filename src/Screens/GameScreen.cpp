#include "GameScreen.hpp"
#include "../GameWindow.hpp"
#include "../Const/WindowSize.hpp"
#include <SDL2/SDL.h>
#include <cmath>

ScreenID GameScreen::Render(GameWindow *game_window) {
    if (game_window->getIsButtonPressed(Buttons::Pause))
        return ScreenID::Title;

    float x, y;
    game_window->getMovement(&x, &y);

    float speedrate = game_window->getIsButtonDown(Buttons::Slow) ? this->chara->getLowFSpeed() : this->chara->getHighFSpeed();

    this->x += x * speedrate * 1.5;
    this->y += y * speedrate * 1.5;

    this->x = std::max(std::min(static_cast<float>(WINDOW_WIDTH-10),this->x),static_cast<float>(0));
    this->y = std::max(std::min(static_cast<float>(WINDOW_HEIGHT-10),this->y),static_cast<float>(0));

    SDL_Rect rect = {static_cast<int>(this->x), static_cast<int>(this->y), 10, 10};
    game_window->FillRect(255, 255, 255, 255, &rect);

    return ScreenID::Game;
}