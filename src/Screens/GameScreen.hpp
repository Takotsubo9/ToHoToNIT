#ifndef _GAME_SCREEN_H_
#define _GAME_SCREEN_H_

#include <SDL2/SDL.h>
#include "../Screen.hpp"
#include "../Const/ScreenID.hpp"
#include "../Const/CharacterID.hpp"
#include "../Game/Stage/Stage.hpp"
#include "../Game/Stage/TestStage.hpp"

class GameWindow;

static int PAUSE_COUNTER_MAX = 20;

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
    GameScreen() {
        this->frames = 0;
        this->paused = false;
        this->pause_counter = 0;
        this->selected_row_pause = PAUSE_ITEM_RESUME_TO_GAME;
        this->player = new Player(CharacterID::TestChara);
        this->stage = new TestStage(this->player);
    }
    virtual ~GameScreen() {
        delete this->stage;
        delete this->player;
    }
    ScreenID Render(GameWindow* game_window);
    ScreenID getScreenID() { return ScreenID::Game; }
};

#endif /* _GAME_SCREEN_H_ */