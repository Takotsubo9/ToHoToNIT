#ifdef __ANDROID__
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

#include "MusicRoomScreen.hpp"
#include "../GameWindow.hpp"
#include "../Const/RefPoint.hpp"

MusicRoomScreen::MusicRoomScreen() {
    selected_row = MUSIC_ITEM_HOGEHOGE;
}

ScreenID MusicRoomScreen::Render(GameWindow* game_window) {
    //とりあえず、BGの描画
    SDL_Rect bg_src_rect = {0,0,1600,1200};
    SDL_Rect bg_rect = {0,0,960,720};
    game_window->DrawImage(ImageID::musicroom_background, &bg_src_rect, &bg_rect, RefPoint::LeftTop);

    if(game_window->getIsButtonPressed(Buttons::Pause))
        return ScreenID::Title;

    return ScreenID::MusicRoom;
}