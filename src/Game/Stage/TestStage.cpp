#include "TestStage.hpp"

void TestStage::Draw(GameWindow* game_window) {
    this->dplayer.move(game_window);
    this->dplayer.Draw(game_window);
}