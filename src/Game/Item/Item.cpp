#include "Item.hpp"
#include "../../GameWindow.hpp"
#include <cmath>

Item::Item(ItemID item_id, float x, float y, float target_x, float target_y, float inclease, float speed) {
    this->item_id = item_id;
    this->x = x;
    this->y = y;
    this->target_x = target_x;
    this->target_y = target_y;
    //target_x/yにspeedの速度で向かう
    if((target_x > 0 && target_y > 0) && (x != target_x || y != target_y)) {
        this->to_target = true;
    } else {
        this->to_target = false;
    }
    this->inclease = inclease;
    this->speed = speed;
}

void Item::Update() {
    if (this->to_target) {
        float rad = std::atan2(target_y - y, target_x - x);
        x += std::min(std::cos(rad) * this->speed, target_x - x);
        y += std::min(std::sin(rad) * this->speed, target_y - y);
        if(target_y - y == 0 && target_x - x == 0)
            this->to_target = false;
    } else {
        this->y += this->inclease;
        this->inclease = std::min(this->inclease + 0.1, 4.0);
    }
}

void Item::Draw(GameWindow* game_window) {
    SDL_Rect src_rect = {static_cast<int>(this->item_id) * 24, 0, 24, 24};
    SDL_Rect dst_rect = {static_cast<int>(this->x), static_cast<int>(this->y), 24, 24};
    game_window->DrawImage(ImageID::game_item, &src_rect, &dst_rect, RefPoint::Center);
    if(this->y < 24) {
        src_rect.y = 24;
        dst_rect.y = 24;
        game_window->DrawImage(ImageID::game_item, &src_rect, &dst_rect, RefPoint::Top);
    }
}

void Item::Effect(dPlayer* dplayer) {
    switch(this->item_id) {
        case ItemID::power:
            dplayer->getPlayer()->setPower(dplayer->getPlayer()->getPower() + 1);
            break;
        case ItemID::big_power:
            dplayer->getPlayer()->setPower(dplayer->getPlayer()->getPower() + 8);
            break;
        case ItemID::point:
            dplayer->getPlayer()->incleasePoint();
            break;
        case ItemID::bomb:
            dplayer->getPlayer()->setBombCount(dplayer->getPlayer()->getBombCount() + 1);
            break;
        case ItemID::one_up:
            dplayer->getPlayer()->setPlayerCount(dplayer->getPlayer()->getPlayerCount() + 1);
            break;
        case ItemID::full_power:
            dplayer->getPlayer()->setPower(128);
            break;
        case ItemID::star:
            //計算方法がわからないので保留
            break;
    }
}