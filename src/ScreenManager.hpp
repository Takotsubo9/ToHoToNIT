#ifndef _SCREEN_MANAGER_H_
#define _SCREEN_MANAGER_H_

#include <iostream>
#include <chrono>
#include <cmath>
#include <SDL2/SDL.h>
#include "Screen.hpp"
#include "Screens/TestScreen.hpp"
#include "Const/ScreenID.hpp"

class GameWindow;

//すべての画面を管理し、画面遷移などを司るクラス
class ScreenManager {
private:
    Screen* screen; //Screenクラスを継承したものを回す。
    uint64_t PrevTicks = 0;
public:
    ScreenManager();
    ~ScreenManager();
    void Render(GameWindow* game_window);
};

#endif /* _SCREEN_MANAGER_H_ */