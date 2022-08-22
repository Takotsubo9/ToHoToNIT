#ifndef _MODE_SELECT_SCREEN_HPP_
#define _MODE_SELECT_SCREEN_HPP_

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

class ModeSelectScreen : public Screen {
private:
    long frames;
public:
    ModeSelectScreen();
    virtual ~ModeSelectScreen();
    ScreenID Render(GameWindow* game_window);
    ScreenID getScreenID() { return ScreenID::ModeSelect; }
};

#endif /* _MODE_SELECT_SCREEN_ */