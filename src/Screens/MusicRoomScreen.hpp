#ifndef _MUSIC_ROOM_SCREEN_H_
#define _MUSIC_ROOM_SCREEN_H_

#include <SDL2/SDL.h>
#include "../Screen.hpp"
#include "../Const/ScreenID.hpp"

class GameWindow;

enum : int {
    MUSIC_ITEM_HOGEHOGE = 0,
    MUSIC_ITEM_COUNT,//個数カウント用
};

//ゲーム画面クラス
class MusicRoomScreen : public Screen {
private:
    int selected_row;
public:
    MusicRoomScreen();
    virtual ~MusicRoomScreen() {
    }
    ScreenID Render(GameWindow* game_window);
    ScreenID getScreenID() { return ScreenID::MusicRoom; }
};

#endif /* _MUSIC_ROOM_SCREEN_H_ */