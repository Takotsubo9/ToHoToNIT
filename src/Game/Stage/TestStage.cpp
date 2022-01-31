#include "TestStage.hpp"

void TestStage::Draw(GameWindow* game_window) {
    float x,y;
    game_window->getMovement(&x, &y);
    this->dplayer.move(x, y, game_window->getIsButtonDown(Buttons::Slow));
    this->dplayer.Draw(game_window);
}