#ifndef _OPTION_SCREEN_H_
#define _OPTION_SCREEN_H_

#include <SDL2/SDL.h>
#include "../Screen.hpp"
#include "../Const/ScreenID.hpp"

class GameWindow;

enum : int {
    OPTION_ITEM_PLAYER = 0,
    OPTION_ITEM_BOMB,
    OPTION_ITEM_BGM_VOLUME,
    OPTION_ITEM_SE_VOLUME,
    OPTION_ITEM_MODE,
    OPTION_ITEM_INITIAL,
    OPTION_ITEM_KEYCONFIG,
    OPTION_ITEM_QUIT,
    OPTION_ITEM_COUNT,//個数カウント用
};

//オプション画面クラス
class OptionScreen : public Screen {
private:
    long frames;
    int selected_row;
public:
    OptionScreen() {
        this->frames = 0;
        this->selected_row = OPTION_ITEM_PLAYER;
    }
    ~OptionScreen() {
        
    }
    ScreenID Render(GameWindow* game_window);
    ScreenID getScreenID() { return ScreenID::Option; }
};

#endif /* _OPTION_SCREEN_H_ */