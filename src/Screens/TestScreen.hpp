#ifndef _TEST_SCREEN_H_
#define _TEST_SCREEN_H_

#include <SDL2/SDL.h>
#include "../Screen.hpp"
#include "../Const/ScreenID.hpp"

class GameWindow;

//仮の画面クラス
class TestScreen : public Screen {
private:
    long frames;
public:
    TestScreen() {
        this->frames = 0;
    }
    ~TestScreen() {
        
    }
    ScreenID Render(GameWindow* game_window);
    ScreenID getScreenID() { return ScreenID::Booting; }
};

#endif /* _TEST_SCREEN_H_ */