#include "TestStage.hpp"

TestStage::TestStage(Player * player) : Stage(player) {
    
}

TestStage::~TestStage() {

}

void TestStage::Update(GameWindow* game_window) {
    for (auto item = this->item_list.begin(); item != this->item_list.end();) {
        item->Update();
        //画面外削除
        if(item->getY() > 720) {
            item = this->item_list.erase(item);
        } else {
            item++;
        }
    }

    this->dplayer.Update(game_window);
}

void TestStage::Draw(GameWindow* game_window) {
    for (auto& item : this->item_list) {
        item.Draw(game_window);
    }

    this->dplayer.Draw(game_window);
}
