#ifndef _ENEMYBARRAGE_H_
#define _ENEMYBARRAGE_H_

#include<vector>
#include"../Bullet/EnemyBullet.hpp"
#include"../../Player/dPlayer.hpp"

class Enemy;

class EnemyBarrage
{
private:
    Enemy * enemy;
    dPlayer * dplayer;
    std::vector<EnemyBullet *> ebullets;
public:
    EnemyBarrage( void );
    virtual ~EnemyBarrage();

    void setEnemy( Enemy * enemy ){ this->enemy = enemy; }
    Enemy * getEnemy( void ){ return enemy; }
    void setdPlayer( dPlayer * dplayer ){ this->dplayer = dplayer; }
    dPlayer * getdPlayer( void ){ return dplayer; }

    //弾クラスをインスタンス化する方法がまだ定まらないので後に追記
};

#endif /* _ENEMYBARRAGE_H_ */