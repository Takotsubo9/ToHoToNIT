#include "OptionScreen.hpp"
#include "../GameWindow.hpp"
#include "../Config.hpp"

ScreenID OptionScreen::Render(GameWindow* game_window) {

    for(int i=0; i<OPTION_ITEM_COUNT; i++) {
        const int x = 100;
        const int y = 100+(i*45);
        SDL_Rect srcrect = {0,48*i,180,48};
        SDL_Rect dstrect = {100,y,180,48};
        const int active_alpha = (i == selected_row) ? 0xFF : 0xC0;
        if(i == selected_row) {
            dstrect.x -= 2;
            dstrect.y -= 2;
            game_window->DrawImage(ImageID::option_selected_items, &srcrect, &dstrect);
        } else {
            game_window->DrawImage(ImageID::option_items, &srcrect, &dstrect, 0xC0);
        }
        
        switch(i) {
            case OPTION_ITEM_PLAYER:
                for(int j=0;j<5;j++) {
                    SDL_Rect src_rect = {(j+1)*32,0,32,48};
                    SDL_Rect dst_rect = {x+200+j*32,y,32,48};
                    if(i==selected_row) {
                        dst_rect.x -= 2;
                        dst_rect.y -= 2;
                    }
                    if(j==game_window->config.getPlayerCount()-1) {
                        dst_rect.x -= 2;
                        dst_rect.y -= 2;
                        game_window->DrawImage(ImageID::number_selected, &src_rect, &dst_rect, active_alpha);
                    }
                    else
                        game_window->DrawImage(ImageID::number, &src_rect, &dst_rect, active_alpha);
                }
                break;
            case OPTION_ITEM_BOMB:
                for(int j=0;j<4;j++) {
                    SDL_Rect src_rect = {j*32,0,32,48};
                    SDL_Rect dst_rect = {x+200+j*32,y,32,48};
                    if(i==selected_row) {
                        dst_rect.x -= 2;
                        dst_rect.y -= 2;
                    }
                    if(j==game_window->config.getBombCount()) {
                        dst_rect.x -= 2;
                        dst_rect.y -= 2;
                        game_window->DrawImage(ImageID::number_selected, &src_rect, &dst_rect, active_alpha);
                    }
                    else
                        game_window->DrawImage(ImageID::number, &src_rect, &dst_rect, active_alpha);
                }
                break;
            case OPTION_ITEM_BGM_VOLUME:
                {
                    int vol = game_window->config.getBGMVolume();
                    int digit = 0;
                    int num = vol;
                    while(num != 0){
                        num /= 10;
                        digit++;
                    }
                    for(int j=0;j<digit;j++) {
                        int Deg = ((int)(vol / pow(10, j)) % 10);
                        SDL_Rect src_rect = {32*Deg,0,32,48};
                        SDL_Rect dst_rect = {-25*j+x+250,y,32,48};
                        if(i==selected_row) {
                            dst_rect.x -= 2;
                            dst_rect.y -= 2;
                            game_window->DrawImage(ImageID::number_selected, &src_rect, &dst_rect, active_alpha);
                        }
                        else
                            game_window->DrawImage(ImageID::number, &src_rect, &dst_rect, active_alpha);
                    }
                }
                break;
            case OPTION_ITEM_SE_VOLUME:
                {
                    int vol = game_window->config.getSEVolume();
                    int digit = 0;
                    int num = vol;
                    while(num != 0){
                        num /= 10;
                        digit++;
                    }
                    for(int j=0;j<digit;j++) {
                        int Deg =((int)(vol / pow(10, j)) % 10);
                        SDL_Rect src_rect = {32*Deg,0,32,48};
                        SDL_Rect dst_rect = {-25*j+x+250,y,32,48};
                        if(i==selected_row) {
                            dst_rect.x -= 2;
                            dst_rect.y -= 2;
                            game_window->DrawImage(ImageID::number_selected, &src_rect, &dst_rect, active_alpha);
                        }
                        else
                            game_window->DrawImage(ImageID::number, &src_rect, &dst_rect, active_alpha);
                    }
                }
                break;
            case OPTION_ITEM_MODE:
                for(int j=0;j<3;j++) {
                    SDL_Rect src_rect = {0,j*48,200,48};
                    SDL_Rect dst_rect = {200*j+x+210,y,200,48};
                    
                    if(i==selected_row) {
                        dst_rect.x -= 2;
                        dst_rect.y -= 2;
                    }
                    if(j==static_cast<int>(game_window->getFullScreenMode())) {
                        dst_rect.x -= 2;
                        dst_rect.y -= 2;
                        game_window->DrawImage(ImageID::option_selected_fullscreen_mode, &src_rect, &dst_rect, active_alpha);
                    }
                    else
                        game_window->DrawImage(ImageID::option_fullscreen_mode, &src_rect, &dst_rect, active_alpha);
                }
                break;
        }
    }

    if(game_window->getIsButtonPressed(Buttons::Bomb) || game_window->getIsButtonPressed(Buttons::Pause))
        this->selected_row = OPTION_ITEM_QUIT;

    if(game_window->getIsButtonPressed(Buttons::Shot)) {
        switch(selected_row) {
            case OPTION_ITEM_RESET:
                game_window->config.Reset();
                break;
            case OPTION_ITEM_QUIT:
                return ScreenID::Title;
            default:
                break;
        }
    }

    if(game_window->getIsButtonPressed(Buttons::Left)) {
        switch (this->selected_row)
        {
            case OPTION_ITEM_PLAYER:
                game_window->config.setPlayerCount(game_window->config.getPlayerCount() - 1);
                break;
            case OPTION_ITEM_BOMB:
                game_window->config.setBombCount(game_window->config.getBombCount() - 1);
                break;
            case OPTION_ITEM_BGM_VOLUME:
                game_window->config.setBGMVolume(game_window->config.getBGMVolume() - 1);
                break;
            case OPTION_ITEM_SE_VOLUME:
                game_window->config.setSEVolume(game_window->config.getSEVolume() - 1);
                break;
            case OPTION_ITEM_MODE:
                switch(game_window->getFullScreenMode()) {
                    case FullScreenMODE::Windowed:
                        game_window->setFullScreenMode(FullScreenMODE::BorderLess);
                        break;
                    case FullScreenMODE::Fullscreen:
                        game_window->setFullScreenMode(FullScreenMODE::Windowed);
                        break;
                    default:
                        game_window->setFullScreenMode(FullScreenMODE::Fullscreen);
                        break;
                }
                break;
            default:
                break;
        }
    }
    else if(game_window->getIsButtonPressed(Buttons::Right)) {
        switch (this->selected_row)
        {
            case OPTION_ITEM_PLAYER:
                game_window->config.setPlayerCount(game_window->config.getPlayerCount() + 1);
                break;
            case OPTION_ITEM_BOMB:
                game_window->config.setBombCount(game_window->config.getBombCount() + 1);
                break;
            case OPTION_ITEM_BGM_VOLUME:
                game_window->config.setBGMVolume(game_window->config.getBGMVolume() + 1);
                break;
            case OPTION_ITEM_SE_VOLUME:
                game_window->config.setSEVolume(game_window->config.getSEVolume() + 1);
                break;
            case OPTION_ITEM_MODE:
                switch(game_window->getFullScreenMode()) {
                    case FullScreenMODE::Windowed:
                        game_window->setFullScreenMode(FullScreenMODE::Fullscreen);
                        break;
                    case FullScreenMODE::Fullscreen:
                        game_window->setFullScreenMode(FullScreenMODE::BorderLess);
                        break;
                    default:
                        game_window->setFullScreenMode(FullScreenMODE::Windowed);
                        break;
                }
                break;
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