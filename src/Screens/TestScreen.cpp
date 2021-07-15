#include "TestScreen.hpp"
#include "../Const/WindowSize.hpp"
#include "../GameWindow.hpp"
#include <cmath>

ScreenID TestScreen::Render(GameWindow* game_window) {
    //Render red filled quad
    SDL_Rect fillRect = { WINDOW_WIDTH / 4 + (game_window->getAxis(0)/200), WINDOW_HEIGHT / 4 + (game_window->getAxis(1)/200), WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 };

    if(game_window->getIsKeyDown(SDLK_b) || game_window->getIsJoyButtonDown(0))
        game_window->FillRect( 0xFF, 0x00, 0x00, (sin(this->frames / 60.0) + 1) * 0xFF / 2.0 , &fillRect);
    else if(game_window->getIsKeyPressed(SDLK_SPACE) || game_window->getIsJoyButtonPressed(1))
        game_window->FillRect( 0x00, 0xFF, 0x00, (sin(this->frames / 60.0) + 1) * 0xFF / 2.0 , &fillRect);
    else
        game_window->FillRect( 0x00, 0x00, 0xFF, (sin(this->frames / 60.0) + 1) * 0xFF / 2.0 , &fillRect);

    if(game_window->getIsKeyPressed(SDLK_q))
        game_window->Quit();

    if(game_window->getIsKeyPressed(SDLK_F11)) {
        if(game_window->getFullScreenMode() == FullScreenMode::Windowed)
            game_window->setFullScreenMode(FullScreenMode::BorderLess);
        else if(game_window->getFullScreenMode() == FullScreenMode::BorderLess)
            game_window->setFullScreenMode(FullScreenMode::Fullscreen);
        else
            game_window->setFullScreenMode(FullScreenMode::Windowed);
    }

    this->frames++;
    return ScreenID::Booting;
}
