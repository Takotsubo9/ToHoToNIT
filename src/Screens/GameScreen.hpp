#ifndef _GAME_SCREEN_H_
#define _GAME_SCREEN_H_

#include <SDL2/SDL.h>
#include "../Screen.hpp"
#include "../Const/ScreenID.hpp"

class GameWindow;

//ゲーム画面クラス
class GameScreen : public Screen {
private:
    long frames;
public:
    GameScreen() {
        this->frames = 0;
    }
    ~GameScreen() {
        
    }
    ScreenID Render(GameWindow* game_window);
    ScreenID getScreenID() { return ScreenID::Game; }
};

#endif /* _GAME_SCREEN_H_ */