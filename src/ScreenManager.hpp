#ifndef _SCREEN_MANAGER_H_
#define _SCREEN_MANAGER_H_


#include <iostream>
#include <chrono>
#include <cmath>
#if defined(__ANDROID__) && !defined(__TERMUX__)
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif
#include "Const/ScreenID.hpp"
#include "FPS.hpp"

class GameWindow;
class Screen;

//すべての画面を管理し、画面遷移などを司るクラス
class ScreenManager {
private:
    Screen* screen; //Screenクラスを継承したものを回す。
    FPS fps;
public:
    ScreenManager();
    virtual ~ScreenManager();
    void Render(GameWindow* game_window);
};

#endif /* _SCREEN_MANAGER_H_ */