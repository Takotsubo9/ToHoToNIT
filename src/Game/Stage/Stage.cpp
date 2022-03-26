#include "Stage.hpp"

Stage::Stage(Player * player) {
    dplayer.setPlayer(player);
}

void Stage::Judge(GameWindow* game_window) {
    //もろもろの当たり判定を判定する関数
    for(auto item = this->item_list.begin(); item != this->item_list.end();) {
        if(std::abs(dplayer.getX() - item->getX()) <= 20 && std::abs(dplayer.getY() - item->getY()) <= 20) {
            item->Effect(&dplayer);
            item = this->item_list.erase(item);
            game_window->PlaySE(SoundEffectID::get_item);
        } else {
            item++;
        }
    }
}