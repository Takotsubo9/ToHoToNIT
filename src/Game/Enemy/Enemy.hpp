#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "EnemyBarrage.hpp"

class EnemyBarrage;

class Enemy
{
private:
    EnemyBarrage * ebarrage;
    int enemyID;
    int maxHP;
    int HP;
    float x;
    float y;
    int enemyHitBoxRadius;    //当たり判定半径
    float defense;    //敵の防御率(0-1の間)
protected:
    void setMaxHP( int maxHP ){ this->maxHP = maxHP; }
    void setEnemyHitBoxRadius( int enemyHitBoxRadius ){ this->enemyHitBoxRadius = enemyHitBoxRadius; }
public:
    Enemy( void );
    Enemy( int enemyID );
    Enemy( int enemyID, float x, float y );    //使うんだったら使って
    virtual ~Enemy();
    void setEnemyBarrage( EnemyBarrage * ebarrage ){ this->ebarrage = ebarrage; }
    EnemyBarrage * getEnemyBarrage( void ){ return ebarrage; }
    void setEnemyID( int enemyID ){ this->enemyID = enemyID; }
    int getEnemyID( void ){ return enemyID; }
    int getMaxHP( void ){ return maxHP; }
    void setHP( int HP ){ this->HP = HP; }
    int getHP( void ){ return HP; }
    void setX( float x ){ this->x = x; }
    float getX( void ){ return x; }
    void setY( float y ){ this->y = y; }
    float getY( void ){ return y; }
    int getEnemyHitBoxRadius( void ){ return enemyHitBoxRadius; }
    void setDefense( float defense ){ this->defense = defense; }
    float getDefense( void ){ return defense; }

    void damageHP( int damagedHP );
    void restHP( int restedHP );
};

#endif /* _ENEMY_H_ */