#ifndef _CHARACTER_SELECT_SCREEN_HPP_
#define _CHARACTER_SELECT_SCREEN_HPP_

#include <string>
#if defined(__ANDROID__) && !defined(__TERMUX__)
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

#include "Screen.hpp"
#include "../Const/CharacterID.hpp"
#include "../Const/ScreenID.hpp"

class GameWindow;
class Config;

class CharacterSelectScreen : public Screen {
private:
    long frames;
public:
    CharacterSelectScreen();
    virtual ~CharacterSelectScreen();
    ScreenID Render(GameWindow* game_window);
    ScreenID getScreenID() { return ScreenID::CharacterSelect; }
};

#endif