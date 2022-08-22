#include "CharacterSelectScreen.hpp"
#include "../Config.hpp"
#include "../GameWindow.hpp"

CharacterSelectScreen::CharacterSelectScreen() {
    this->frames = 0;
}

CharacterSelectScreen::~CharacterSelectScreen() {

}

ScreenID CharacterSelectScreen::Render(GameWindow* game_window) {
    this->frames++;
    return ScreenID::CharacterSelect;
}

