#include "MusicRoomScreen.hpp"
#include "../GameWindow.hpp"
#include "../Const/RefPoint.hpp"
#include <SDL2/SDL.h>


ScreenID MusicRoomScreen::Render(GameWindow* game_window) {
    SDL_Rect bg_src_rect = {0,0,1600,1200};
    SDL_Rect bg_rect = {0,0,960,720};
    game_window->DrawImage(ImageID::musicroom_background, &bg_src_rect, &bg_rect, RefPoint::LeftTop);

    if(game_window->getIsButtonPressed(Buttons::Pause))
        return ScreenID::Title;

    return ScreenID::MusicRoom;
}