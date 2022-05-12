#if defined(__ANDROID__) && !defined(__TERMUX__) 
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

#include "MusicRoomScreen.hpp"
#include "../GameWindow.hpp"
#include "../Const/RefPoint.hpp"

MusicRoomScreenItem& operator++(MusicRoomScreenItem& item) {
    return item = static_cast<MusicRoomScreenItem>((static_cast<int>(item) + 1 + static_cast<int>(MusicRoomScreenItem::COUNT)) % static_cast<int>(MusicRoomScreenItem::COUNT));
}

MusicRoomScreenItem& operator--(MusicRoomScreenItem& item) {
    return item = static_cast<MusicRoomScreenItem>((static_cast<int>(item) - 1 + static_cast<int>(MusicRoomScreenItem::COUNT)) % static_cast<int>(MusicRoomScreenItem::COUNT));
}


MusicRoomScreen::MusicRoomScreen() {
    selected_row = MusicRoomScreenItem::HOGEHOGE;
}

MusicRoomScreen::~MusicRoomScreen() {
    
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