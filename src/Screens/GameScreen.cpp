#include "GameScreen.hpp"
#include "../GameWindow.hpp"
#include "../Const/WindowSize.hpp"
#include <SDL2/SDL.h>
#include <cmath>

GameScreen::GameScreen() {
    this->frames = 0;
    this->paused = false;
    this->pause_counter = 0;
    this->selected_row_pause = PAUSE_ITEM_RESUME_TO_GAME;
    this->player = new Player(CharacterID::TestChara);
    this->stage = new TestStage(this->player);
}

ScreenID GameScreen::Render(GameWindow *game_window) {

    if(this->paused) 
        pause_counter = std::min(pause_counter + 1, PAUSE_COUNTER_MAX);
    else
        pause_counter = std::max(pause_counter - 1, 0);

    SDL_Rect all_rect = {0,0,960,720};
    if (pause_counter == 0) {
        this->stage->Draw(game_window);
    }


    if(pause_counter != 0) {
        game_window->FillRect(0x00, 0x40, 0x80, static_cast<uint8_t>(0x70 * (static_cast<double>(pause_counter) / PAUSE_COUNTER_MAX)), &all_rect);
        for(int i = 0; i < PAUSE_ITEM_COUNT + 1; i++) {
            SDL_Rect src = {0,48*i,220,48};
            SDL_Rect dst = {337,313+48*i,220, static_cast<int>(48 * (static_cast<double>(pause_counter) / PAUSE_COUNTER_MAX))};
            uint8_t alpha = 0xff;
            if(i >= 1 && (i - 1) != selected_row_pause)
                alpha = 0x80;
            else {
                dst.w *= 1.1;
                dst.h *= 1.1;
            }
            game_window->DrawImage(ImageID::game_pause_menu, &src, &dst, RefPoint::Center, alpha);
        }
    }

    game_window->DrawImage(ImageID::game_frame, &all_rect, &all_rect);

    if (game_window->getIsButtonPressed(Buttons::Pause)) {
        this->paused = !this->paused;
        selected_row_pause = PAUSE_ITEM_RESUME_TO_GAME;
    }

    if(this->paused) {
        if(game_window->getIsButtonPressed(Buttons::Down)) {
            selected_row_pause = (selected_row_pause + 1) % PAUSE_ITEM_COUNT;
        }
        if(game_window->getIsButtonPressed(Buttons::Up)) {
            selected_row_pause = (selected_row_pause - 1 + PAUSE_ITEM_COUNT) % PAUSE_ITEM_COUNT;
        }
        if(game_window->getIsButtonPressed(Buttons::Shot)) {
            switch (selected_row_pause)
            {
                case PAUSE_ITEM_RESUME_TO_GAME:
                    this->paused = false;
                    break;
                case PAUSE_ITEM_RETURN_TO_TITLE:
                    return ScreenID::Title;
            }
        }
    }

    return ScreenID::Game;
}