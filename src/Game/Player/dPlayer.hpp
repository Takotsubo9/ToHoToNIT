#ifndef _DPLAYER_H_
#define _DPLAYER_H_

#ifdef __ANDROID__
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

#include "../../GameWindow.hpp"
#include "Player.hpp"

class PlayerBarrage;

class dPlayer {
private:
    Player* player;
    PlayerBarrage * pbarrage;
    float x;
    float y;
    const int hitBoxRadius = 5;    //キャラの当たり判定半径(pxl) 全キャラで不変
public:
    dPlayer();
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
    int getHitBoxRadius( void ){ return hitBoxRadius; }

    void move(float x, float y, bool isSlow);
    void Draw(GameWindow * game_window);
};

#endif /* _DPLAYER_H_ */