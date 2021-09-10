#ifndef _DPLAYER_H_
#define _DPLAYER_H_

#include "Player.hpp"

class PlayerBarrage;

class dPlayer {
private:
    Player* player;
    PlayerBarrage * pbarrage;
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
    Player * getPlayer( void ) {
        return player;
    }
    void setPlayerBarrage( PlayerBarrage * pbarrage ) {
        this->pbarrage = pbarrage;
    }
    PlayerBarrage * getPlayerBarrage( void ) {
        return pbarrage;
    }
    void setX( float x ){ this->x = x; }
    float getX( void ){ return x; }
    void setY( float y ){ this->y = y; }
    float getY( void ){ return y; }

    void move(float x, float y, bool isSlow) {
        float speed = isSlow ? this->player->getCharacter()->getLowFSpeed() : this->player->getCharacter()->getHighFSpeed();
        this->x += x * 1.5 * speed;
        this->y += y * 1.5 * speed;
    }
    void draw() {

    }
};

#endif /* _DPLAYER_H_ */