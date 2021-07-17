#include "OptionScreen.hpp"
#include "../GameWindow.hpp"

ScreenID OptionScreen::Render(GameWindow* game_window) {

    for(int i=0; i<OPTION_ITEM_COUNT; i++) {
        SDL_Rect srcrect = {0,48*i,180,48};
        SDL_Rect dstrect = {100,100+(i*45),180,48};
        if(i == selected_row) {
            dstrect.x -= 2;
            dstrect.y -= 2;
            game_window->DrawImage(ImageID::option_selected_items, &srcrect, &dstrect);
        } else {
            game_window->DrawImage(ImageID::option_items, &srcrect, &dstrect, 0xC0);
        }
    }

    if(game_window->getIsButtonPressed(Buttons::Bomb) || game_window->getIsButtonPressed(Buttons::Pause))
        this->selected_row = OPTION_ITEM_QUIT;

    if(game_window->getIsButtonPressed(Buttons::Shot)) {
        switch(selected_row) {
            case OPTION_ITEM_QUIT:
                return ScreenID::Title;
            default:
                break;
        }
    }

    if(game_window->getIsButtonPressed(Buttons::Down))
        selected_row = (selected_row + 1 + OPTION_ITEM_COUNT) % OPTION_ITEM_COUNT;
    if(game_window->getIsButtonPressed(Buttons::Up))
    selected_row = (selected_row - 1 + OPTION_ITEM_COUNT) % OPTION_ITEM_COUNT;


    return ScreenID::Option;
}