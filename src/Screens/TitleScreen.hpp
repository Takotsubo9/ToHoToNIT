#ifndef _TITLE_SCREEN_H_
#define _TITLE_SCREEN_H_

#include <SDL2/SDL.h>
#include "../Screen.hpp"
#include "../Const/ScreenID.hpp"

class GameWindow;

enum : int {
    TITLE_ITEM_START = 0,
    TITLE_ITEM_EXTRA_START,
    TITLE_ITEM_SCARLET_START,
    TITLE_ITEM_REPLAY,
    TITLE_ITEM_SCORE,
    TITLE_ITEM_MUSIC_ROOM,
    TITLE_ITEM_OPTION,
    TITLE_ITEM_QUIT,
    TITLE_ITEM_COUNT,//個数カウント用
};

//タイトル画面クラス
class TitleScreen : public Screen {
private:
    long frames;
    int selected_row;
public:
    TitleScreen() {
        this->frames = 0;
        this->selected_row = TITLE_ITEM_START;
    }
    ~TitleScreen() {
        
    }
    ScreenID Render(GameWindow* game_window);
    ScreenID getScreenID() { return ScreenID::Title; }
};

#endif /* _TITLE_SCREEN_H_ */