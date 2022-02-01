#include "dPlayer.hpp"

dPlayer::dPlayer() {
    this->x = 338;
    this->y = 600;
}

void dPlayer::move(float x, float y, bool isSlow) {
    float speed = isSlow ? this->player->getCharacter()->getLowFSpeed() : this->player->getCharacter()->getHighFSpeed();
    this->x += x * 1.5 * speed;
    this->y += y * 1.5 * speed;
    this->x = std::max(std::min(static_cast<double>(this->x), (32 + 385) * 1.5), 32 * 1.5);
    this->y = std::max(std::min(static_cast<double>(this->y), (16 + 450) * 1.5), 16 * 1.5);
}

void dPlayer::Draw(GameWindow* game_window) {
    SDL_Rect player_rect = {static_cast<int>(this->x), static_cast<int>(this->y), 30, 40};
    player_rect.x -= (player_rect.w / 2);
    player_rect.y -= (player_rect.h / 2);
    game_window->FillRect(0xff, 0xff, 0xff, 0xff, &player_rect);
}