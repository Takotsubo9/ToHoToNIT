#ifndef _SCREEN_MANAGER_H_
#define _SCREEN_MANAGER_H_


#include <iostream>
#include <chrono>
#include <cmath>
#include <memory>
#include "Const/ScreenID.hpp"
#include "FPS.hpp"

class GameWindow;
class Screen;

//すべての画面を管理し、画面遷移などを司るクラス
class ScreenManager {
private:
    std::unique_ptr<Screen> screen; //Screenクラスを継承したものを回す。
    FPS fps;
public:
    ScreenManager();
    virtual ~ScreenManager();
    void Render(GameWindow* game_window);
};

#endif /* _SCREEN_MANAGER_H_ */