#include "ModeSelectScreen.hpp"
#include "../Config.hpp"
#include "../GameWindow.hpp"

ModeSelectScreen::ModeSelectScreen() {
    this->frames = 0;
}

ModeSelectScreen::~ModeSelectScreen() {

}

ScreenID ModeSelectScreen::Render(GameWindow* game_window) {

    // とりあえずモードセレクトを仮で
    if (game_window->getIsButtonPressed(Buttons::Pause)) {
        return ScreenID::Title;
    } else if (game_window->getIsButtonPressed(Buttons::Shot)) {
        return ScreenID::Game;
    }

    this->frames++;
    return ScreenID::ModeSelect;
}

