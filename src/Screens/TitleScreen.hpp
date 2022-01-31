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
    TITLE_ITEM_PRACTICE_START,
    TITLE_ITEM_REPLAY,
    TITLE_ITEM_SCORE,
    TITLE_ITEM_MUSIC_ROOM,
    TITLE_ITEM_OPTION,
    TITLE_ITEM_QUIT,
    TITLE_ITEM_COUNT,//個数カウント用
};

enum : int {
    OPTION_ITEM_PLAYER = 0,
    OPTION_ITEM_BOMB,
    OPTION_ITEM_BGM_VOLUME,
    OPTION_ITEM_SE_VOLUME,
    OPTION_ITEM_MODE,
    OPTION_ITEM_RESET,
    OPTION_ITEM_KEYCONFIG,
    OPTION_ITEM_QUIT,
    OPTION_ITEM_COUNT,//個数カウント用
};

enum : int {
    KEYCONFIG_ITEM_SHOT = 0,
    KEYCONFIG_ITEM_BOMB,
    KEYCONFIG_ITEM_SLOW,
    KEYCONFIG_ITEM_PAUSE,
    KEYCONFIG_ITEM_UP,
    KEYCONFIG_ITEM_DOWN,
    KRYCONFIG_ITEM_LEFT,
    KEYCONFIG_ITEM_RIGHT,
    KEYCONFIG_ITEM_SKIP,
    KEYCONFIG_ITEM_RESET,
    KEYCONFIG_ITEM_QUIT,
    KEYCONFIG_ITEM_COUNT,//個数カウント用
};

enum class TitleScreenPhase {
    Title,
    Option,
    KeyConfig,
};

//タイトル画面クラス
class TitleScreen : public Screen {
private:
    long frames;
    int selected_row_title;
    int selected_row_option;
    int selected_row_keyconfig;
    TitleScreenPhase phase;
public:
    TitleScreen();
    virtual ~TitleScreen() {
        
    }
    ScreenID Render(GameWindow* game_window);
    ScreenID getScreenID() { return ScreenID::Title; }
};

#endif /* _TITLE_SCREEN_H_ */