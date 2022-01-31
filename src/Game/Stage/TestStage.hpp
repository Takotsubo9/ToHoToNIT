#ifndef _TEST_STAGE_H_
#define _TEST_STAGE_H_

#include "Stage.hpp"

class TestStage : public Stage {
public:
    TestStage(Player * player) : Stage(player) {

    }

    virtual ~TestStage() {

    }

    void Draw(GameWindow * game_window) {
        float x,y;
        game_window->getMovement(&x, &y);
        this->dplayer.move(x, y, game_window->getIsButtonDown(Buttons::Slow));
        this->dplayer.Draw(game_window);
    }
};

#endif /* _TEST_STAGE_H_ */