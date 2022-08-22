#include "ModeSelectScreen.hpp"
#include "../Config.hpp"
#include "../GameWindow.hpp"

ModeSelectScreen::ModeSelectScreen() {
    this->frames = 0;
}

ModeSelectScreen::~ModeSelectScreen() {

}

ScreenID ModeSelectScreen::Render(GameWindow* game_window) {
    this->frames++;
    return ScreenID::ModeSelect;
}

