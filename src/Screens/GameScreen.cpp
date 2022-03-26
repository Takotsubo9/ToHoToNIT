#ifdef __ANDROID__
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

#include "GameScreen.hpp"
#include "../GameWindow.hpp"
#include <cmath>
#include <cstdio>

GameScreen::GameScreen(Config& config) {
    this->frames = 0;
    this->paused = false;
    this->pause_counter = 0;
    this->selected_row_pause = PAUSE_ITEM_RESUME_TO_GAME;
    this->player = new Player(config);
    this->stage = new TestStage(this->player);
}

ScreenID GameScreen::Render(GameWindow *game_window) {

    //ポーズのアニメーション用にカウンターをいろいろ
    if(this->paused) 
        pause_counter = std::min(pause_counter + 1, PAUSE_COUNTER_MAX);
    else
        pause_counter = std::max(pause_counter - 1, 0);

    SDL_Rect all_rect = {0,0,960,720};

    //ポーズアニメーションのカウンターが0の際のみ、ステージの描画
    //(暫定の実装)
    if (pause_counter == 0) {
        this->stage->Update(game_window);
        this->stage->Judge(game_window);
    }
    this->stage->Draw(game_window);

    //ポーズアニメーションのカウンターが0じゃない際にポーズ用のやつを描画
    if(pause_counter != 0) {
        game_window->FillRect(0x00, 0x40, 0x80, static_cast<uint8_t>(0x70 * (static_cast<double>(pause_counter) / PAUSE_COUNTER_MAX)), &all_rect);
        for(int i = 0; i < PAUSE_ITEM_COUNT + 1; i++) {
            SDL_Rect src = {0,48*i,220,48};
            SDL_Rect dst = {337,313+48*i,220, static_cast<int>(48 * (static_cast<double>(pause_counter) / PAUSE_COUNTER_MAX))};
            uint8_t alpha = 0xff;
            if(i >= 1 && (i - 1) != selected_row_pause)
                alpha = 0x80;
            else {
                dst.w *= 1.1;
                dst.h *= 1.1;
            }
            game_window->DrawImage(ImageID::game_pause_menu, &src, &dst, RefPoint::Center, alpha);
        }
    }

    game_window->DrawImage(ImageID::game_frame, &all_rect, &all_rect);

    SDL_Rect src_rect = {0, 0, static_cast<int>(this->player->getPower() * 1.5), 32};
    SDL_Rect dst_rect = {740, 294, src_rect.w, src_rect.h};
    game_window->DrawImage(ImageID::game_power_gauge, &src_rect, &dst_rect);

    src_rect.x = 0;
    dst_rect.x = 630;
    //文字系widthは点以外130
    src_rect.w = 130;
    dst_rect.w = 130;
    src_rect.h = 36;
    dst_rect.h = 36;
    for(int i = 0; i < 7; i++) {
        src_rect.y = i * 36;
        dst_rect.y = i * 48 + 50;
        if(i >= 2)
            dst_rect.y += 25;
        if(i >= 4)
            dst_rect.y += 25;
        if(i == 6) {
            //点は40
            src_rect.w = 40;
            dst_rect.w = 40;
        }
        game_window->DrawImage(ImageID::game_status, &src_rect, &dst_rect);
    }

    //星は45x45
    src_rect.w = 45;
    dst_rect.w = 45;

    //Player星の場所
    src_rect.x = 40;
    dst_rect.y = 170;
    for(unsigned int i = 0; i < this->player->getPlayerCount(); i++) {
        dst_rect.x = i * 30 + 740;
        game_window->DrawImage(ImageID::game_status, &src_rect, &dst_rect);
    }

    //Bomb星の場所
    src_rect.x = 85;
    dst_rect.y += 48;
    for(unsigned int i = 0; i < this->player->getBombCount(); i++) {
        dst_rect.x = i * 30 + 740;
        game_window->DrawImage(ImageID::game_status, &src_rect, &dst_rect);
    }

    char buf[10];
    src_rect.y = 0;
    src_rect.w = 32;
    src_rect.h = 48;
    dst_rect.w = 29; //32*0.9
    dst_rect.h = 43; //48*0.9

    //cの書き方って感じの書き方ですが、許して
    //最高得点を取得する関数がまだ存在しないので、0
    sprintf(buf, "%09d", 0);
    dst_rect.y = 54;
    for(int i = 0; i < 9; i++) {
        src_rect.x = (buf[i] - '0') * 32;
        dst_rect.x = i * 24 + 740;
        game_window->DrawImage(ImageID::number, &src_rect, &dst_rect);
    }

    //得点
    sprintf(buf, "%09ld", this->player->getAllPoint());
    dst_rect.y = 100;
    for(int i = 0; i < 9; i++) {
        src_rect.x = (buf[i] - '0') * 32;
        dst_rect.x = i * 24 + 740;
        game_window->DrawImage(ImageID::number, &src_rect, &dst_rect);
    }

    sprintf(buf, "%d", this->player->getGraze());
    dst_rect.y = 344;
    char* ch = buf;
    while(*ch) {
        src_rect.x = (*ch - '0') * 32;
        dst_rect.x = (ch - buf) * 24 + 740;
        game_window->DrawImage(ImageID::number, &src_rect, &dst_rect);
        ch++;
    }

    sprintf(buf, "%d", this->player->getPoint());
    dst_rect.y = 390;
    ch = buf;
    while(*ch) {
        src_rect.x = (*ch - '0') * 32;
        dst_rect.x = (ch - buf) * 24 + 740;
        game_window->DrawImage(ImageID::number, &src_rect, &dst_rect);
        ch++;
    }

    if(this->player->getPower() != 128) {
        sprintf(buf, "%d", this->player->getPower());
        dst_rect.y = 296;
        ch = buf;
        while(*ch) {
            src_rect.x = (*ch - '0') * 32;
            dst_rect.x = (ch - buf) * 24 + 740;
            game_window->DrawImage(ImageID::number, &src_rect, &dst_rect);
            ch++;
        }
    } else {
        src_rect = {0,0,76,32};
        dst_rect = {740,296,76,32};
        game_window->DrawImage(ImageID::game_power_max_text, &src_rect, &dst_rect);
    }

    if (game_window->getIsButtonPressed(Buttons::Pause)) {
        this->paused = !this->paused;
        if (this->paused)
            selected_row_pause = PAUSE_ITEM_RESUME_TO_GAME;
    }

    if(this->paused) {
        if(game_window->getIsButtonPressed(Buttons::Down)) {
            selected_row_pause = (selected_row_pause + 1) % PAUSE_ITEM_COUNT;
        }
        if(game_window->getIsButtonPressed(Buttons::Up)) {
            selected_row_pause = (selected_row_pause - 1 + PAUSE_ITEM_COUNT) % PAUSE_ITEM_COUNT;
        }
        if(game_window->getIsButtonPressed(Buttons::Shot)) {
            switch (selected_row_pause)
            {
                case PAUSE_ITEM_RESUME_TO_GAME:
                    this->paused = false;
                    break;
                case PAUSE_ITEM_RETURN_TO_TITLE:
                    return ScreenID::Title;
            }
        }
    }

    return ScreenID::Game;
}