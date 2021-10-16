#ifndef _ENEMYBARRAGE_H_
#define _ENEMYBARRAGE_H_

#include<vector>
#include"../Bullet/EnemyBullet.hpp"
#include"../Bullet/BigEnemyBullet.hpp"
#include"../../Player/dPlayer.hpp"

class Enemy;

class EnemyBarrage
{
private:
    int barrageID;
    Enemy * enemy;
    dPlayer * dplayer;
    std::vector<EnemyBullet *> ebullets;
public:
    EnemyBarrage( void );
    EnemyBarrage( Enemy * enemy, int barrageID );
    virtual ~EnemyBarrage();

    void setBarrageID( int barrageID ){ this->barrageID = barrageID; }
    int getBarrageID( void ){ return barrageID; }
    void setEnemy( Enemy * enemy ){ this->enemy = enemy; }
    Enemy * getEnemy( void ){ return enemy; }
    void setdPlayer( dPlayer * dplayer ){ this->dplayer = dplayer; }
    dPlayer * getdPlayer( void ){ return dplayer; }

    void setEBullet( EnemyBullet * ebullet ){ this->ebullets.push_back( ebullet ); }
    EnemyBullet * getEBullet( int num ){ return ebullets[num]; }
    int getEBulletSize( void ){ return ebullets.size(); }
};

#endif /* _ENEMYBARRAGE_H_ */