#ifndef _SCREEN_H_
#define _SCREEN_H_

#if defined(__ANDROID__) && !defined(__TERMUX__) 
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

#include "../Const/ScreenID.hpp"

class GameWindow;

//画面の基底クラス
//新しい画面を追加する場合、このクラスを継承すること
class Screen {
public:
    Screen(){};
    virtual ~Screen(){};
    virtual ScreenID Render(GameWindow* game_window) = 0;
    virtual ScreenID getScreenID() = 0;
};

#endif /* _SCREEN_H_ */