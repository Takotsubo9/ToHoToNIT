#ifndef _GAME_SCREEN_H_
#define _GAME_SCREEN_H_

#if defined(__ANDROID__) && !defined(__TERMUX__)
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

#include "Screen.hpp"
#include "../Const/ScreenID.hpp"
#include "../Const/CharacterID.hpp"
#include "../Game/Stage/Stage.hpp"
#include "../Game/Stage/TestStage.hpp"

class GameWindow;

const int PAUSE_COUNTER_MAX = 20;

enum : int {
    PAUSE_ITEM_RESUME_TO_GAME = 0,
    PAUSE_ITEM_RETURN_TO_TITLE,
    PAUSE_ITEM_COUNT,//個数カウント用
};

//ゲーム画面クラス
class GameScreen : public Screen {
private:
    long frames;
    Stage * stage;
    Player * player;
    bool paused;
    int pause_counter;
    int selected_row_pause;
public:
    GameScreen(Config& config);
    virtual ~GameScreen();
    ScreenID Render(GameWindow* game_window);
    ScreenID getScreenID() { return ScreenID::Game; }
};

#endif /* _GAME_SCREEN_H_ */