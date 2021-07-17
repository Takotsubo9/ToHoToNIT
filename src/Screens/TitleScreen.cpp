#include "TitleScreen.hpp"
#include "../GameWindow.hpp"
#include <SDL2/SDL.h>

ScreenID TitleScreen::Render(GameWindow* game_window) {

    for(int i=0; i<TITLE_ITEM_COUNT; i++) {
        SDL_Rect srcrect = {0,48*i,220,48};
        SDL_Rect dstrect = {667-(i*10),292+(i*45),220,48};
        if(i == selected_row) {
            dstrect.x -= 2;
            dstrect.y -= 2;
            game_window->DrawImage(ImageID::title_selected_items, &srcrect, &dstrect);
        } else {
            game_window->DrawImage(ImageID::title_items, &srcrect, &dstrect);
        }
    }
    
    if(game_window->getIsButtonPressed(Buttons::Bomb) || game_window->getIsButtonPressed(Buttons::Pause))
        this->selected_row = TITLE_ITEM_QUIT;

    if(game_window->getIsButtonPressed(Buttons::Shot)) {
        switch(selected_row) {
            case TITLE_ITEM_QUIT:
                game_window->Quit();
            default:
                break;
        }
    }

    if(game_window->getIsButtonPressed(Buttons::Down))
        selected_row = (selected_row + 1 + TITLE_ITEM_COUNT) % TITLE_ITEM_COUNT;
    if(game_window->getIsButtonPressed(Buttons::Up))
    selected_row = (selected_row - 1 + TITLE_ITEM_COUNT) % TITLE_ITEM_COUNT;

    return ScreenID::Title;
}
