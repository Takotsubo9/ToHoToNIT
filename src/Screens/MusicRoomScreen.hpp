#ifndef _MUSIC_ROOM_SCREEN_H_
#define _MUSIC_ROOM_SCREEN_H_

#ifdef __ANDROID__
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

#include "Screen.hpp"
#include "../Const/ScreenID.hpp"

class GameWindow;

enum class MusicRoomScreenItem : int {
    HOGEHOGE = 0,
    COUNT,//個数カウント用
};

//ゲーム画面クラス
class MusicRoomScreen : public Screen {
private:
    MusicRoomScreenItem selected_row;
public:
    MusicRoomScreen();
    virtual ~MusicRoomScreen() {
    }
    ScreenID Render(GameWindow* game_window);
    ScreenID getScreenID() { return ScreenID::MusicRoom; }
};

#endif /* _MUSIC_ROOM_SCREEN_H_ */