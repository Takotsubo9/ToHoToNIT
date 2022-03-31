#ifndef _TITLE_SCREEN_H_
#define _TITLE_SCREEN_H_

#ifdef __ANDROID__
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

#include "Screen.hpp"
#include "../Const/ScreenID.hpp"

class GameWindow;

//タイトルの選択リスト
enum class TitleScreenItem : int {
    START = 0,
    EXTRA_START,
    SCARLET_START,
    PRACTICE_START,
    REPLAY,
    SCORE,
    MUSIC_ROOM,
    OPTION,
    QUIT,
    COUNT,//個数カウント用
};

//オプションでの選択リスト
enum class OptionScreenItem : int {
    PLAYER = 0,
    BOMB,
    BGM_VOLUME,
    SE_VOLUME,
    FULLSCREEN_MODE,
    RESET,
    KEYCONFIG,
    QUIT,
    COUNT,//個数カウント用
};

//キーコンでの選択リスト
enum KeyConfigScreenItem : int {
    SHOT = 0,
    BOMB,
    SLOW,
    PAUSE,
    UP,
    DOWN,
    LEFT,
    RIGHT,
    SKIP,
    RESET,
    QUIT,
    COUNT,//個数カウント用
};

//タイトル画面でのフェーズ
//タイトル/オプション/キーコンを同じスクリーンとして扱う
enum class TitleScreenPhase {
    Title,
    Option,
    KeyConfig,
};

//タイトル画面クラス
class TitleScreen : public Screen {
private:
    long frames;
    TitleScreenItem selected_row_title;
    OptionScreenItem selected_row_option;
    KeyConfigScreenItem selected_row_keyconfig;
    TitleScreenPhase phase;
public:
    TitleScreen();
    virtual ~TitleScreen() {
        
    }
    ScreenID Render(GameWindow* game_window);
    ScreenID getScreenID() { return ScreenID::Title; }
};

#endif /* _TITLE_SCREEN_H_ */