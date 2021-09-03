#ifndef _DPLAYER_H_
#define _DPLAYER_H_

#include "Player.hpp"

class dPlayer {
private:
    Player* player;
    float x;
    float y;
public:
    dPlayer() {
        this->x = 100;
        this->y = 100;
    }
    virtual ~dPlayer() {

    }
    void setPlayer(Player * player) {
        this->player = player;
    }
    void move(float x, float y, bool isSlow) {
        float speed = isSlow ? this->player->getCharacter()->getLowFSpeed() : this->player->getCharacter()->getHighFSpeed();
        this->x += x * 1.5 * speed;
        this->y += y * 1.5 * speed;
    }
    void draw() {

    }
};

#endif /* _DPLAYER_H_ */