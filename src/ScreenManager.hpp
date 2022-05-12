#ifndef _SCREEN_MANAGER_H_
#define _SCREEN_MANAGER_H_

#if defined(__ANDROID__) && !defined(__TERMUX__) 
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

#include <iostream>
#include <chrono>
#include <cmath>
#include "Screens/Screen.hpp"
#include "Const/ScreenID.hpp"
#include "FPS.hpp"

class GameWindow;

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