#ifndef _GAME_SCREEN_H_
#define _GAME_SCREEN_H_

#include <SDL2/SDL.h>
#include "../Screen.hpp"
#include "../Const/ScreenID.hpp"
#include "../Const/CharacterID.hpp"
#include "../Game/Stage/Stage.hpp"
#include "../Game/Stage/TestStage.hpp"

class GameWindow;

//ゲーム画面クラス
class GameScreen : public Screen {
private:
    long frames;
    Stage * stage;
    Player * player;
    bool paused;
public:
    GameScreen() {
        this->frames = 0;
        this->paused = false;
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