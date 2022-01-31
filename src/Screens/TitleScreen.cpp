#include "TitleScreen.hpp"
#include "../GameWindow.hpp"
#include "../Const/RefPoint.hpp"
#include <SDL2/SDL.h>

TitleScreen::TitleScreen() {
    this->frames = 0;
    this->selected_row_title = TITLE_ITEM_START;
    this->selected_row_option = OPTION_ITEM_COUNT;
    this->selected_row_keyconfig = KEYCONFIG_ITEM_SHOT;
    this->phase = TitleScreenPhase::Title;
}

ScreenID TitleScreen::Render(GameWindow* game_window) {

    SDL_Rect bg_src_rect = {0,0,2400,1800};
    SDL_Rect bg_rect = {0,0,960,720};
    game_window->DrawImage(ImageID::title_background, &bg_src_rect, &bg_rect, RefPoint::LeftTop);

    if(this->phase == TitleScreenPhase::Title) {

        SDL_Rect logo_src_rect[5] = {
            {0, 0, 108, 108},
            {108, 0, 108, 108},
            {216, 0, 108, 108},
            {0, 108, 108, 108},
            {108, 108, 108, 108},
        };
        SDL_Rect logo_src_eng_rect[2] = {
            {0, 216, 324, 54},
            {0, 270, 324, 54},
        };

        for (int i = 0; i < 5; i++) {
            SDL_Rect logo_dst_rect = {420 + i * 108, i * 30, 108, 108};
            double angle = i == 2 ? -20 : 0;
            game_window->DrawImage(ImageID::title_logo, &logo_src_rect[i], &logo_dst_rect, RefPoint::LeftTop, 0xff, angle);
        }
        for (int i = 0; i < 2; i++) {
            SDL_Rect logo_dst_rect = {480 + i * 200, 110 - i * 72, 324, 54};
            game_window->DrawImage(ImageID::title_logo, &logo_src_eng_rect[i], &logo_dst_rect, RefPoint::LeftTop, 0xff, -20);
        }

        for(int i=0; i<TITLE_ITEM_COUNT; i++) {
            SDL_Rect srcrect = {0,48*i,220,48};
            SDL_Rect dstrect = {667-(i*10),244+(i*45),220,48};
            if(i == selected_row_title) {
                dstrect.x -= 2;
                dstrect.y -= 2;
                game_window->DrawImage(ImageID::title_selected_items, &srcrect, &dstrect, RefPoint::LeftTop);
            } else {
                game_window->DrawImage(ImageID::title_items, &srcrect, &dstrect, RefPoint::LeftTop, 0xC0);
            }
        }

        //項目が選択された後の1フレームだけ描画されないということを防ぐために、すべてを描画した後に、キー入力をやるべきです。
        if(game_window->getIsButtonPressed(Buttons::Bomb) || game_window->getIsButtonPressed(Buttons::Pause))
            this->selected_row_title = TITLE_ITEM_QUIT;

        if(game_window->getIsButtonPressed(Buttons::Shot)) {
            switch(selected_row_title) {
                case TITLE_ITEM_START:
                    return ScreenID::Game;
                case TITLE_ITEM_OPTION:
                    this->phase = TitleScreenPhase::Option;
                    this->selected_row_option = OPTION_ITEM_PLAYER;
                    break;
                case TITLE_ITEM_MUSIC_ROOM:
                    return ScreenID::MusicRoom;
                case TITLE_ITEM_QUIT:
                    game_window->Quit();
                    break;
                default:
                    break;
            }
        }

        if(game_window->getIsButtonPressed(Buttons::Down))
            selected_row_title = (selected_row_title + 1 + TITLE_ITEM_COUNT) % TITLE_ITEM_COUNT;
        if(game_window->getIsButtonPressed(Buttons::Up))
            selected_row_title = (selected_row_title - 1 + TITLE_ITEM_COUNT) % TITLE_ITEM_COUNT;

    } else if(this->phase == TitleScreenPhase::Option) {
        
        for(int i=0; i<OPTION_ITEM_COUNT; i++) {
            const int x = 100;
            const int y = 100+(i*45);
            SDL_Rect srcrect = {0,48*i,180,48};
            SDL_Rect dstrect = {100,y,180,48};
            const int active_alpha = (i == selected_row_option) ? 0xFF : 0xC0;
            if(i == selected_row_option) {
                dstrect.x -= 2;
                dstrect.y -= 2;
                game_window->DrawImage(ImageID::option_selected_items, &srcrect, &dstrect, RefPoint::LeftTop);
            } else {
                game_window->DrawImage(ImageID::option_items, &srcrect, &dstrect, RefPoint::LeftTop, 0xC0);
            }
            
            switch(i) {
                case OPTION_ITEM_PLAYER:
                    for(int j=0;j<5;j++) {
                        SDL_Rect src_rect = {(j+1)*32,0,32,48};
                        SDL_Rect dst_rect = {x+200+j*32,y,32,48};
                        if(i==selected_row_option) {
                            dst_rect.x -= 2;
                            dst_rect.y -= 2;
                        }
                        if(j==game_window->config.getPlayerCount()-1) {
                            dst_rect.x -= 2;
                            dst_rect.y -= 2;
                            game_window->DrawImage(ImageID::number_selected, &src_rect, &dst_rect, RefPoint::LeftTop, active_alpha);
                        }
                        else
                            game_window->DrawImage(ImageID::number, &src_rect, &dst_rect, RefPoint::LeftTop, active_alpha);
                    }
                    break;
                case OPTION_ITEM_BOMB:
                    for(int j=0;j<4;j++) {
                        SDL_Rect src_rect = {j*32,0,32,48};
                        SDL_Rect dst_rect = {x+200+j*32,y,32,48};
                        if(i==selected_row_option) {
                            dst_rect.x -= 2;
                            dst_rect.y -= 2;
                        }
                        if(j==game_window->config.getBombCount()) {
                            dst_rect.x -= 2;
                            dst_rect.y -= 2;
                            game_window->DrawImage(ImageID::number_selected, &src_rect, &dst_rect, RefPoint::LeftTop, active_alpha);
                        }
                        else
                            game_window->DrawImage(ImageID::number, &src_rect, &dst_rect, RefPoint::LeftTop, active_alpha);
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
                            if(i==selected_row_option) {
                                dst_rect.x -= 2;
                                dst_rect.y -= 2;
                                game_window->DrawImage(ImageID::number_selected, &src_rect, &dst_rect, RefPoint::LeftTop, active_alpha);
                            }
                            else
                                game_window->DrawImage(ImageID::number, &src_rect, &dst_rect, RefPoint::LeftTop, active_alpha);
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
                            if(i==selected_row_option) {
                                dst_rect.x -= 2;
                                dst_rect.y -= 2;
                                game_window->DrawImage(ImageID::number_selected, &src_rect, &dst_rect, RefPoint::LeftTop, active_alpha);
                            }
                            else
                                game_window->DrawImage(ImageID::number, &src_rect, &dst_rect, RefPoint::LeftTop, active_alpha);
                        }
                    }
                    break;
                case OPTION_ITEM_MODE:
                    for(int j=0;j<3;j++) {
                        SDL_Rect src_rect = {0,j*48,200,48};
                        SDL_Rect dst_rect = {200*j+x+210,y,200,48};
                        
                        if(i==selected_row_option) {
                            dst_rect.x -= 2;
                            dst_rect.y -= 2;
                        }
                        if(j==static_cast<int>(game_window->getFullScreenMode())) {
                            dst_rect.x -= 2;
                            dst_rect.y -= 2;
                            game_window->DrawImage(ImageID::option_selected_fullscreen_mode, &src_rect, &dst_rect, RefPoint::LeftTop, active_alpha);
                        }
                        else
                            game_window->DrawImage(ImageID::option_fullscreen_mode, &src_rect, &dst_rect, RefPoint::LeftTop, active_alpha);
                    }
                    break;
            }
        }

        if(game_window->getIsButtonPressed(Buttons::Left)) {
            switch (this->selected_row_option)
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
            switch (this->selected_row_option)
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
        
        if(game_window->getIsButtonPressed(Buttons::Bomb) || game_window->getIsButtonPressed(Buttons::Pause))
            this->selected_row_option = OPTION_ITEM_QUIT;

        if(game_window->getIsButtonPressed(Buttons::Shot)) {
            switch(selected_row_option) {
                case OPTION_ITEM_RESET:
                    game_window->config.Reset();
                    break;
                case OPTION_ITEM_KEYCONFIG:
                    this->phase = TitleScreenPhase::KeyConfig;
                    game_window->setJoystickButtonEnable(false);
                    this->selected_row_keyconfig = KEYCONFIG_ITEM_SHOT;
                    break;
                case OPTION_ITEM_QUIT:
                    this->phase = TitleScreenPhase::Title;
                    break;
                default:
                    break;
            }
        }

        if(game_window->getIsButtonPressed(Buttons::Down))
            selected_row_option = (selected_row_option + 1 + OPTION_ITEM_COUNT) % OPTION_ITEM_COUNT;
        if(game_window->getIsButtonPressed(Buttons::Up))
            selected_row_option = (selected_row_option - 1 + OPTION_ITEM_COUNT) % OPTION_ITEM_COUNT;


    } else if(this->phase == TitleScreenPhase::KeyConfig) {

        for(int i=0;i<KEYCONFIG_ITEM_COUNT;i++) {

            SDL_Rect src_rect = {0,i*48,230,48};
            SDL_Rect dst_rect = {100, 100 + i*48,230,48};
            if(i==this->selected_row_keyconfig) {
                dst_rect.x -= 2;
                dst_rect.y -= 2;
                game_window->DrawImage(ImageID::keyconfig_selected_items, &src_rect, &dst_rect, RefPoint::LeftTop);
            }
            else
                game_window->DrawImage(ImageID::keyconfig_items, &src_rect, &dst_rect, RefPoint::LeftTop);

                
            if (i!=KEYCONFIG_ITEM_QUIT && i!=KEYCONFIG_ITEM_RESET) {
                if(game_window->config.joystick_buttons_map[static_cast<Buttons>(i)]!=-1) {
                    src_rect.y = KEYCONFIG_ITEM_COUNT*48;
                    dst_rect.x = dst_rect.x + 300;

                    if(i==this->selected_row_keyconfig) {
                        game_window->DrawImage(ImageID::keyconfig_selected_items, &src_rect, &dst_rect, RefPoint::LeftTop);
                    } else {
                        game_window->DrawImage(ImageID::keyconfig_items, &src_rect, &dst_rect, RefPoint::LeftTop);
                    }

                    dst_rect.x = dst_rect.x + 200;



                        for(int j=0;j<2;j++) {
                            int num = ((int)(game_window->config.joystick_buttons_map[static_cast<Buttons>(i)] / pow(10, j)) % 10);
                            src_rect = {32*num,0,32,48};
                            dst_rect = {dst_rect.x-32*j,dst_rect.y,32,48};
                            if(i==this->selected_row_keyconfig) {    
                                game_window->DrawImage(ImageID::number_selected, &src_rect, &dst_rect, RefPoint::LeftTop);
                            } else {
                                game_window->DrawImage(ImageID::number, &src_rect, &dst_rect, RefPoint::LeftTop);
                            }
                        }
                }
            }
        }

        if(this->selected_row_keyconfig!=KEYCONFIG_ITEM_QUIT && this->selected_row_keyconfig!=KEYCONFIG_ITEM_RESET) {
            if(game_window->getJoystickButtonEvent()->size() != 0) {
                int button_num = (*game_window->getJoystickButtonEvent())[0];
                game_window->config.joystick_buttons_map[static_cast<Buttons>(this->selected_row_keyconfig)] = button_num;
                for(int j=0;j<KEYCONFIG_ITEM_RESET;j++) {//変なforになってしまい、申し訳ない。
                    if(j!=this->selected_row_keyconfig) {
                        if(game_window->config.joystick_buttons_map[static_cast<Buttons>(j)]==button_num) {
                            game_window->config.joystick_buttons_map[static_cast<Buttons>(j)] = UNDEFINED_BUTTONS;
                        }
                    }
                }
            }
        }


        if(game_window->getIsButtonPressed(Buttons::Bomb) || game_window->getIsButtonPressed(Buttons::Pause))
            this->selected_row_keyconfig = KEYCONFIG_ITEM_QUIT;

        if(game_window->getIsButtonPressed(Buttons::Shot)) {
            switch(selected_row_keyconfig) {
                case KEYCONFIG_ITEM_RESET:
                    game_window->config.KeyConfigReset();
                    break;
                case KEYCONFIG_ITEM_QUIT:
                    this->phase = TitleScreenPhase::Option;
                    game_window->setJoystickButtonEnable(true);
                    break;
                default:
                    break;
            }
        }

        if(game_window->getIsButtonPressed(Buttons::Down))
            selected_row_keyconfig = (selected_row_keyconfig + 1 + KEYCONFIG_ITEM_COUNT) % KEYCONFIG_ITEM_COUNT;
        if(game_window->getIsButtonPressed(Buttons::Up))
            selected_row_keyconfig = (selected_row_keyconfig - 1 + KEYCONFIG_ITEM_COUNT) % KEYCONFIG_ITEM_COUNT;


    }


    return ScreenID::Title;
}
