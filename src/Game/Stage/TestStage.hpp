#ifndef _TEST_STAGE_H_
#define _TEST_STAGE_H_

#include "Stage.hpp"

class TestStage : public Stage {
public:
    TestStage(Player * player) : Stage(player) {

    }

    virtual ~TestStage() {

    }
    void Update(GameWindow* game_window);
    void Draw(GameWindow* game_window);
};

#endif /* _TEST_STAGE_H_ */