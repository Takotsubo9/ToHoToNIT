#include "dPlayer.hpp"

dPlayer::dPlayer() {
    this->x = 338;
    this->y = 600;
    this->move_frame_count = 0;
    this->frame_count = 0;
    this->flip = SDL_FLIP_NONE;
}

dPlayer::~dPlayer() {
    
}

void dPlayer::Update(GameWindow* game_window) {
    float x, y;
    game_window->getMovement(&x, &y);
    float speed = game_window->getIsButtonDown(Buttons::Slow) ? this->player->getCharacter()->getLowFSpeed() : this->player->getCharacter()->getHighFSpeed();
    this->x += x * 1.5 * speed;
    this->y += y * 1.5 * speed;
    this->x = std::max(std::min(static_cast<double>(this->x), (32 + 385) * 1.5), 32 * 1.5);
    this->y = std::max(std::min(static_cast<double>(this->y), (16 + 450) * 1.5), 16 * 1.5);
    frame_count = (frame_count + 1) % 20;
    if(x < 0) {
        move_frame_count = std::max((move_frame_count - 1), -7);
    } else if(x > 0) {
        move_frame_count = std::min((move_frame_count + 1), 7);
    } else if(move_frame_count > 0){
        move_frame_count = std::max((move_frame_count - 1), 0);
    } else if(move_frame_count < 0) {
        move_frame_count = std::min((move_frame_count + 1), 0);
    }
}

void dPlayer::Draw(GameWindow* game_window) {
    SDL_Rect player_rect = {static_cast<int>(this->x), static_cast<int>(this->y), 48, 67};
    SDL_Rect src_rect = {(frame_count / 5) * 48,0,48,67};
    if(move_frame_count < 0) {
        src_rect.y = 67;
        src_rect.x = 48 * (-move_frame_count / 2);
        flip = SDL_FLIP_NONE;
    } else if(move_frame_count > 0) {
        src_rect.y = 67;
        src_rect.x = 48 * (move_frame_count / 2);
        flip = SDL_FLIP_HORIZONTAL;
    }
    game_window->DrawImage(this->player->getCharacter()->getImageID(), &src_rect, &player_rect, RefPoint::Center, 255U, 0.0, flip);
}