#ifndef _PLAYERBARRAGE_H_
#define _PLAYERBARRAGE_H_

#include<vector>
#include"PlayerBullet.hpp"
#include"../Enemy/Enemy.hpp"

class dPlayer;

class PlayerBarrage
{
private:
    dPlayer * dplayer;
    Enemy * enemy;
    std::vector<PlayerBullet *> pbullets;
public:
    PlayerBarrage( void );
    virtual ~PlayerBarrage();

    void setdPlayer( dPlayer * dplayer ){ this->dplayer = dplayer; }
    dPlayer * getdPlayer( void ){ return dplayer; }
    void setEnemy( Enemy * enemy ){ this->enemy = enemy; }
    Enemy * getEnemy( void ){ return enemy; }


    //弾クラスをインスタンス化する方法がまだ定まらないので後に追記
};

#endif /* _PLAYERBARRAGE_H_ */