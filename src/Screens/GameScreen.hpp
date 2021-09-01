#ifndef _GAME_SCREEN_H_
#define _GAME_SCREEN_H_

#include <SDL2/SDL.h>
#include "../Screen.hpp"
#include "../Const/ScreenID.hpp"
#include "../Game/Chara/Character.hpp"
#include "../Game/Chara/TestChara.hpp"

class GameWindow;

//ゲーム画面クラス
class GameScreen : public Screen {
private:
    long frames;
    float x;
    float y;
    Character* chara; 
public:
    GameScreen() {
        this->frames = 0;
        this->x = 200;
        this->y = 200;
        this->chara = new TestChara();
    }
    virtual ~GameScreen() {
        delete this->chara;
    }
    ScreenID Render(GameWindow* game_window);
    ScreenID getScreenID() { return ScreenID::Game; }
};

#endif /* _GAME_SCREEN_H_ */