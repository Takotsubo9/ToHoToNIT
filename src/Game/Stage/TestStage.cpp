#include "TestStage.hpp"

void TestStage::Update(GameWindow* game_window) {
    this->dplayer.Update(game_window);
}

void TestStage::Draw(GameWindow* game_window) {
    this->dplayer.Draw(game_window);
}